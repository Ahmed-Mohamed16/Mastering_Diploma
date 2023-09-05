/* Startup.c */
/* Eng.Ahmed Mohamed */

#include <stdint.h>

void Reset_Handler ();

void Dafault_Handler()
{
	Reset_Handler();
}

void NMI_Handler() __attribute__ ((weak, alias ("Dafault_Handler")));;
void Hard_Fault_Handler () __attribute__ ((weak, alias ("Dafault_Handler")));;
void MM_fault_Handler() __attribute__ ((weak, alias ("Dafault_Handler")));;
void Bus_Fault() __attribute__ ((weak, alias ("Dafault_Handler")));;
void Usage_Fault_Handler() __attribute__ ((weak, alias ("Dafault_Handler")));;

extern unsigned int _stack_top;

/* Create an array contain .ward vectors => global array -> will be in .data section */
/* Just we want to make the start address of this array @ 0x08000000 -> which is the start of flash */
uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t *)&_stack_top , 
	(uint32_t *)&Reset_Handler , 
	(uint32_t *)&NMI_Handler ,
	(uint32_t *)&Hard_Fault_Handler ,
	(uint32_t *)&MM_fault_Handler ,
	(uint32_t *)&Bus_Fault ,
	(uint32_t *)&Usage_Fault_Handler
};

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;


void Reset_Handler()
{
	/* Copy data section from flash to ram */
	unsigned int data_size = (unsigned char *)&_E_data - (unsigned char *)&_S_data;
	unsigned char *P_src = (unsigned char *)&_E_text;
	unsigned char *P_dst = (unsigned char *)&_S_data;
	
	for (int i=0 ; i<data_size ; i++)
	{
		*((unsigned char *)P_dst++) = *((unsigned char *)P_src++);
	}
	
	/* Initialize .bss section in sram with 0 */
	unsigned int bss_size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;
	unsigned char *P_dst = (unsigned char *)&_S_bss;
	
	for (int i=0 ; i<bss_size ; i++)
	{
		*((unsigned char *)P_dst++) = 0;
	}
	
	/* jumb to main */
	main();
}
