#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H

/*Macros for Line Number*/
#define HLCD_u8_Line_1		1
#define HLCD_u8_Line_2		2

/*Prototypes of LCD Functions*/

/*Prototype of Function to init LCD*/
u8 HLCD_u8Init(void);

/*Prototype of Function to Send commands to LCD*/
u8 HLCD_u8WriteCmnd(u8 Copy_u8Cmnd);

/*Prototype of Function to Write Char on LCD*/
u8 HLCD_u8WriteChar(u8 Copy_u8Char);

/*Prototype of Function to Set Cursor*/
u8 HLCD_u8SetCursor(u8 Copy_u8LineNum , u8 Copy_u8CharNum);

/*Prototype of Function to write String*/
u8 HLCD_u8WriteString(u8 Copy_u8String[]);

/*Prototype of Function to write Number*/
u8 HLCD_u16WriteNum(u16 Copy_u8Num);

/*Prototype of Function to Clear LCD*/
u8 HLCD_u8ClrLCD(void);


#endif
