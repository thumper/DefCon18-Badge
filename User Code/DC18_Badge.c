/******************************************************************************
*
* DEFCON 18 BADGE
*
* Filename:		  DC18_Badge.c
* Author:		    Joe Grand (Kingpin)
* Revision:		  1.0
* Last Updated: June 1, 2010
*
* Description:	Main File for the DEFCON 18 Badge (Freescale MC56F8006)
* Notes:
*
* None yet!	
*******************************************************************************/

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"

/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "DC18_Badge.h"
#include "DC18_LCD.h"
#include "DC18_Graphics.h"

#define DEBUG 1

/****************************************************************************
 ************************** Global variables ********************************
 ***************************************************************************/

// Badge
badge_state_type badge_state = DEFCON; // begin in main title/logo screen on power-up

// LCD
uint8_t gFB[BYTES_PER_IMAGE]; // frame buffer

// Icons
uint16_t	gLoc; 				// current image location 
uint16_t	gIconIdx; 		// index into icon array

// Flags
uint16_t 	gSTATE_CHANGE = TRUE; // If TRUE, need to redraw the screen since state has changed
uint16_t 	gSW = 0; 							// State of buttons (HIGH = currently pressed), bit 1 = SW1, bit 0 = SW0 
uint16_t 	gUSB_EN; 							// HIGH if USB is connected, LOW if no USB

// bloom filter
uint8_t		gBloomDegree;
uint32_t	gBloomID = 0;
uint32_t	gRNGseed = 0;

/****************************************************************************
 ************************** Functions ***************************************
 ***************************************************************************/

void dc18_badge(void)
{ 
  BloomVecBase	gBloom[DEGREE][BLOOMVEC];
  uint8_t c;
  uint16_t i, j;
  for (i=0;i<DEGREE;i++)
    for (j=0;j<BLOOMVEC;j++)
      gBloom[i][j] = 0;
	
	dc18_init(); // hardware initialization
	
  // begin operation
  while(1)
  {
	gRNGseed++;
	if (gRNGseed % 1000 == 0) Term_SendStr(".");
  	switch (badge_state)
  	{
  		case DEFCON:
  			dc18_load_image(0); // move image from program memory into frame buffer
  			break;
  		case BADGE: // Glyph selection mode
   			/*
   				load icon image into the correct location in the frame buffer
				
					image location 0
					page 2: gFB[1-30] 
					page 3: gFB[129-158] 
					page 4: gFB[257-286] 
					page 5: gFB[385-414] 

					image location 1
					page 2: gFB[33-62] 
					page 3: gFB[161-190] 
					page 4: gFB[289-318] 
					page 5: gFB[417-446] 

					image location 2
					page 2: gFB[65-94] 
					page 3: gFB[193-222]
					page 4: gFB[321-350]
					page 5: gFB[449-478]

					image location 3
					page 2: gFB[97-126] 
					page 3: gFB[225-254]
					page 4: gFB[353-382]
					page 5: gFB[481-510]
				*/
				for (i = 0; i < BYTES_PER_GLYPH_PAGE; ++i) 
				{
				  j = gLoc << 5;
				  gFB[(1 + i) + j] = dc18Glyphs[gIconIdx][i];
				  gFB[(129 + i) + j] = dc18Glyphs[gIconIdx][i + BYTES_PER_GLYPH_PAGE];
				  gFB[(257 + i) + j] = dc18Glyphs[gIconIdx][i + (BYTES_PER_GLYPH_PAGE << 1)];				   		
				  gFB[(385 + i) + j] = dc18Glyphs[gIconIdx][i + (BYTES_PER_GLYPH_PAGE * 3)]; 				
 				}  			  			
  		  break;  			
  		case JOEGRAND:
  			dc18_load_image(1);	
  			break;	
  		case KINGPIN:
  			dc18_load_image(6);		  	
  			break;
  		case BY:
  			dc18_load_image(4);		  	
  			break;
  		case AKA:
  			dc18_load_image(5);		  	
  			break;	  
		case WEBOFTRUST:
		    dc18_clear_fb();
		    break;
  		case USB:
				Term_SendStr("Welcome to the DEFCON 18 Badge."); // send message so the user knows we're in USB mode now
				while (gUSB_EN) // once we've entered this mode, stay here until USB is disconnected
				{
					if (Term_KeyPressed()) // if there's a byte waiting in the rx queue...
					{
						Term_ReadChar(&c); // ...then get it
						switch (c)
						{
							case 'C': // Clear frame buffer
								dc18_clear_fb();
								dc18_usb_send_ack();
								break;
							case 'U': // Update LCD
						 	  dc18_update_lcd();
								dc18_usb_send_ack();								
								break;
							case 'L': // Load byte into frame buffer (refer to Kent Displays' 128x32 Reflex Graphic Display Module 
												// data sheet 25138B pg. 9 for memory map)
												// Valid byte locations 0x000 (0) to 0x1FF (511)
												// 0 = pixel on (dark), 1 = pixel off (bright)
												// Use this command to load all sorts of nifty graphics and data onto the LCD through USB
												// Example: Sending '00 01 0A' will write value 0xA to address 0x001
								Term_ReadChar(&c); // These three values are raw hex bytes, NOT ASCII
								i = (uint16_t)c << 8;
								Term_ReadChar(&c);
								i |= (uint16_t)c; 
								Term_ReadChar(&c);
								if (i < BYTES_PER_IMAGE) gFB[i] = c; // load value 'c' into LCD byte location 'i'
  		  				dc18_usb_send_ack();
								break;
							case 'X': // eXit USB mode
								dc18_usb_send_ack();
							  badge_state = DEFCON;
			    			dc18_load_image(0); // move image from program memory into frame buffer
								dc18_update_lcd();  // force update 
								gUSB_EN = 0; 				// set flag to 0 to escape the while() loop
							  break;
						}
					}
				}
				break;	    			  			  							  			
		}
    			
		if (gSTATE_CHANGE)
		{
			gSTATE_CHANGE = FALSE;
			dc18_update_lcd();
		}

		if (PWREN_GetVal()) // Check if USB is connected or not...
			gUSB_EN = FALSE;
		else
			gUSB_EN = TRUE;
	
   	if (!gUSB_EN) // if we are running on battery power...
   	{ 
    	LED1_PutVal(OFF); // turn off USB indicator LED
    	dc18_sleep(); 		// sleep until external interrupt
		}
		else // USB is plugged in, so stay awake to receive and process commands
		{
    	LED1_PutVal(ON); 				 // turn on USB indicator LED
 			
			if (Term_KeyPressed()) // if there's a byte waiting in the rx queue...
			{	
				Term_ReadChar(&c); 	 // ...then get it
				if (c == '#') badge_state = USB; // enter USB mode if requested
				if (c == '?') {
				    uint32_t b;
					if (!gBloomID)
						gBloomID = gRNGseed = dc18_rng(311, gRNGseed);
				    b = gBloomID;
				    dc18_SendNum(gBloomID);
				}
				if (c == '!') 
				{
					int i,j;
					// send all but last two
					for (i=0; i<DEGREE-2; i++) 
					{
						for (j=0; j<BLOOMVEC; j++) 
						{
							dc18_SendNum(gBloom[i][j]);
						}
					}
					// merge last two filters together
					for (j=0; j<BLOOMVEC; j++) 
					{
						dc18_SendNum((gBloom[DEGREE-2][j] | gBloom[DEGREE-1][j]));
					}
				}
			}
		}
    
    dc18_get_buttons();	 // Set gSW flags based on button presses	
		dc18_change_state(gBloom); // Change state, if necessary
	if (gSW != 0 && !gBloomID) 
	    gBloomID = gRNGseed = dc18_rng(311, gRNGseed);
  }
}


/**************************************************************/

void dc18_get_buttons(void)
{
  uint8_t sw0, sw1;

	// check for button presses 
  sw0 = !EINT_SW0_GetVal();
  sw1 = !EINT_SW1_GetVal();

  if (sw0 || sw1) // one or more buttons has been pressed
	{
		Delay(100); 	// give the user time to press both buttons (also serves as overkill debounce)

 		sw0 = !EINT_SW0_GetVal();
  	sw1 = !EINT_SW1_GetVal();
	}
	
  if (sw0 && sw1) 
  	gSW = SW_BOTH; // set flags accordingly
  else if (sw0)		
  	gSW = SW_0;		 // the first person
  else if (sw1)		
  	gSW = SW_1;		 // to request freebird at hacker karaoke
  else					  
  	gSW = SW_NONE; // skips to the front of the line
}

/**************************************************************/

void dc18_change_state(BloomVecBase gBloom[DEGREE][BLOOMVEC])
{
  gSTATE_CHANGE = TRUE; 	

  switch (badge_state) 
 	{
   	case DEFCON:
   		if (gSW == SW_1) badge_state = JOEGRAND;
			else if (gSW == SW_0) 
   		{
   			// clear frame buffer and variables in preparation for the next state
   			dc18_clear_fb(); 
   			gLoc = 0;
   			gIconIdx = 0;
   			badge_state = BADGE;
   		}
			else gSTATE_CHANGE = FALSE;
 			break;
		case BADGE:
		  if (gSW == SW_1)
  		{ 
  			++gIconIdx; // point to next icon
  		  if (gIconIdx >= NUM_GLYPHS) gIconIdx = 0; // wrap-around
  		}
  		else if (gSW == SW_0)
  		{
  		  if (gIconIdx == 0) gIconIdx = NUM_GLYPHS; // wrap-around backwards
  		  --gIconIdx; // point to next icon
  		}
  		else if (gSW == SW_BOTH)
  		{
  		  if (gLoc < GLYPHS_PER_IMAGE - 1)
  			  ++gLoc; // move to next image location
  			else
  				badge_state = DEFCON; // if all glyphs have been entered, go to the next state
  		}
			else gSTATE_CHANGE = FALSE;
			break;
   	case JOEGRAND:
   		if (gSW == SW_1) badge_state = BY;
   		else if (gSW == SW_BOTH) badge_state = KINGPIN;   		
   		else gSTATE_CHANGE = FALSE;   		
   		break;     	
		case KINGPIN:
   		if (gSW == SW_0) badge_state = JOEGRAND;
			else gSTATE_CHANGE = FALSE;
			break;
   	case BY:
   		if (gSW == SW_1) badge_state = WEBOFTRUST;
   		else if (gSW == SW_0) badge_state = AKA;
   		else gSTATE_CHANGE = FALSE;   		
 			break;
		case AKA:
   		if (gSW == SW_0) badge_state = BY;
   		else gSTATE_CHANGE = FALSE; 			
   		break; 			
	case WEBOFTRUST:
   		if (gSW == SW_1) badge_state = DEFCON;
   		else if (gUSB_EN) {
		    if (gSW == SW_0) {
				// trigger WEB OF TRUST in other
				int i;
				uint32_t rBloomID = 0;
				BloomHashBase hash[SALTS];
				Term_SendChar('?');
				rBloomID = dc18_ReadNum();
				bloom_CalcHashes(rBloomID, hash);
#ifdef DEBUG
				Term_SendStr("received ID = ");
				dc18_SendNum(rBloomID);
				Term_SendStr("\n\r");
				dc18_SendNum(hash[0]);
				Term_SendStr("\n\r");
				dc18_SendNum(hash[1]);
				Term_SendStr("\n\r");
				dc18_SendNum(hash[2]);
				Term_SendStr("\n\r");
#endif
				// TODO: check all degrees
				for (i=0; i<DEGREE; i++) 
				{
					if (bloom_check(hash, gBloom[i]))
					{
#ifdef DEBUG
						Term_SendStr("Found at degree ");
						Term_SendChar((uint8_t)('0' + i));
						Term_SendStr("\n\r");
#endif
					}
				}
		    } else if (gSW == SW_BOTH) {
		        int i,j;
				BloomHashBase hash[SALTS];
				uint32_t rBloomID = 0;
				Term_SendChar('?');
				rBloomID = dc18_ReadNum();
				bloom_CalcHashes(rBloomID, hash);
				bloom_set(hash, gBloom[0]);
				Term_SendChar('!');
				// read remote filters, as +1 degree
				for (i=1;i<DEGREE; i++) 
				{
					for(j=0; j < BLOOMVEC; j++) 
					{
						BloomVecBase val = dc18_ReadNum();
						gBloom[i][j] |= val;
					}
				}
#ifdef DEBUG
				Term_SendStr("Thanks.  My filters now look like:\n\r");
				for (i=0; i<DEGREE; i++) 
				{
					Term_SendStr("degree ");
					dc18_SendNum(i);
					Term_SendStr(": ");
					for(j=0; j<BLOOMVEC; j++)
						dc18_SendNum(gBloom[i][j]);
					Term_SendStr("\n\r");
				}
#endif
		    } else gSTATE_CHANGE = FALSE;
		} else gSTATE_CHANGE = FALSE;
		break;
	  case USB:
	    if (gSW == SW_1) badge_state = DEFCON;
			else gSTATE_CHANGE = FALSE;
	  	break;
 		default:
 			gSTATE_CHANGE = FALSE;
 			break;
 	}
}


/**************************************************************/

void dc18_clear_fb(void)
{
	uint16_t i;
	
  for (i = 0; i < BYTES_PER_IMAGE; ++i) gFB[i] = 0xFF;
}


/**************************************************************/
// move full-screen (128 x 32) image from program memory into frame buffer
void dc18_load_image(uint16_t image_num)
{
  uint16_t i;
  
  for (i = 0; i < BYTES_PER_IMAGE; ++i) gFB[i] = dc18Images[image_num][i];
}

/**************************************************************/


	 	
/**************************************************************/

void dc18_update_lcd(void)
{
  // Transfer the local image buffer to display RAM, setting the border bright (off).  
  LoadData(0, BYTES_PER_IMAGE, (uint8_t*)gFB);
  LoadBorder(1);  
  
  // Perform a full-screen update of the display.  This  
  // will power-down the display driver when finished.  
  Display(0, N_ROWS); 
  
  // Set driver SPI communications signals low.  
  ZeroSPILines();
}


/**************************************************************/

void dc18_usb_send_ack(void)
{
	Term_SendChar('.');
}

/**************************************************************/

void dc18_init(void) // hardware initialization
{
	Cpu_DisableInt(); // disable global interrupts while we configure and enable all the modules

	// LED
	LED0_PutVal(OFF);
	LED1_PutVal(OFF);
		  	
	// LCD
	HardResetDisplay();	// reset the driver

	Cpu_EnableInt();  // we're ready for action, so re-enable global interrupts 
}


/**************************************************************/

void dc18_sleep(void) 
{
	Inhr6_TurnRxOff(); // disable RX buffer of Term bean to prevent spurious entry during sleep
	
 	// set GPIOA6/TXD to input before going to sleep to prevent back-powering the FT232RL
  GPIO_A_PUR &= ~GPIO_A_PUR_PU6_MASK; // disable A6 pull-up
  GPIO_A_DDR &= ~GPIO_A_DDR_DD6_MASK; // set as input
  GPIO_A_PER &= ~GPIO_A_PER_PE6_MASK; // set to GPIO mode
 
  OCCS_DIVBY |= OCCS_DIVBY_COD3_MASK; // Divide peripheral clock by 256 (1xxx) (15.625kHz @ 8MHz ROSC, ~781Hz @ 400kHz ROSC)
  PMC_SCR |= PMC_SCR_LPR_MASK; 				// Request low-power run/wait mode
     
	Cpu_SetWaitMode(); // Awake on the next external interrupt from SW0 or SW1

  PMC_SCR &= ~PMC_SCR_LPR_MASK;					// Disable low-power run/wait mode 
  OCCS_DIVBY &= ~OCCS_DIVBY_COD3_MASK;	// Restore original peripheral clock divider

	// re-enable GPIOA6/TXD to back-power the FT232RL to allow us to read the correct #PWREN value 
	// (to determine if USB is connected or not)
 	GPIO_A_PER |= GPIO_A_PER_PE6_MASK; // set to peripheral mode 	

	Inhr6_TurnRxOn(); // re-enable RX buffer now that we're awake
}


uint32_t dc18_rng(uint32_t salt, uint32_t seed) {
    seed = seed * 117 + salt;
    return seed;
}

void dc18_SendNum(uint32_t b) 
{
    int i;
	for (i=0; i<32; i+=4) {
		uint32_t d = (b >> 28-i) & 0xF;
		if (d < 10) Term_SendChar((uint8_t)('0'+d));
		else Term_SendChar((uint8_t)('A'-10+d));
	}
}

uint32_t dc18_ReadNum()
{
    uint8_t c;
    int bits;
	uint32_t num = 0;
	int i;
	for (i = 0; i<32; i+=4) 
	{
		Term_ReadChar(&c);
		if (c >= 'A')
			bits = 10 + (c - 'A');
		else
			bits = c-'0';
		num |= ((uint32_t)bits) << (28-i);
	}
    return num;
}

void bloom_CalcHashes(uint32_t rBloomID, BloomHashBase hash[SALTS])
{
	uint32_t mod = BLOOMVEC * sizeof(BloomVecBase) * 8;
	hash[0] = (BloomHashBase) (dc18_rng(311, rBloomID) % mod);
	hash[1] = (BloomHashBase) (dc18_rng(997, rBloomID) % mod);
	hash[2] = (BloomHashBase) (dc18_rng(0xDEADBEEF, rBloomID) % mod);
}

short bloom_check(BloomHashBase hash[], BloomVecBase vec[])
{
	int i;
	int bitsize = sizeof(BloomVecBase) * 8;
	for (i=0; i<SALTS; i++) 
	{
		uint32_t vecPos = hash[i] / bitsize;
		uint32_t vecBit = hash[i] % bitsize;
		if (!(vec[vecPos] & ((BloomVecBase)1<<vecBit)))
		    return 0;
	}
	return 1;
}

void bloom_set(BloomHashBase hash[], BloomVecBase vec[])
{
	int i;
	int bitsize = sizeof(BloomVecBase) * 8;
	for (i=0; i<SALTS; i++) 
	{
		uint32_t vecPos = hash[i] / bitsize;
		uint32_t vecBit = hash[i] % bitsize;
		vec[vecPos] |=((BloomVecBase)1<<vecBit);
	}
}


/**************************************************************
/* INTERRUPT SERVICE ROUTINES
/**************************************************************/



/**************************************************************
/* MISC. UTILITY FUNCTIONS
/**************************************************************/



/**************************************************************
*	Function:  SendChar
*
*	Bit-banged asynchronous serial @ 1200, 8N1
* These are not very accurate because they could get interrupted
**************************************************************/

void SendChar(uint8_t data)
{
	uint16_t i = 0;

  // start bit
  SOUT1_PutVal(LOW);
  Cpu_Delay100US(8); // wait for duration corresponding to baud rate

	// send bits 7..0, LSB first
  for(i = 0; i < 8; i++)
  {
    // set line high if bit is 1, low if bit is 0
  	if (data & 0x01)
  		SOUT1_PutVal(HIGH);
    else
  		SOUT1_PutVal(LOW);
         
    data >>= 1;
    
    Cpu_Delay100US(8);
  }
  
  // stop bit
  SOUT1_PutVal(HIGH);
  Cpu_Delay100US(8); 
}    
      
/*void SendMsg(uint8_t *msg) 
{
  uint8_t ix = 0;	   // String pointer
  uint8_t nxt_char;
  
  nxt_char = msg[ix++];
  while(nxt_char != 0x00) 
  {
    SendChar(nxt_char);
    nxt_char = msg[ix++];
  }
}*/


/**************************************************************
*	Function: 	delay_ms
*	Parameters: 16-bit delay value
*	Return:		none
*
*	Simple delay loops
* These are not very accurate because they could get interrupted
**************************************************************/
 
void Delay(uint16_t ms)  // delay the specified number of milliseconds
{
  uint16_t i;

  for (i = 0; i < ms; ++i)
  	Cpu_Delay100US(10);
}

/****************************** END OF FILE **********************************/

