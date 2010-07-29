/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Inhr6.H
**     Project   : DC18
**     Processor : MC56F8006_32_LQFP
**     Component : AsynchroSerial
**     Version   : Component 02.472, Driver 02.06, CPU db: 3.00.188
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 5/31/2010, 8:37 PM
**     Abstract  :
**         This bean "AsynchroSerial" implements an asynchronous serial
**         communication. The bean supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The bean requires one on-chip asynchronous serial channel.
**     Settings  :
**         Serial channel              : SCI
**
**         Protocol
**             Init baud rate          : 9600baud
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**             Input buffer size       : 0
**             Output buffer size      : 0
**
**         Registers
**             Input buffer            : SCI_DATA  [61668]
**             Output buffer           : SCI_DATA  [61668]
**             Control register        : SCI_CTRL1 [61665]
**             Mode register           : SCI_CTRL1 [61665]
**             Baud setting reg.       : SCI_RATE  [61664]
**
**
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Input   |     19               |  GPIOB4_ANA0_ANB0_MISO_SDA_RXD_T0_CLKO_0
**            Output  |     18               |  GPIOA6_ANA1_ANB1_FAULT0_SCL_TXD_CLKO_1
**         ----------------------------------------------------------
**
**
**
**     Contents  :
**         RecvChar        - byte Inhr6_RecvChar(Inhr6_TComData *Chr);
**         SendChar        - byte Inhr6_SendChar(Inhr6_TComData Chr);
**         GetCharsInRxBuf - word Inhr6_GetCharsInRxBuf(void);
**         TurnRxOn        - void Inhr6_TurnRxOn(void);
**         TurnRxOff       - void Inhr6_TurnRxOff(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __Inhr6
#define __Inhr6

/* MODULE Inhr6. */

#include "Cpu.h"



#ifndef __BWUserType_Inhr6_TError
#define __BWUserType_Inhr6_TError
  typedef union {
    byte err;
    struct {
      bool OverRun  : 1;               /* Overrun error flag */
      bool Framing  : 1;               /* Framing error flag */
      bool Parity   : 1;               /* Parity error flag */
      bool RxBufOvf : 1;               /* Rx buffer full error flag */
      bool Noise    : 1;               /* Noise error flag */
      bool Break    : 1;               /* Break detect */
      bool LINSync  : 1;               /* LIN synchronization error */
      bool BitError  : 1;              /* Bit error flag - mismatch to the expected value happened. */
    } errName;
  } Inhr6_TError;                      /* Error flags. For languages which don't support bit access is byte access only to error flags possible. */
#endif

#ifndef __BWUserType_Inhr6_TComData
#define __BWUserType_Inhr6_TComData
  typedef byte Inhr6_TComData;         /* User type for communication. Size of this type depends on the communication data witdh */
#endif

byte Inhr6_RecvChar(Inhr6_TComData *Chr);
/*
** ===================================================================
**     Method      :  Inhr6_RecvChar (component AsynchroSerial)
**
**     Description :
**         If any data is received, this method returns one
**         character, otherwise it returns an error code (it does
**         not wait for data). This method is enabled only if the
**         receiver property is enabled.
**         [Note:] Because the preferred method to handle error and
**         break exception in the interrupt mode is to use events
**         <OnError> and <OnBreak> the return value ERR_RXEMPTY has
**         higher priority than other error codes. As a consequence
**         the information about an exception in interrupt mode is
**         returned only if there is a valid character ready to be
**         read.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the receiver is configured to use DMA controller then
**         this method only sets the selected DMA channel. Then the
**         status of the DMA transfer can be checked using
**         GetCharsInRxBuf method. See an example of a typical usage
**         for details about the communication using DMA.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to a received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_BREAK - Break character is detected
**                           (only when the <Interrupt service>
**                           property is disabled and the <Break
**                           signal> property is enabled)
**                           ERR_COMMON - common error occurred (the
**                           <GetError> method can be used for error
**                           specification)
**                           Version specific information for
**                           Freescale 56800 derivatives ] 
**                           DMA mode:
**                           If DMA controller is available on the
**                           selected CPU and the receiver is
**                           configured to use DMA controller then
**                           only ERR_OK, ERR_RXEMPTY, and ERR_SPEED
**                           error code can be returned from this
**                           method.
** ===================================================================
*/

byte Inhr6_SendChar(Inhr6_TComData Chr);
/*
** ===================================================================
**     Method      :  Inhr6_SendChar (component AsynchroSerial)
**
**     Description :
**         Sends one character to the channel. If the bean is
**         temporarily disabled (Disable method) SendChar method
**         only stores data into an output buffer. In case of a zero
**         output buffer size, only one character can be stored.
**         Enabling the bean (Enable method) starts the transmission
**         of the stored data. This method is available only if the
**         transmitter property is enabled.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the transmitter is configured to use DMA controller then
**         this method only sets selected DMA channel. Then the
**         status of the DMA transfer can be checked using
**         GetCharsInTxBuf method. See an example of a typical usage
**         for details about communication using DMA.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/

word Inhr6_GetCharsInRxBuf(void);
/*
** ===================================================================
**     Method      :  Inhr6_GetCharsInRxBuf (component AsynchroSerial)
**
**     Description :
**         Returns the number of characters in the input buffer.
**         This method is available only if the receiver property is
**         enabled.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the receiver is configured to use DMA controller then
**         this method returns the number of characters in the
**         receive buffer.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the input
**                           buffer.
** ===================================================================
*/

void Inhr6_Init(void);
/*
** ===================================================================
**     Method      :  Inhr6_Init (component AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#define Inhr6_TurnRxOff() clrRegBit(SCI_CTRL1, RE)
/*
** ===================================================================
**     Method      :  Inhr6_TurnRxOff (component AsynchroSerial)
**
**     Description :
**         Turns off the receiver. This method is available only if
**         the receiver property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define Inhr6_TurnRxOn() setRegBit(SCI_CTRL1, RE)
/*
** ===================================================================
**     Method      :  Inhr6_TurnRxOn (component AsynchroSerial)
**
**     Description :
**         Turns on the receiver. This method is available only if
**         the receiver property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



/* END Inhr6. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

#endif /* ifndef __Inhr6 */
