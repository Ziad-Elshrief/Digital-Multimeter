#ifndef MDIO_INTERFACE_H
#define MDIO_INTERFACE_H

/* Macros For PortId */
#define MDIO_u8_PORTA  				0
#define MDIO_u8_PORTB  				1
#define MDIO_u8_PORTC  				2
#define MDIO_u8_PORTD  				3

/* Macros for PinId */
#define MDIO_u8_PIN_0 				0
#define MDIO_u8_PIN_1 				1
#define MDIO_u8_PIN_2 				2
#define MDIO_u8_PIN_3 				3
#define MDIO_u8_PIN_4 				4
#define MDIO_u8_PIN_5 				5
#define MDIO_u8_PIN_6 				6
#define MDIO_u8_PIN_7 				7

/*Macros For Pin Direction */
#define MDIO_u8_OUTPUT 				1
#define MDIO_u8_INPUT_FLOATING 		0
#define MDIO_u8_INPUT_PULLED_UP		2

/* Macros for Pin Value */
#define MDIO_u8_LOW					0
#define MDIO_u8_HIGH				1

/* Prototypes for Public Interfaces*/

/*Prototype of a Function to set pin direction*/
u8 MDIO_u8SetPinDirection(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8PinDirection );

/*Prototype of a Function to set pin value*/
u8 MDIO_u8SetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 Copy_u8PinValue );

/*Prototype of a Function to get pin value*/
u8 MDIO_u8GetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 * Copy_Pu8PinValue );

/*Prototype of a Function to set port direction*/
u8 MDIO_u8SetPortDirection(u8 Copy_u8PortId , u8 Copy_u8PortDirection );

/*Prototype of a Function to set port value*/
u8 MDIO_u8SetPortValue(u8 Copy_u8PortId , u8 Copy_u8PortValue );

/*Prototype of a Function to get port value*/
u8 MDIO_u8GetPortValue(u8 Copy_u8PortId , u8 * Copy_Pu8PortValue );

/*Prototype of init Function */
u8 MDIO_u8Init(void);

#endif
