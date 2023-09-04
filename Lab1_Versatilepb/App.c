#include "PlatForm_Types.h"

#include "Uart.h"

uint8 String[100] = "Learn-in-Depth : Ahmed";

void main (void)
{
	
	Uart_Send_String(String);
}