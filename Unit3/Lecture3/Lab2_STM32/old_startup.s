/* Code of : startup_cortex_M3.s */
/* Eng : Ahmed Mohamed El-Sayed  */

/* Start address of SRAM @ 0x20000000 */

.section .vectors

.word   0x20001000            /* top of the stack -> address of (sp) register */
.word   _reset                /* 1 Reset */
.word   Vector_handler        /* 2 NMI */
.word   Vector_handler        /* 3 Hard Fault */
.word   Vector_handler        /* 4 MM Fault */
.word   Vector_handler        /* 5 Bus Fault */
.word   Vector_handler        /* 6 Usage Fault */
.word   Vector_handler        /* 7 RESERVED */
.word   Vector_handler        /* 8 RESERVED */
.word   Vector_handler        /* 9 RESERVED*/
.word   Vector_handler        /* 10 RESERVED */
.word   Vector_handler        /* 11 SV call */
.word   Vector_handler        /* 12 Debug reserved */
.word   Vector_handler        /* 13 RESERVED */
.word   Vector_handler        /* 14 PendSV */
.word   Vector_handler        /* 15 SysTick */
.word   Vector_handler        /* 16 IRQ0 */
.word   Vector_handler        /* 17 IRQ1 */
.word   Vector_handler        /* 18 IRQ2 */
.word   Vector_handler        /* 19 ...   */
        /* On to IRQ67 */

.section .text 

_reset:
	bl main
	b .       /* (b .) -> act like infinite loop after finishing main */


.thumb_func   /* to make assembler handle (32 or 16 bit) instruction */

Vector_handler:
	b _reset
	