#include "std_types.h"
#include "MDIO_Interface.h"
#include "MADC_Interface.h"
#include "HLCD_interface.h"
#define F_CPU 8000000UL
#include "avr/delay.h"


int main(void){
	u16 Local_u16DigitalValue;
	u16 Local_u16AnalogValue;
	MDIO_u8Init();
	HLCD_u8Init();

	MADC_voidInit();



	while(1){
		MADC_u8GetDigitalValue(MADC_u8_CHANNEL_0, &Local_u16DigitalValue );
		Local_u16AnalogValue=(Local_u16DigitalValue*5000UL)/1024;
		//UL => cast constant num to Unsigned Long to prevent overflow
		HLCD_u8SetCursor(HLCD_u8_Line_1 , 0);
		HLCD_u8WriteString("Volt: ");
		HLCD_u16WriteNum(Local_u16AnalogValue);
		HLCD_u8SetCursor(HLCD_u8_Line_2 , 0);
		HLCD_u8WriteString("Ohm: ");
		HLCD_u16WriteNum(Local_u16AnalogValue*2);
		_delay_ms(1000);
		HLCD_u8ClrLCD();
	}
	return 0;
}
