#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "UTILS.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Interface.h"
#include "ADC_Interface.h"

int main(void)
{
	DIO_SetPinDirection(PORT_A,PIN0,OUTPUT);
	DIO_SetPinDirection(PORT_A,PIN1,OUTPUT);
	DIO_SetPinDirection(PORT_A,PIN2,OUTPUT);
	DIO_SetPortDirection(PORT_B,OUTPUT);
	LCD_Init();
	ADC_Init(REF_VCC,ADC_SCALER_64);
	
	LCD_WriteString("ADC");
	u16 x,y;
	while (1)
	{
		
		x=ADC_Read(CH_7);
		LCD_GoTo(2,1);
		LCD_WriteNumber_4D(x);
		
		y=ADC_Read(CH_6);
		LCD_GoTo(2,7);
		LCD_WriteNumber_4D(y);
	}
}
