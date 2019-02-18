$INCLUDE   (reg_c51.INC)

org 000h
ljmp begin

org 23h
ljmp serial_IT

;/**
; * FUNCTION_PURPOSE: This file set up uart in mode 1 (8 bits uart) with
; * internal baud rate generator.
; * FUNCTION_INPUTS: void
; * FUNCTION_OUTPUTS: void
; */
org 0100h

begin:
	MOV SCON,#50h;					  /* uart in mode 1 (8 bit), REN=1 */
   ANL BDRCON,#0EEh;             /* BRR=0; SRC=0; */
   ORL BDRCON,#0Eh;             /* TBCK=1;RBCK=1; SPD=1 */
   MOV BRL,#0FDh;               /* 9600 Bds at 11.059MHz */
 	SETB ES; 						  /* Enable serial interrupt	*/
	SETB EA;						     /* Enable global interrupt */
   ORL BDRCON,#10h;             /* Baud rate generator run*/

   JMP $;                       /* endless */

;/**
; * FUNCTION_PURPOSE: serial interrupt, echo received data.
; * FUNCTION_INPUTS: P3.0(RXD) serial input
; * FUNCTION_OUTPUTS: P3.1(TXD) serial output
; */
serial_IT:
   JNB RI,EMIT_IT              ; test if it is a reception
       	CLR RI			       ; clear reception flag for next reception
	MOV A,SBUF                  ; read data from uart
        MOV SBUF,A		       ; write same data to uart
	LJMP END_IT 
EMIT_IT: 				
   CLR TI                    	 ; clear transmition flag for next transmition

END_IT:
   RETI

end

