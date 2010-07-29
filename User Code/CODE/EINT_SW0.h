/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : EINT_SW0.H
**     Project   : DC18
**     Processor : MC56F8006_32_LQFP
**     Component : ExtInt
**     Version   : Component 02.094, Driver 02.04, CPU db: 3.00.188
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 5/31/2010, 7:58 PM
**     Abstract  :
**         This bean "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The bean uses one pin which generates interrupt on 
**         selected edge.
**     Settings  :
**         Interrupt name              : INT_GPIO_C
**         User handling procedure     : EINT_SW0_OnInterrupt
**
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       12            |  GPIOC0_ANA5_FAULT0_CMP1_M1
**             ----------------------------------------------------
**
**         Port name                   : GPIOC
**
**         Bit number (in port)        : 0
**         Bit mask of the port        : 1
**
**         Signal edge/level           : falling
**         Priority                    : 0
**         Pull option                 : up
**         Initial state               : Enabled
**
**         Edge register               : GPIO_C_IPOLR [61894]
**         Enable register             : GPIO_C_IENR [61893]
**         Request register            : GPIO_C_IESR [61896]
**
**         Port data register          : GPIO_C_DR [61889]
**         Port control register       : GPIO_C_DDR [61890]
**         Port function register      : GPIO_C_PER [61891]
**     Contents  :
**         GetVal - bool EINT_SW0_GetVal(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __EINT_SW0_H
#define __EINT_SW0_H

/* MODULE EINT_SW0. */

/*Including shared modules, which are used in the whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"


#define EINT_SW0_PIN_MASK       ((byte)1) /* Pin mask */

#define EINT_SW0_GetVal() ((bool)(getRegBits(GPIO_C_RAWDATA,EINT_SW0_PIN_MASK)))
/*
** ===================================================================
**     Method      :  EINT_SW0_GetVal (component ExtInt)
**
**     Description :
**         Returns the actual value of the input pin of the bean.
**     Parameters  : None
**     Returns     :
**         ---             - Returned input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
** ===================================================================
*/

/* END EINT_SW0. */

#endif /* __EINT_SW0_H*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
