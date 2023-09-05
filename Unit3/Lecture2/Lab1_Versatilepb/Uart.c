#include "PlatForm_Types.h"

#include "Uart.h"

/* Define UART data register */
#define UARTODR     *((volatile uint32 *)0x101f1000)

void Uart_Send_String(uint8 *Copy_Pu8String)
{
	/* Loop until the end of string */
	while(Copy_Pu8String != '\0')
	{
		/* Cast the data to 4byte -> Because UARTODR is 4byte register */
		UARTODR = (uint32)*Copy_Pu8String;
		/* Go to next char */
		Copy_Pu8String++;
	}
}