#ifndef MADC_PRIVATE_H
#define MADC_PRIVATE_H

#define MADC_u8_ADMUX_REG 			*((volatile u8*)0x27)
#define	MADC_u8_ADCSRA_REG			*((volatile u8*)0x26)


#define MADC_u8_SFIOR_REG			*((volatile u8*)0x50)


#define MADC_u8_ADCH_REG			*((volatile u8*)0x25)
#define MADC_u8_ADCL_REG			*((volatile u8*)0x24)

#define MADC_u16_ADC_REG			*((volatile u16*)0x24)

/*VREF Config options*/
#define MADC_u8_AREF         		0b00000000
#define MADC_u8_AVCC         		0b01000000
#define MADC_u8_Internal_VREF		0b11000000

/*Adj Config Options */
#define MADC_u8_Right_Adj			0b00000000
#define MADC_u8_Left_Adj			0b00100000


#endif
