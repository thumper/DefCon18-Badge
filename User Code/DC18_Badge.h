/******************************************************************************
*
* DEFCON 18 BADGE
*
* Filename:		DC18_Badge.h
* Author:		  Joe Grand (Kingpin)
* Revision:		1.0
*
* Description:	Header File for the DEFCON 18 Badge (Freescale MC56F8006)
* Notes:
*
* None yet!	
*******************************************************************************/

#ifndef __DC18__
#define __DC18__

#include <stdint.h>


/**************************************************************************
************************** Definitions ************************************
***************************************************************************/

#define LOW   0
#define HIGH  1

#define ON    HIGH 
#define OFF   LOW

#define SW_NONE 	0b00
#define SW_0			0b01
#define	SW_1			0b10
#define SW_BOTH		0b11

#define SALTS 3
#define DEGREE 4
#define BLOOMVEC 16


/**************************************************************************
************************** Macros *****************************************
***************************************************************************/


/**************************************************************************
************************** Structs ****************************************
***************************************************************************/

typedef enum
{
	DEFCON,
	EIGHTEEN, // * 0xE38 + 16¢
	BADGE,
	BY,
	JOEGRAND,
	AKA,
	KINGPIN,
	USB,
	NINJA,
	WEBOFTRUST
} badge_state_type;



/***********************************************************************
 ************************** Function prototypes ************************
 ***********************************************************************/

typedef uint16_t BloomHashBase;
typedef uint32_t BloomVecBase;
void bloom_CalcHashes(uint32_t rBloomID, BloomHashBase hash[SALTS]);
short bloom_check(BloomHashBase *hash, BloomVecBase vec[]);
void bloom_set(BloomHashBase *hash, BloomVecBase vec[]);
uint32_t bloom_getId();

void draw_medium(int c, uint8_t row, uint16_t col);
void stripe_write(unsigned char block, uint16_t block_length,
	uint16_t start, uint8_t start_height, uint8_t end_height);
void set_point(uint8_t row, uint16_t col, uint8_t val);
void draw_Num(uint32_t b, uint8_t row, uint16_t col);


void dc18_badge(void);
void dc18_get_buttons(void);
void dc18_change_state(BloomVecBase gBloom[DEGREE][BLOOMVEC]);

void dc18_clear_fb(void);
void dc18_load_image(uint16_t image_num);
void dc18_update_lcd(void);
void dc18_usb_send_ack(void);

void dc18_init(void);
void dc18_sleep(void);


void SendChar(uint8_t);
//void SendMsg(uint8_t *msg);
void Delay(uint16_t ms);

uint32_t dc18_rng(uint32_t salt, uint32_t seed);
void dc18_SendNum(uint32_t b);
uint32_t dc18_ReadNum();



/**************************************************************************
************** 000017F0: 0060d0f5bfd62049a77dcfc3a14fad8b *****************
***************************************************************************/

#endif /* __DC18__ */
