/*
 * ADC_Interface.h
 *
 * Created: 03-Mar-22 12:15:46 PM
 *  Author: lenovo
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"
#include "UTILS.h"

#define ADMUX   (*(volatile unsigned char*)0x27)
#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADCSRA   (*(volatile unsigned char*)0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7

#define ADCH     (*(volatile unsigned char*)0x25)
#define ADCL     (*(volatile unsigned char*)0x24)
#define ADC      (*(volatile unsigned short*)0x24)

typedef enum{
	REF_VCC,
	REF_AREF,
	REF_256V,
}ADC_Ref_Type;

typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128,
}ADC_Scaler_Type;

typedef enum
{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7,
	}ADC_Channel_Type;

void ADC_Init(ADC_Ref_Type vref, ADC_Scaler_Type scaler);

u16 ADC_Read(ADC_Channel_Type channel);

#endif /* ADC_INTERFACE_H_ */