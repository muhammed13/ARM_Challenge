/*
 ============================================================================
 Name        : PortDriver_Lcfg.c
 Author      : Muhammed Gamal
 Description : 
 ============================================================================
 */

/*********************************includes**********************************/
#include "PortDriver.h"
/***************************************************************************/


/*********************************definitions*******************************/

/***************************************************************************/


/******************************global variables*****************************/

/***************************************************************************/

/* PB structure used with Dio_Init API */
const PortDriver_CfgType Port_Configuration =
                                   {
									   /* Channel		                 PortDriver_Channel_Direction          PortDriver_Channel_Current_mA                         PortDriver_Channel_SlewRate                PortDriver_Channel_Attachment                   PortDriver_Channel_Function             PortDriver_Channel_IntOperation                     PortDriver_Channel_IntSense                 PortDriver_Channel_IntEdgeLevel  */
                                		   
										{PortDriver_Channel_E0,      PortDriver_Channel_Direction_INPUT,      PortDriver_Channel_Current_mA_4,                   PortDriver_Channel_SlewRate_Disable,       PortDriver_Channel_Attachment_NotConnected,      PortDriver_Channel_Function_X_DIO,      PortDriver_Channel_ExtIntOperation_Disable,      PortDriver_Channel_INTSense_EdgeSensitive,      PortDriver_Channel_Exti_Falling_Low},
										{PortDriver_Channel_A0,      PortDriver_Channel_Direction_INPUT,      PortDriver_Channel_Current_mA_4,                   PortDriver_Channel_SlewRate_Disable,       PortDriver_Channel_Attachment_PullupRes,         PortDriver_Channel_Function_X_DIO,      PortDriver_Channel_ExtIntOperation_Enable,      PortDriver_Channel_INTSense_LevelSensitive,      PortDriver_Channel_Exti_Rising_High }
								   };


