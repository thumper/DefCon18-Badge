/******************************************************************************
*
* DEFCON 18 BADGE
*
* Filename:		DC18_Graphics.h
* Author:		  Joe Grand (Kingpin)
* Revision:		1.0
*
* Description:	Header File containing graphics for the DEFCON 18 Badge (Freescale MC56F8006)
* Notes:
*
* None yet!	
*******************************************************************************/

#ifndef __DC18_GRAPHICS__
#define __DC18_GRAPHICS__


/**************************************************************************
*************************** Constants *************************************
***************************************************************************/

#define GLYPHS_PER_IMAGE			4		// Number of 30 x 30 glyphs that fit on a full display
#define BYTES_PER_GLYPH_PAGE	30	// Number of bytes in each page of a glyph

#define TUMBLERS_PER_IMAGE		15	// Number of 5 x 30 tumblers used for Ninja unlock screen
#define TUMBLER_WIDTH					5
#define TX_ICON_WIDTH					8


#define NUM_GLYPHS	11			// Number of glyphs
__pmem static const uint8_t dc18Glyphs[][120] = {
  { // 0: Alcohol
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x33, 0x7B, 0x7B, 0x33, 0x87, 
	 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x6B, 0x37, 0x9F, 0xCF, 
	 0x67, 0x33, 0x11, 0x01, 0x83, 0xC7,
	 0x2F, 0x6F, 0x0F, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x8F, 0x47, 0x23, 
	 0x91, 0x49, 0xCD, 0x9D, 0x3D, 0x7D, 0x3D, 0x0C, 0x06, 0x03, 0xE1, 0xF0, 
	 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF,
	 0x1F, 0x8F, 0xC7, 0x63, 0xB1, 0xD8, 0x68, 0xB2, 0x5B, 0x30, 0x02, 0x05, 
	 0x0D, 0x10, 0x2D, 0x2D, 0x83, 0xCE, 0xE4, 0xF0, 0xF8, 0xFC, 0xFF, 0xBF, 
	 0x5F, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF,
	 0xFC, 0xF8, 0xF2, 0xE3, 0xC5, 0x82, 0x81, 0x80, 0x80, 0xC0, 0xE0, 0xF0, 
	 0xF8, 0xFC, 0xFE, 0xFF, 0x9F, 0xCF, 0xEF, 0xEF, 0x9F, 0xFF, 0xFF, 0xFF, 
	 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
	},
	{ // 1: Gambling
	 0x01, 0xFD, 0xFD, 0x3D, 0x1D, 0x0D, 0x0D, 0x0D, 0x0D, 0x1D, 0x3D, 0xFD, 
   0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0x3D, 0x1D, 0x0D, 0x0D, 0x0D, 
   0x0D, 0x1D, 0x3D, 0xFD, 0xFD, 0x01,
   0x00, 0xFF, 0xFF, 0xFC, 0xF8, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8, 0xFC, 0x3F, 
   0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0x3F, 0xFC, 0xF8, 0xF0, 0xF0, 0xF0, 
   0xF0, 0xF8, 0xFC, 0xFF, 0xFF, 0x00, 
   0x00, 0xFF, 0xFF, 0x3F, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0x3F, 0xFC, 
   0xF8, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8, 0xFC, 0x3F, 0x1F, 0x0F, 0x0F, 0x0F, 
   0x0F, 0x1F, 0x3F, 0xFF, 0xFF, 0x00, 
   0x80, 0xBF, 0xBF, 0xBC, 0xB8, 0xB0, 0xB0, 0xB0, 0xB0, 0xB8, 0xBC, 0xBF, 
   0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBC, 0xB8, 0xB0, 0xB0, 0xB0, 
   0xB0, 0xB8, 0xBC, 0xBF, 0xBF, 0x80
  },
  { // 2: Gaming
   0xE7, 0xC7, 0x8F, 0x1F, 0x3F, 0x1F, 0x1F, 0x3F, 0x7F, 0xFF, 0x7F, 0xBF, 
   0xDF, 0x6F, 0x37, 0x1B, 0x0D, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 
   0x01, 0x01, 0x83, 0x45, 0x4B, 0x97, 
   0xFF, 0xFF, 0x7F, 0xBF, 0xDE, 0x6E, 0x37, 0x98, 0xCC, 0x66, 0x33, 0x99, 
   0xCC, 0x66, 0x32, 0x98, 0xC8, 0x60, 0x20, 0x80, 0x80, 0x30, 0x48, 0x84, 
   0x84, 0x4B, 0x34, 0x88, 0x48, 0xA4, 
   0x0D, 0x06, 0x03, 0x01, 0x80, 0x40, 0x20, 0x40, 0x80, 0x42, 0x23, 0x49, 
   0x8C, 0x26, 0x73, 0xD9, 0xCC, 0x6E, 0x3B, 0x99, 0x4D, 0xA7, 0xD2, 0xE8, 
   0xF4, 0xFA, 0xFD, 0xFE, 0xFF, 0xFF, 
   0xF4, 0xE8, 0xD0, 0xA0, 0xC8, 0x95, 0xA2, 0x90, 0x88, 0x90, 0xA2, 0x95, 
   0xC8, 0xA0, 0xD0, 0xE8, 0xF4, 0xFA, 0xFD, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  },
  { // 3: Electronics
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 
   0x7F, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x3F, 0x9F, 0xCF, 0x67, 0x33, 0x19, 
   0x09, 0x8D, 0xC7, 0xE3, 0xF1, 0xF9, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7C, 0x31, 0x01, 
   0x03, 0x06, 0x04, 0x0C, 0x18, 0x73, 0xC1, 0x01, 0x60, 0xF8, 0xFC, 0xFE, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0x07, 0x07, 0x87, 0x77, 0x0F, 0x07, 0x2B, 0x01, 0xAA, 0x40, 0x28, 0x10, 
   0x08, 0x94, 0xA6, 0xA6, 0xA4, 0xA4, 0x21, 0x4B, 0x98, 0x3F, 0x7F, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0x80, 0x87, 0x84, 0xC2, 0xA1, 0x91, 0xC9, 0xA5, 0x94, 0x94, 0x94, 0x94, 
   0x92, 0x89, 0xA4, 0xD2, 0x92, 0xA4, 0xC9, 0x92, 0xA4, 0xC9, 0x92, 0xA4, 
   0xC9, 0x93, 0xA7, 0xCF, 0x9F, 0xBF
  },
  { // 4: Locksport
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x0F, 0x07, 0x87, 
   0x83, 0xC3, 0xC3, 0xC3, 0xC3, 0x83, 0x87, 0x07, 0x0F, 0x0F, 0x1F, 0x3F, 
   0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
   0xFF, 0xFF, 0x3F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x1F, 0x1F, 
   0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1E, 0x00, 0x00, 0x00, 
   0x00, 0x1F, 0x1F, 0x3F, 0xFF, 0xFF, 
   0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x8C, 0xDE, 0xFF, 0xFF, 0xDE, 0x8C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xF0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
   0xC1, 0xC1, 0xC1, 0xC1, 0xC1, 0xC1, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
   0xC0, 0xC0, 0xE0, 0xF0, 0xFF, 0xFF
  },
  { // 5: Love
   0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x0F, 0x07, 0x07, 0x07, 0xC7, 0x87, 
   0x8F, 0x0F, 0x1F, 0x1F, 0x0F, 0x0F, 0x07, 0x07, 0x07, 0xC7, 0x87, 0x8F, 
   0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 
   0xFF, 0xC1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
   0x02, 0x00, 0x00, 0x00, 0xC1, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 
   0xF0, 0xF8, 0xFC, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 
   0xF8, 0xF0, 0xE0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF 
  },
  { // 6: Music
   0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xFF, 0x0F, 
   0x0F, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F, 
   0x7F, 0x7F, 0x7F, 0x7F, 0xBF, 0xBF,
   0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xFF, 0x00, 
   0xFF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDE, 0xDE, 0xDE, 0xDE, 0xDE, 0xDC, 0xDC, 
   0xDC, 0xDC, 0xFC, 0x00, 0xFF, 0xDF, 
   0xEF, 0xFF, 0x8F, 0x07, 0x03, 0x03, 0x03, 0x03, 0x07, 0x0F, 0x1F, 0x00, 
   0xFF, 0xEF, 0xEF, 0xEF, 0xEF, 0xEF, 0x6F, 0x2F, 0x1F, 0x1F, 0x1F, 0x1F, 
   0x2F, 0x6F, 0xEF, 0x00, 0xFF, 0xEF, 
   0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF6, 0xF6, 0xF6, 0xF6, 0xF6, 0xF7, 0xF7, 
   0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF4, 0xF8, 0xF8, 0xF0, 0xF0, 0xF0, 
   0xF0, 0xF0, 0xF8, 0xF8, 0xF7, 0xF7 
  },
  { // 7: Network
   0xFF, 0x03, 0x3B, 0x3B, 0x3B, 0x3B, 0x3B, 0xBB, 0x03, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x3B, 0x3B, 
   0x3B, 0x3B, 0x3B, 0xBB, 0x03, 0xFF,
   0xFF, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x7C, 0x7C, 0x7C, 0x7F, 0x7F, 0x7F, 
   0x7F, 0x3F, 0xBF, 0xBF, 0x3F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7C, 0x7C, 0x7C, 
   0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFF,
   0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x3E, 
   0xBE, 0xBC, 0x81, 0x81, 0xBC, 0xBE, 0x3E, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 
   0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 
   0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xCB, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  },
  { // 8: Software
   0x01, 0xFD, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
   0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
   0x05, 0x85, 0x85, 0x85, 0xFD, 0x01, 
   0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 
   0x20, 0x10, 0x90, 0x90, 0x10, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x03, 0x02, 0x02, 0xFE, 0x00, 
   0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
   0x04, 0x08, 0x09, 0x09, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 
   0x80, 0xBF, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 
   0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 
   0xA0, 0xA0, 0xA0, 0xA0, 0xBF, 0x80
  },
  { // 9: Telephony
   0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x0F, 0x07, 0x07, 0x87, 0xC7, 0xE7, 0x07, 
	 0x07, 0x67, 0x67, 0x67, 0x67, 0x07, 0x07, 0xE7, 0xC7, 0x87, 0x07, 0x07, 
	 0x0F, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF,
	 0xFC, 0x7C, 0x3C, 0x1C, 0x0C, 0x8C, 0x44, 0xE4, 0xE4, 0xF3, 0x91, 0xB8, 
	 0xF8, 0xF8, 0xC8, 0xD8, 0xF8, 0xF8, 0x98, 0xB1, 0xF3, 0xE4, 0x64, 0xC4, 
	 0x8C, 0x0C, 0x1C, 0x3C, 0x7C, 0xFC,
	 0xFF, 0x00, 0x00, 0x0C, 0x12, 0x77, 0x9E, 0xBE, 0xFF, 0xFF, 0x7F, 0xFF, 
	 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x1F, 0x3F, 0x3E, 0xFE, 
	 0x73, 0x16, 0x0C, 0x00, 0x00, 0xFF,
	 0xFF, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE1, 0xE1, 0xE3, 0xE2, 0xE6, 
	 0xE7, 0xE7, 0xE4, 0xE5, 0xE7, 0xE7, 0xE7, 0xE3, 0xE3, 0xE0, 0xE0, 0xE0, 
	 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF
  },
  { // 10: Wireless
	 0x1F, 0x8F, 0xC7, 0xE3, 0xF1, 0xF9, 0x7D, 0x3F, 0x1F, 0x8F, 0xCF, 0xFF, 
	 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x8F, 0x1F, 0x3F, 0x7F, 
	 0xF9, 0xF1, 0xE3, 0xC7, 0x0F, 0x3F,
	 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xF8, 0xFC, 0xFE, 0xFF, 0xE7, 0xE3, 0xF1, 
	 0x38, 0x1C, 0x0F, 0x0F, 0x1C, 0x38, 0xF1, 0xE3, 0xE7, 0xFF, 0xFE, 0xFC, 
	 0xF8, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF,
	 0x8F, 0x0F, 0x3F, 0x7F, 0xF3, 0xE3, 0xC7, 0x8F, 0x1F, 0x39, 0xF1, 0xF3, 
	 0xFE, 0xFC, 0x00, 0x00, 0xFC, 0xFE, 0xF3, 0xF1, 0x39, 0x1F, 0x8F, 0xC7, 
	 0xE3, 0xF3, 0x7F, 0x3F, 0x0F, 0x8F,
	 0xFF, 0xFF, 0xFE, 0xFC, 0xF8, 0xF1, 0xF3, 0xE7, 0xE7, 0xFF, 0xFF, 0xFF, 
	 0xFF, 0xFF, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xE7, 0xF3, 
	 0xF1, 0xF8, 0xFC, 0xFE, 0xFF, 0xFF  
  }
};



// Full-screen graphic images
__pmem static const uint8_t dc18Images[][512] = {
  { // 0: DEFCON logo
   0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 
   0x3F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 
   0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 
   0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 
   0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 
   0x3F, 0x3F, 0x3F, 0x3F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0x7F, 0x3F, 0x1F, 0x1F, 0x1F, 0x0F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 
   0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 
   0xF8, 0xF0, 0x00, 0x00, 0x00, 0x03, 0x07, 0x3F, 0xFF, 0xFF, 0xFF, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 
   0x3C, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 
   0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0xFF, 0x1F, 
   0x07, 0x01, 0x00, 0x00, 0xC0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC, 
   0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xFF, 0xFF, 0xFF, 0x3F, 0x07, 0x61, 
   0x78, 0x78, 0x60, 0xC0, 0xFC, 0xFE, 0xBB, 0x71, 0xFB, 0xFF, 0xFB, 0x71, 
   0xBB, 0xFE, 0xFC, 0xC0, 0x60, 0x78, 0x78, 0x63, 0x0F, 0xFF, 0xFF, 0xFF, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x80, 0x01, 0x07, 0x0F, 0x1F, 0x3F, 
   0x7F, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 
   0x1F, 0x0F, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xFC, 0xFF, 0xFF, 0xFF, 0x00, 
   0x00, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 
   0x3C, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 
   0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xF8, 
   0xE0, 0x80, 0x00, 0x00, 0x03, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F, 
   0x3F, 0x3F, 0x1F, 0x1F, 0x1F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFC, 0xE0, 0x80, 
   0x20, 0xF0, 0xE0, 0xB0, 0x30, 0x19, 0x1B, 0x0F, 0x0E, 0x06, 0x0E, 0x0F, 
   0x1B, 0x19, 0x31, 0xB0, 0xE0, 0x70, 0x20, 0xC0, 0xF0, 0xFF, 0xFF, 0xFF, 
   0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xF0, 0xE0, 
   0xC0, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 
   0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
   0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 
   0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 
   0xFC, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFE, 0xFD, 0xF8, 0xF8, 0xF8, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 
   0xF0, 0xF8, 0xF8, 0xFC, 0xFD, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC
  },
  { // 1: Grand Idea Studio logo
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x0F, 0x07, 0x87, 
   0xC3, 0x81, 0x00, 0x00, 0x00, 0x00, 0x81, 0xC3, 0x83, 0x07, 0x0F, 0x1F, 
   0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x0F, 
   0x8F, 0x8F, 0x0F, 0x1F, 0x1F, 0x3F, 0xFF, 0x0F, 0x0F, 0x0F, 0x8F, 0x8F, 
   0x8F, 0x0F, 0x1F, 0x3F, 0xFF, 0xFF, 0x1F, 0x07, 0x87, 0x07, 0x1F, 0x7F, 
   0xFF, 0xFF, 0x07, 0x07, 0x07, 0x0F, 0x3F, 0x7F, 0xFF, 0x03, 0x03, 0x03, 
   0xFF, 0x03, 0x03, 0x03, 0xE3, 0xE3, 0xE3, 0xE3, 0xC3, 0x07, 0x0F, 0x1F, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x60, 0x00, 0x03, 0x0F, 
   0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x0F, 0x87, 0x80, 0xC0, 
   0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xC0, 0x00, 0x00, 0x1F, 0x3F, 
   0x33, 0x33, 0x33, 0x12, 0x02, 0x02, 0xC3, 0x00, 0x00, 0x00, 0xE3, 0xC3, 
   0x81, 0x10, 0x18, 0x3C, 0x07, 0x00, 0x80, 0xC0, 0xE7, 0xE6, 0xE0, 0x80, 
   0x83, 0x8F, 0x80, 0x80, 0x80, 0xFF, 0xFC, 0xF8, 0xE0, 0xC0, 0xC0, 0xC0, 
   0xFF, 0xE0, 0xC0, 0xC0, 0xC7, 0xC7, 0xC7, 0xC7, 0xC3, 0xE0, 0xF0, 0xF8, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0xFF, 0x7F, 0x7F, 0x3F, 
   0x3F, 0x3F, 0x3F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0x3F, 0x3F, 0x3F, 0xFF, 
   0xFF, 0x7F, 0x3F, 0x3F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x3F, 0x3F, 0x7F, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x38, 0x10, 0x00, 0x80, 0xC2, 
   0xC3, 0xC3, 0xC2, 0x00, 0x00, 0xC0, 0xC6, 0xC7, 0xC7, 0xC7, 0x87, 0x0F, 
   0x0F, 0x1F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x06, 0xFE, 
   0x06, 0x02, 0x02, 0xE2, 0xE3, 0xE3, 0xC7, 0x07, 0x0F, 0x1F, 0x03, 0x03, 
   0x03, 0x33, 0x33, 0x33, 0x33, 0xFF, 0x3F, 0x07, 0x01, 0xE1, 0x81, 0x07, 
   0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0x81, 0x80, 0x98, 0x18, 0x10, 
   0x31, 0x31, 0x78, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xFF, 0x00, 
   0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 
   0xFE, 0xFE, 0xFE, 0x7C, 0x00, 0x00, 0x01, 0xFF, 0x00, 0x00, 0x00, 0xFF, 
   0xC1, 0x00, 0x00, 0x1C, 0x3F, 0x7F, 0x7F, 0x7F, 0x3E, 0x1C, 0x00, 0x00, 
   0xC1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF0, 0xF0, 0xE1, 0xE3, 0xC7, 
   0xC7, 0x8F, 0x07, 0x03, 0x03, 0x07, 0x8F, 0xC7, 0xC7, 0xC7, 0xE3, 0xE1, 
   0xF0, 0xF0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0xFF, 
   0x80, 0x80, 0x80, 0x8F, 0x8F, 0x8F, 0xC7, 0xC0, 0xE0, 0xF0, 0xC0, 0xC0, 
   0xC0, 0xC6, 0xC6, 0xC6, 0xC6, 0xC1, 0xC0, 0xE0, 0xF0, 0xF1, 0xF1, 0xF0, 
   0xF0, 0xC0, 0xC1, 0xC7, 0xFF, 0xFF, 0xF9, 0xF1, 0xE1, 0xE3, 0xE3, 0xE1, 
   0xF0, 0xF0, 0xFC, 0xFF, 0xFF, 0xF0, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFC, 
   0xF8, 0xF8, 0xF0, 0xF1, 0xF0, 0xF8, 0xF8, 0xFC, 0xFF, 0xF8, 0xF8, 0xF8, 
   0xF8, 0xF8, 0xF8, 0xFC, 0xFC, 0xFE, 0xFF, 0xFF, 0xFC, 0xFC, 0xFC, 0xFF, 
   0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFE, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  },
  { 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFC, 
   0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x0F, 0x3F, 0x7F, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 
   0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0x1F, 0x1F, 0x7F, 0xFF, 0x1F, 0x1F, 0xFF, 0x9F, 0x9F, 0x1F, 0x1F, 0x9F, 
   0x9F, 0xFF, 0x1F, 0x1F, 0x7F, 0xFF, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0x1F, 0x1F, 0xFF, 0x1F, 0x1F, 0x9F, 0x9F, 0x1F, 0x1F, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x1F, 0x9F, 0x9F, 0x1F, 0x1F, 
   0xFF, 0x1F, 0x1F, 0x9F, 0x9F, 0x1F, 0x1F, 0xFF, 0x1F, 0x1F, 0x9F, 0x9F, 
   0x1F, 0x1F, 0xFF, 0x9F, 0x9F, 0x1F, 0x1F, 0x9F, 0x9F, 0xFF, 0x1F, 0x1F, 
   0xFF, 0xFF, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF,  
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x3F, 0x3F, 
   0x1F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x80, 
   0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xE0, 0xE0, 0xFC, 0xF8, 0xE0, 0xE0, 0xFF, 0xE7, 0xE7, 0xE0, 0xE0, 0xE7, 
   0xE7, 0xFF, 0xE0, 0xE0, 0xFC, 0xF8, 0xE0, 0xE0, 0xFF, 0xE3, 0xE3, 0xE7, 
   0xE7, 0xE0, 0xE0, 0xFF, 0xE0, 0xE0, 0xFC, 0xFC, 0xE0, 0xE0, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0xFC, 
   0xFF, 0xE0, 0xE0, 0xFC, 0xFC, 0xE0, 0xE0, 0xFF, 0xE0, 0xE0, 0xFC, 0xFC, 
   0xE0, 0xE3, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
   0xE0, 0xE0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x01, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 
   0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0xE0, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0x3F, 0x3F, 0x03, 0x01, 0x39, 0x39, 0x39, 0x01, 0x03, 0x3F, 0x3F, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0x07, 0x07, 0xE7, 0xE7, 0x07, 0x07, 0xFF, 0x07, 0x07, 0xE7, 0xE7, 0xE7, 
   0xE7, 0xFF, 0x07, 0x07, 0x3F, 0x1F, 0xC7, 0xE7, 0xFF, 0x07, 0x07, 0x27, 
   0x27, 0xE7, 0xE7, 0xFF, 0x07, 0x07, 0xE7, 0xE7, 0x07, 0x1F, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x3F, 0x03, 0x01, 0x39, 0x39, 0x39, 
   0x01, 0x03, 0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,  
   0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF0, 0xC0, 0x80, 0x80, 0x00, 
   0x00, 0x00, 0x00, 0x03, 0x0F, 0x3F, 0x3F, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF8, 0xF9, 0xF9, 0xF9, 0xF9, 0xFF, 
   0xF8, 0xF8, 0xF9, 0xF9, 0xF8, 0xF8, 0xFF, 0xF8, 0xF8, 0xF9, 0xF9, 0xF9, 
   0xF9, 0xFF, 0xF8, 0xF8, 0xFF, 0xFE, 0xF8, 0xF9, 0xFF, 0xF8, 0xF8, 0xF9, 
   0xF9, 0xF9, 0xF9, 0xFF, 0xF8, 0xF8, 0xF9, 0xF9, 0xF8, 0xFE, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 
   0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF
  },
  { 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xFC, 
   0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x0F, 0x3F, 0x7F, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 
   0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0x1F, 0x1F, 0x7F, 0xFF, 0x1F, 0x1F, 0xFF, 0x9F, 0x9F, 0x1F, 0x1F, 0x9F, 
   0x9F, 0xFF, 0x1F, 0x1F, 0x7F, 0xFF, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0x1F, 0x1F, 0xFF, 0x1F, 0x1F, 0x9F, 0x9F, 0x1F, 0x1F, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x1F, 0x9F, 0x9F, 0x1F, 0x1F, 
   0xFF, 0x1F, 0x1F, 0x9F, 0x9F, 0x1F, 0x1F, 0xFF, 0x1F, 0x1F, 0x9F, 0x9F, 
   0x1F, 0x1F, 0xFF, 0x9F, 0x9F, 0x1F, 0x1F, 0x9F, 0x9F, 0xFF, 0x1F, 0x1F, 
   0xFF, 0xFF, 0x1F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x3F, 0x3F, 
   0x1F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x80, 
   0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xE0, 0xE0, 0xFC, 0xF8, 0xE0, 0xE0, 0xFF, 0xE7, 0xE7, 0xE0, 0xE0, 0xE7, 
   0xE7, 0xFF, 0xE0, 0xE0, 0xFC, 0xF8, 0xE0, 0xE0, 0xFF, 0xE3, 0xE3, 0xE7, 
   0xE7, 0xE0, 0xE0, 0xFF, 0xE0, 0xE0, 0xFC, 0xFC, 0xE0, 0xE0, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xFC, 0xFC, 0xFC, 0xFC, 
   0xFF, 0xE0, 0xE0, 0xFC, 0xFC, 0xE0, 0xE0, 0xFF, 0xE0, 0xE0, 0xFC, 0xFC, 
   0xE0, 0xE3, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 
   0xE0, 0xE0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  
   0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x01, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 
   0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00, 0xE0, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0xFF, 
   0xFF, 0x07, 0x07, 0xFF, 0x07, 0x07, 0x1F, 0x3F, 0x07, 0x07, 0xFF, 0x07, 
   0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0xE7, 0xE7, 0x07, 0x07, 
   0xFF, 0x07, 0x07, 0xE7, 0xE7, 0xE7, 0xE7, 0xFF, 0x07, 0x07, 0x3F, 0x1F, 
   0xC7, 0xE7, 0xFF, 0x07, 0x07, 0x27, 0x27, 0xE7, 0xE7, 0xFF, 0x07, 0x07, 
   0xE7, 0xE7, 0x07, 0x1F, 0xFF, 0x07, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  
   0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF0, 0xC0, 0x80, 0x80, 0x00, 
   0x00, 0x00, 0x00, 0x03, 0x0F, 0x3F, 0x3F, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF8, 0xF9, 
   0xF9, 0xF8, 0xF8, 0xFF, 0xF8, 0xF8, 0xFF, 0xFE, 0xF8, 0xF8, 0xFF, 0xF8, 
   0xF8, 0xF9, 0xF9, 0xF9, 0xF9, 0xFF, 0xF8, 0xF8, 0xF9, 0xF9, 0xF8, 0xF8, 
   0xFF, 0xF8, 0xF8, 0xF9, 0xF9, 0xF9, 0xF9, 0xFF, 0xF8, 0xF8, 0xFF, 0xFE, 
   0xF8, 0xF9, 0xFF, 0xF8, 0xF8, 0xF9, 0xF9, 0xF9, 0xF9, 0xFF, 0xF8, 0xF8, 
   0xF9, 0xF9, 0xF8, 0xFE, 0xFF, 0xF9, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  },
  { 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE3, 0xE1, 0xF1, 0xF1, 0x71, 0x71, 0x71, 
   0x21, 0x01, 0x03, 0x83, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x87, 
   0xE1, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 
   0x01, 0x01, 0xF1, 0xF1, 0xF1, 0xF1, 0xE1, 0xC3, 0x03, 0x07, 0x0F, 0x3F, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 
   0x01, 0x31, 0x31, 0x31, 0x31, 0x71, 0xF1, 0xFF, 0xFF, 0x0F, 0x07, 0x03, 
   0x01, 0x61, 0xF1, 0xF1, 0xE1, 0x01, 0x03, 0x07, 0x1F, 0xFF, 0xFF, 0xFF, 
   0xE3, 0xF1, 0xF1, 0xF1, 0xF1, 0xE1, 0x01, 0x03, 0x03, 0x07, 0xFF, 0xFF, 
   0xFF, 0x0F, 0x07, 0x03, 0x01, 0x61, 0xF1, 0xF1, 0xE1, 0x01, 0x03, 0x07, 
   0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x0F, 0x1F, 0x1F, 0x1C, 0x1C, 0x1C, 
   0x0C, 0x00, 0x81, 0x81, 0xE3, 0xFF, 0xFF, 0xE1, 0xE0, 0xE0, 0xE3, 0xE3, 
   0xE3, 0x00, 0x00, 0x00, 0x00, 0xE3, 0xE3, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 
   0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x87, 0x80, 0xC0, 0xE0, 0xF8, 
   0xFF, 0xFF, 0xFF, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0xF8, 
   0xF8, 0xF8, 0xF8, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x0E, 0x1E, 0x1E, 
   0x1E, 0x1E, 0x0C, 0x00, 0x80, 0xC0, 0xE0, 0xFF, 0xFF, 0xFE, 0x1C, 0x18, 
   0x18, 0x18, 0x18, 0x08, 0x84, 0x80, 0xC0, 0xE0, 0xF8, 0xFF, 0xFF, 0xFF, 
   0x1F, 0x0F, 0x07, 0x03, 0x01, 0x10, 0x18, 0x1C, 0x1E, 0x1F, 0x1F, 0xFF, 
   0xFF, 0xFE, 0x1C, 0x18, 0x18, 0x18, 0x18, 0x08, 0x84, 0x80, 0xC0, 0xE0, 
   0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  },
  { 
   0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 
   0x1F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  
   0xFF, 0xFF, 0xFF, 0xE0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
   0xC0, 0xE0, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 
   0xF1, 0xF1, 0xF1, 0x01, 0x01, 0x01, 0xF1, 0xF1, 0xF1, 0xF1, 0x01, 0x01, 
   0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0x79, 0xB9, 0x99, 0x59, 0x49, 0x61, 
   0x71, 0x00, 0x00, 0x61, 0x69, 0x49, 0x59, 0x99, 0xB9, 0x39, 0x79, 0xFF, 
   0xFF, 0xFF, 0x75, 0x34, 0x96, 0xC6, 0xE0, 0xC6, 0x96, 0x36, 0x77, 0xFF, 
   0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 
   0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,  
   0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xEF, 0x0F, 0xFF, 0xFF, 0xFF, 0x9F, 0x6F, 
   0x6F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xFC, 0xFF, 0xEF, 0xEF, 0x0F, 0xFC, 0xFC, 
   0x1C, 0xCF, 0xEF, 0xCF, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xE7, 0xE7, 0xE7, 0xE6, 0x66, 0x66, 
   0x66, 0x02, 0x02, 0xE0, 0xE4, 0xE4, 0xE6, 0xE7, 0xE7, 0xE7, 0xE7, 0xFF, 
   0xFF, 0xFF, 0xFE, 0x01, 0x01, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 
   0x29, 0x29, 0x29, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 
   0x7F, 0x7F, 0x7F, 0x7F, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
   0x7F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xF7, 0xF0, 0xF7, 0xF7, 0xFF, 0xF8, 0xF7, 
   0xF6, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xF7, 0xF0, 0xF7, 0xF7, 
   0xF8, 0xF3, 0xF7, 0xF3, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 
   0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
   0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 
   0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 
   0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
  }
}; 

#define MED_DIGIT_HEIGHT 7
#define MED_DIGIT_WIDTH 5



__pmem static const unsigned char med_digit_art[][MED_DIGIT_HEIGHT] = 
{
    {
	0b01110,
	0b10001,
	0b10001,
	0b10001,
	0b10001,
	0b10001,
	0b01110
    },
    {
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100
    },
    {
	0b01110,
	0b10001,
	0b00001,
	0b00010,
	0b00100,
	0b01000,
	0b11111
    },
    {
	0b01110,
	0b10001,
	0b00001,
	0b01110,
	0b00001,
	0b10001,
	0b01110
    }, 
    {
	0b10001,
	0b10001,
	0b10001,
	0b11111,
	0b00001,
	0b00001,
	0b00001,
    },
    {
	0b11111,
	0b10000,
	0b10000,
	0b11110,
	0b00001,
	0b10001,
	0b01110,
    },
     {
	 0b01110,
	 0b10001,
	 0b10000,
	 0b11110,
	 0b10001,
	 0b10001,
	 0b01110
     },
     {
	 0b11111,
	 0b00001,
	 0b00010,
	 0b00010,
	 0b00100,
	 0b00100,
	 0b00100
     },
     {
	 0b01110,
	 0b10001,
	 0b10001,
	 0b01110,
	 0b10001,
	 0b10001,
	 0b01110
     }, 
     {
	 0b01110,
	 0b10001,
	 0b10001,
	 0b01111,
	 0b00001,
	 0b10001,
	 0b01110
     },
     {
	 0b01110,
	 0b10001,
	 0b10001,
	 0b11111,
	 0b10001,
	 0b10001,
	 0b10001
     },
     {
	 0b11110,
	 0b10001,
	 0b10001,
	 0b11111,
	 0b10001,
	 0b10001,
	 0b11110
     },
     {
	 0b01110,
	 0b10001,
	 0b10000,
	 0b10000,
	 0b10000,
	 0b10001,
	 0b01110
     },
     {
	 0b11110,
	 0b10001,
	 0b10001,
	 0b10001,
	 0b10001,
	 0b10001,
	 0b11110
     },
     {
	 0b11111,
	 0b10000,
	 0b10000,
	 0b11110,
	 0b10000,
	 0b10000,
	 0b11111
     },
     {
	 0b11111,
	 0b10000,
	 0b10000,
	 0b11110,
	 0b00000,
	 0b10000,
	 0b10000
     },
     {
	 0b10001,
	 0b10001,
	 0b01010,
	 0b00100,
	 0b01010,
	 0b10001,
	 0b10001
     },
     {
	 0b00000,
	 0b00000,
	 0b00000,
	 0b00000,
	 0b00000,
	 0b00000,
	 0b00000
     },
     {
	 0b11000,
	 0b11000,
	 0b11000,
	 0b11000,
	 0b11000,
	 0b11000,
	 0b11000
     },
};



#endif /* __DC18_GRAPHICS__ */
