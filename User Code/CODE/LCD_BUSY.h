/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : LCD_BUSY.H
**     Project   : DC18
**     Processor : MC56F8006_32_LQFP
**     Component : BitIO
**     Version   : Component 02.075, Driver 01.18, CPU db: 3.00.188
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 5/31/2010, 10:09 AM
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This bean is set to work in Input direction only.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       10            |  GPIOC2_PGA0INV_ANA9_CMP2_P4
**             ----------------------------------------------------
**
**         Port name                   : GPIOC
**
**         Bit number (in port)        : 2
**         Bit mask of the port        : 4
**
**         Initial direction           : Input (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : GPIO_C_DR [61889]
**         Port control register       : GPIO_C_DDR [61890]
**         Port function register      : GPIO_C_PER [61891]
**
**         Optimization for            : code size
**     Contents  :
**         GetVal - bool LCD_BUSY_GetVal(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __LCD_BUSY_H
#define __LCD_BUSY_H

/* MODULE LCD_BUSY. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"


#define LCD_BUSY_PIN_MASK       ((byte)4) /* Pin mask */


/*
** ===================================================================
**     Method      :  LCD_BUSY_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This bean is set to work in Input direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define LCD_BUSY_GetVal() ((bool)(getRegBits(GPIO_C_DR,LCD_BUSY_PIN_MASK)))


/* END LCD_BUSY. */

#endif /* __LCD_BUSY_H*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
