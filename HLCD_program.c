/* LIB Layer*/
#include "std_types.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

/*MCAL*/
#include "MDIO_Interface.h"

/*HAL*/
#include "HLCD_interface.h"
#include "HLCD_private.h"
#include "HLCD_config.h"

/*Function to init LCD*/
u8 HLCD_u8Init(void){
 u8 Local_u8ErrorState = STD_TYPES_OK;
 _delay_ms(31);
 /*Function Set Command*/
 HLCD_u8WriteCmnd(0x38);
 _delay_us(40);
 /*Display on/off Command*/
 HLCD_u8WriteCmnd(0x0F);
 _delay_us(40);
 /*Display Clear*/
 HLCD_u8WriteCmnd(0x01);
 _delay_ms(2);
 /*Entry Mode Set Command*/
 HLCD_u8WriteCmnd(0x06);
 return Local_u8ErrorState;
}

/*Function to Send commands to LCD*/
u8 HLCD_u8WriteCmnd(u8 Copy_u8Cmnd){
 u8 Local_u8ErrorState = STD_TYPES_OK;
 /*Set RS Pin -> Low (Command) */
 MDIO_u8SetPinValue(HLCD_u8_RS_PORT,HLCD_u8_RS_PIN,MDIO_u8_LOW);
 /*Set RW Pin -> Low (Write)  */
 MDIO_u8SetPinValue(HLCD_u8_RW_PORT,HLCD_u8_RW_PIN,MDIO_u8_LOW);
 /*Send Command on Data Pins */
 MDIO_u8SetPortValue(HLCD_u8_DATA_PORT,Copy_u8Cmnd);
 /*Enable Pulse High -> Low */
 MDIO_u8SetPinValue(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN,MDIO_u8_HIGH);
 _delay_us(1);
 MDIO_u8SetPinValue(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN,MDIO_u8_LOW);
 return Local_u8ErrorState;
}

/*Function to Write Char on LCD*/
u8 HLCD_u8WriteChar(u8 Copy_u8Char){
 u8 Local_u8ErrorState = STD_TYPES_OK;
 /*Set RS Pin -> High (Char) */
 MDIO_u8SetPinValue(HLCD_u8_RS_PORT,HLCD_u8_RS_PIN,MDIO_u8_HIGH);
 /*Set RW Pin -> Low (Write)  */
 MDIO_u8SetPinValue(HLCD_u8_RW_PORT,HLCD_u8_RW_PIN,MDIO_u8_LOW);
 /*Send Command on Data Pins */
 MDIO_u8SetPortValue(HLCD_u8_DATA_PORT,Copy_u8Char);
 /*Enable Pulse High -> Low */
 MDIO_u8SetPinValue(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN,MDIO_u8_HIGH);
 _delay_us(1);
 MDIO_u8SetPinValue(HLCD_u8_EN_PORT,HLCD_u8_EN_PIN,MDIO_u8_LOW);
 return Local_u8ErrorState;
}

/*Function to Set Cursor*/
u8 HLCD_u8SetCursor(u8 Copy_u8LineNum , u8 Copy_u8CharNum){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(Copy_u8LineNum){
	case HLCD_u8_Line_1:
		HLCD_u8WriteCmnd(0x80+Copy_u8CharNum);
		break;
	case HLCD_u8_Line_2:
		HLCD_u8WriteCmnd(0xC0+Copy_u8CharNum);
		break;
	default:
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

/*Function to write String*/
u8 HLCD_u8WriteString(u8 Copy_u8String[]){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	for(u8 i=0 ; Copy_u8String[i] != '\0';i++){
		HLCD_u8WriteChar(Copy_u8String[i]);
	}
	return Local_u8ErrorState;
}

/*Function to write Number*/
u8 HLCD_u16WriteNum(u16 Copy_u8Num){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u16 Local_u16temp;
	u16 Local_u16tempNum=Copy_u8Num;
	u8 Local_u8DigitNum=0;
	if(Copy_u8Num==0){
		HLCD_u8WriteChar(48+Copy_u8Num);
	}
	else{
	while(Local_u16tempNum!=0){
		Local_u16tempNum=Local_u16tempNum/10;
		Local_u8DigitNum++;
	}
	for(s8 Local_s8LoopCount=Local_u8DigitNum-1 ;Local_s8LoopCount>=0 ; Local_s8LoopCount-- ){
		Local_u16temp=Copy_u8Num/PRIVATE_u16Power(10,Local_s8LoopCount);
		Copy_u8Num=Copy_u8Num-(Local_u16temp*PRIVATE_u16Power(10,Local_s8LoopCount));
		HLCD_u8WriteChar(48+Local_u16temp);
	}
	}
	return Local_u8ErrorState;
}

/*Prototype of Function to Clear LCD*/
u8 HLCD_u8ClrLCD(void){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	 /*Display Clear*/
	 HLCD_u8WriteCmnd(0x01);
	 _delay_ms(2);
	return Local_u8ErrorState;
}


/*Power Function*/
u16 PRIVATE_u16Power(u16 Copy_u16Num , u8 Copy_u8Power ){
	u16 Local_u16Result=1;
	for(u8 Local_u8LoopCount=1; Local_u8LoopCount<=Copy_u8Power;Local_u8LoopCount++){
		Local_u16Result=Local_u16Result*Copy_u16Num;
	}
	return Local_u16Result;
}
