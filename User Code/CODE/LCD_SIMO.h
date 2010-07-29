/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : LCD_SIMO.H
**     Project   : DC18
**     Processor : MC56F8006_32_LQFP
**     Component : BitIO
**     Version   : Component 02.075, Driver 01.18, CPU db: 3.00.188
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 5/31/2010, 10:09 AM
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This bean is set to work in Output direction only.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       16            |  GPIOB3_ANA3_ANB3_PWM5_MOSI_TIN3_CMP1_OUT
**             ----------------------------------------------------
**
**         Port name                   : GPIOB
**
**         Bit number (in port)        : 3
**         Bit mask of the port        : 8
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : GPIO_B_DR [61857]
**         Port control register       : GPIO_B_DDR [61858]
**         Port function register      : GPIO_B_PER [61859]
**
**         Optimization for            : code size
**     Contents  :
**         PutVal - void LCD_SIMO_PutVal(bool Val);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __LCD_SIMO_H
#define __LCD_SIMO_H

/* MODULE LCD_SIMO. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"


#define LCD_SIMO_PIN_MASK       ((byte)8) /* Pin mask */


/*
** ===================================================================
**     Method      :  LCD_SIMO_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
#define LCD_SIMO_PutVal(Val) BitIO__PutVal(BitIO__GPIO_B_DR, LCD_SIMO_PIN_MASK, Val>0?SET:CLR, 0, 0)


/* END LCD_SIMO. */

#endif /* __LCD_SIMO_H*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
