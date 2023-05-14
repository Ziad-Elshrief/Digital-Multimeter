/*LIB Layer*/
#include"std_types.h"
#include"bit_math.h"

/*MCAL*/
#include"MADC_Config.h"
#include "MADC_Interface.h"
#include"MADC_Private.h"


void MADC_voidInit(void){
	/*Select VREF => AVCC */
	MADC_u8_ADMUX_REG |= MADC_u8_ADC_VREF;
	/*Select Right Adjustment*/
	MADC_u8_ADMUX_REG |= MADC_u8_ADC_Adj ;
	/*Single Conv. mode*/
	CLR_BIT(MADC_u8_ADCSRA_REG,5);
	/*Prescaler option =>64 => 125KHz */
	SET_BIT(MADC_u8_ADCSRA_REG,2);
	SET_BIT(MADC_u8_ADCSRA_REG,1);
	CLR_BIT(MADC_u8_ADCSRA_REG,0);
	/*Enable ADC*/
	SET_BIT(MADC_u8_ADCSRA_REG,7);
}

u8 MADC_u8GetDigitalValue(u8 Copy_u8ChannelNum, u16* Copy_Pu16DigitalValue){
	u8 Local_u8ErrorState=STD_TYPES_NOK;
	if( (Copy_u8ChannelNum<32) &&(Copy_Pu16DigitalValue != STD_TYPES_NULL ) ){
		Local_u8ErrorState=STD_TYPES_OK;
		/*Clear Channel Number Bits*/
		MADC_u8_ADMUX_REG &= 0b11100000;
		/*Select Channel Number*/
		MADC_u8_ADMUX_REG |= Copy_u8ChannelNum;
		/*Start Conversion */
		SET_BIT(MADC_u8_ADCSRA_REG,6);
		/*Wait for the flag*/
		while( ! GET_BIT(MADC_u8_ADCSRA_REG,4) );
		/*Clear Flag*/
		SET_BIT(MADC_u8_ADCSRA_REG,4);
		/*Read Digital Value */
		*Copy_Pu16DigitalValue= MADC_u16_ADC_REG;
	}

	return Local_u8ErrorState;
}
