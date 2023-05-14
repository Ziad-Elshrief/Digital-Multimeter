#ifndef MADC_CONFIG_H
#define MADC_CONFIG_H

/*Config VREF*/
/*Options:
 * MADC_u8_AREF
 * MADC_u8_AVCC
 * MADC_u8_Internal_VREF */
#define MADC_u8_ADC_VREF 		MADC_u8_AVCC

/*Config Adjustment */
/*Options:
 * 1- MADC_u8_Right_Adj
 * 2- MADC_u8_Left_Adj */
#define MADC_u8_ADC_Adj			MADC_u8_Right_Adj


#endif
