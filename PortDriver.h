/*
 ============================================================================
 Name        : PortDriver.h
 Author      : Muhammed Gamal
 Description :
 ============================================================================
 */

/*********************************includes**********************************/
#include "std_types.h"
#include "PortDriver_Lcfg.h"
#include "Register.h"
/***************************************************************************/


/***************************types and definitions***************************/
typedef uint8_t PortDriver_Channel_DirectionType;
#define PortDriver_Channel_Direction_INPUT			 		0
#define PortDriver_Channel_Direction_OUTPUT					1

typedef uint8_t PortDriver_Channel_Current_mAType;
#define PortDriver_Channel_Current_mA_2			 			0
#define PortDriver_Channel_Current_mA_4			 			1
#define PortDriver_Channel_Current_mA_8			 			2
			
typedef uint8_t PortDriver_Channel_SlewRateType;
#define PortDriver_Channel_SlewRate_Disable					0
#define PortDriver_Channel_SlewRate_Enable					0

typedef uint8_t PortDriver_Channel_AttachmentType;
#define PortDriver_Channel_Attachment_NotConnected			0
#define PortDriver_Channel_Attachment_openDrain				1
#define PortDriver_Channel_Attachment_PullupRes				2
#define PortDriver_Channel_Attachment_PullDownRes			3

typedef uint8_t PortDriver_Channel_FunctionType;
#define PORTDRIVER_CHANNEL_FUNCTION_X_DIO                  0

#define PORTDRIVER_CHANNEL_FUNCTION_B1_U1Tx                1
#define PORTDRIVER_CHANNEL_FUNCTION_D6_U2Rx                1
#define PORTDRIVER_CHANNEL_FUNCTION_D7_U2Tx                1
#define PORTDRIVER_CHANNEL_FUNCTION_C6_U3Rx                1
#define PORTDRIVER_CHANNEL_FUNCTION_C7_U3Tx                1
#define PORTDRIVER_CHANNEL_FUNCTION_C4_U4Rx                1
#define PORTDRIVER_CHANNEL_FUNCTION_C5_U4Tx                1
#define PORTDRIVER_CHANNEL_FUNCTION_E4_U5Rx                1
#define PORTDRIVER_CHANNEL_FUNCTION_E5_U5Tx                1
#define PORTDRIVER_CHANNEL_FUNCTION_D4_U6Rx                1
#define PORTDRIVER_CHANNEL_FUNCTION_D5_U6Tx                1
#define PORTDRIVER_CHANNEL_FUNCTION_E0_U7Rx                1
#define PORTDRIVER_CHANNEL_FUNCTION_E1_U7Tx                1
#define PORTDRIVER_CHANNEL_FUNCTION_D0_SSI3Clk             1
#define PORTDRIVER_CHANNEL_FUNCTION_D1_SSI3Fss             1
#define PORTDRIVER_CHANNEL_FUNCTION_D2_SSI3Rx              1
#define PORTDRIVER_CHANNEL_FUNCTION_D3_SSI3Tx              1
#define PORTDRIVER_CHANNEL_FUNCTION_C0_SWCLK               1
#define PORTDRIVER_CHANNEL_FUNCTION_C1_SWDIO               1
#define PORTDRIVER_CHANNEL_FUNCTION_C3_SWO                 1
#define PORTDRIVER_CHANNEL_FUNCTION_C0_TCK                 1
#define PORTDRIVER_CHANNEL_FUNCTION_C2_TDI                 1
#define PORTDRIVER_CHANNEL_FUNCTION_C3_TDO                 1
#define PORTDRIVER_CHANNEL_FUNCTION_C1_TMS                 1
#define PORTDRIVER_CHANNEL_FUNCTION_B0_U1Rx                1
#define PORTDRIVER_CHANNEL_FUNCTION_A0_U0Rx                1
#define PORTDRIVER_CHANNEL_FUNCTION_A1_U0Tx                1
#define PORTDRIVER_CHANNEL_FUNCTION_F1_U1CTS               1
#define PORTDRIVER_CHANNEL_FUNCTION_F0_U1RTS               1

#define PORTDRIVER_CHANNEL_FUNCTION_A2_SSI0Clk             2
#define PORTDRIVER_CHANNEL_FUNCTION_A3_SSI0Fss             2
#define PORTDRIVER_CHANNEL_FUNCTION_A4_SSI0Rx              2
#define PORTDRIVER_CHANNEL_FUNCTION_A5_SSI0Tx              2
#define PORTDRIVER_CHANNEL_FUNCTION_F2_SSI1Clk             2
#define PORTDRIVER_CHANNEL_FUNCTION_D0_SSI1Clk             2
#define PORTDRIVER_CHANNEL_FUNCTION_F3_SSI1Fss             2
#define PORTDRIVER_CHANNEL_FUNCTION_D1_SSI1Fss             2
#define PORTDRIVER_CHANNEL_FUNCTION_F0_SSI1Rx              2
#define PORTDRIVER_CHANNEL_FUNCTION_D2_SSI1Rx              2
#define PORTDRIVER_CHANNEL_FUNCTION_F1_SSI1Tx              2
#define PORTDRIVER_CHANNEL_FUNCTION_D3_SSI1Tx              2
#define PORTDRIVER_CHANNEL_FUNCTION_B4_SSI2Clk             2
#define PORTDRIVER_CHANNEL_FUNCTION_B5_SSI2Fss             2
#define PORTDRIVER_CHANNEL_FUNCTION_B6_SSI2Rx              2
#define PORTDRIVER_CHANNEL_FUNCTION_B7_SSI2Tx              2
#define PORTDRIVER_CHANNEL_FUNCTION_C4_U1Rx                2
#define PORTDRIVER_CHANNEL_FUNCTION_C5_U1Tx                2

#define PORTDRIVER_CHANNEL_FUNCTION_B2_I2C0SCL             3
#define PORTDRIVER_CHANNEL_FUNCTION_B3_I2C0SDA             3
#define PORTDRIVER_CHANNEL_FUNCTION_A6_I2C1SCL             3
#define PORTDRIVER_CHANNEL_FUNCTION_A7_I2C1SDA             3
#define PORTDRIVER_CHANNEL_FUNCTION_E4_I2C2SCL             3
#define PORTDRIVER_CHANNEL_FUNCTION_E5_I2C2SDA             3
#define PORTDRIVER_CHANNEL_FUNCTION_D0_I2C3SCL             3
#define PORTDRIVER_CHANNEL_FUNCTION_D1_I2C3SDA             3
#define PORTDRIVER_CHANNEL_FUNCTION_F0_CAN0Rx              3
#define PORTDRIVER_CHANNEL_FUNCTION_F3_CAN0Tx              3

#define PORTDRIVER_CHANNEL_FUNCTION_F2_M0FAULT0            4
#define PORTDRIVER_CHANNEL_FUNCTION_D6_M0FAULT0            4
#define PORTDRIVER_CHANNEL_FUNCTION_D2_M0FAULT0            4
#define PORTDRIVER_CHANNEL_FUNCTION_B6_M0PWM0              4
#define PORTDRIVER_CHANNEL_FUNCTION_B7_M0PWM1              4
#define PORTDRIVER_CHANNEL_FUNCTION_B4_M0PWM2              4
#define PORTDRIVER_CHANNEL_FUNCTION_B5_M0PWM3              4
#define PORTDRIVER_CHANNEL_FUNCTION_E4_M0PWM4              4
#define PORTDRIVER_CHANNEL_FUNCTION_E5_M0PWM5              4
#define PORTDRIVER_CHANNEL_FUNCTION_C4_M0PWM6              4
#define PORTDRIVER_CHANNEL_FUNCTION_D0_M0PWM6              4
#define PORTDRIVER_CHANNEL_FUNCTION_C5_M0PWM7              4
#define PORTDRIVER_CHANNEL_FUNCTION_D1_M0PWM7              4

#define PORTDRIVER_CHANNEL_FUNCTION_F4_M1FAULT0            5
#define PORTDRIVER_CHANNEL_FUNCTION_D0_M1PWM0              5
#define PORTDRIVER_CHANNEL_FUNCTION_D1_M1PWM1              5
#define PORTDRIVER_CHANNEL_FUNCTION_A6_M1PWM2              5
#define PORTDRIVER_CHANNEL_FUNCTION_E4_M1PWM2              5
#define PORTDRIVER_CHANNEL_FUNCTION_A7_M1PWM3              5
#define PORTDRIVER_CHANNEL_FUNCTION_E5_M1PWM3              5
#define PORTDRIVER_CHANNEL_FUNCTION_F0_M1PWM4              5
#define PORTDRIVER_CHANNEL_FUNCTION_F1_M1PWM5              5
#define PORTDRIVER_CHANNEL_FUNCTION_F2_M1PWM6              5
#define PORTDRIVER_CHANNEL_FUNCTION_F3_M1PWM7              5

#define PORTDRIVER_CHANNEL_FUNCTION_F0_PhA0                6
#define PORTDRIVER_CHANNEL_FUNCTION_D6_PhA0                6
#define PORTDRIVER_CHANNEL_FUNCTION_C5_PhA1                6
#define PORTDRIVER_CHANNEL_FUNCTION_D7_PhB0                6
#define PORTDRIVER_CHANNEL_FUNCTION_F1_PhB0                6
#define PORTDRIVER_CHANNEL_FUNCTION_C6_PhB1                6
#define PORTDRIVER_CHANNEL_FUNCTION_F4_IDX0                6
#define PORTDRIVER_CHANNEL_FUNCTION_D3_IDX0                6
#define PORTDRIVER_CHANNEL_FUNCTION_C4_IDX1            	   6

#define PORTDRIVER_CHANNEL_FUNCTION_B6_T0CCP0              7
#define PORTDRIVER_CHANNEL_FUNCTION_F0_T0CCP0              7
#define PORTDRIVER_CHANNEL_FUNCTION_B7_T0CCP1              7
#define PORTDRIVER_CHANNEL_FUNCTION_F1_T0CCP1              7
#define PORTDRIVER_CHANNEL_FUNCTION_F2_T1CCP0              7
#define PORTDRIVER_CHANNEL_FUNCTION_B4_T1CCP0              7
#define PORTDRIVER_CHANNEL_FUNCTION_F3_T1CCP1              7
#define PORTDRIVER_CHANNEL_FUNCTION_B5_T1CCP1              7
#define PORTDRIVER_CHANNEL_FUNCTION_F4_T2CCP0              7
#define PORTDRIVER_CHANNEL_FUNCTION_B0_T2CCP0              7
#define PORTDRIVER_CHANNEL_FUNCTION_B1_T2CCP1              7
#define PORTDRIVER_CHANNEL_FUNCTION_B2_T3CCP0              7
#define PORTDRIVER_CHANNEL_FUNCTION_B3_T3CCP1              7
#define PORTDRIVER_CHANNEL_FUNCTION_C0_T4CCP0              7
#define PORTDRIVER_CHANNEL_FUNCTION_C1_T4CCP1              7
#define PORTDRIVER_CHANNEL_FUNCTION_C2_T5CCP0              7
#define PORTDRIVER_CHANNEL_FUNCTION_C3_T5CCP1              7
#define PORTDRIVER_CHANNEL_FUNCTION_C4_WT0CCP0             7
#define PORTDRIVER_CHANNEL_FUNCTION_C5_WT0CCP1             7
#define PORTDRIVER_CHANNEL_FUNCTION_C6_WT1CCP0             7
#define PORTDRIVER_CHANNEL_FUNCTION_C7_WT1CCP1             7
#define PORTDRIVER_CHANNEL_FUNCTION_D0_WT2CCP0             7
#define PORTDRIVER_CHANNEL_FUNCTION_D1_WT2CCP1             7
#define PORTDRIVER_CHANNEL_FUNCTION_D2_WT3CCP0             7
#define PORTDRIVER_CHANNEL_FUNCTION_D3_WT3CCP1             7
#define PORTDRIVER_CHANNEL_FUNCTION_D4_WT4CCP0             7
#define PORTDRIVER_CHANNEL_FUNCTION_D5_WT4CCP1             7
#define PORTDRIVER_CHANNEL_FUNCTION_D6_WT5CCP0             7
#define PORTDRIVER_CHANNEL_FUNCTION_D7_WT5CCP1             7

#define PORTDRIVER_CHANNEL_FUNCTION_C5_U1CTS               8
#define PORTDRIVER_CHANNEL_FUNCTION_C4_U1RTS               8
#define PORTDRIVER_CHANNEL_FUNCTION_F4_USB0EPEN            8
#define PORTDRIVER_CHANNEL_FUNCTION_C6_USB0EPEN            8
#define PORTDRIVER_CHANNEL_FUNCTION_D2_USB0EPEN            8
#define PORTDRIVER_CHANNEL_FUNCTION_C7_USB0PFLT            8
#define PORTDRIVER_CHANNEL_FUNCTION_D3_USB0PFLT            8
#define PORTDRIVER_CHANNEL_FUNCTION_B4_CAN0Rx              8
#define PORTDRIVER_CHANNEL_FUNCTION_E4_CAN0Rx              8
#define PORTDRIVER_CHANNEL_FUNCTION_B5_CAN0Tx              8
#define PORTDRIVER_CHANNEL_FUNCTION_E5_CAN0Tx              8
#define PORTDRIVER_CHANNEL_FUNCTION_A0_CAN1Rx              8
#define PORTDRIVER_CHANNEL_FUNCTION_A1_CAN1Tx              8
#define PORTDRIVER_CHANNEL_FUNCTION_D7_NMI                 8
#define PORTDRIVER_CHANNEL_FUNCTION_F0_NMI                 8

#define PORTDRIVER_CHANNEL_FUNCTION_F0_C0o                 9
#define PORTDRIVER_CHANNEL_FUNCTION_F1_C1o                 9

#define PORTDRIVER_CHANNEL_FUNCTION_F3_TRCLK               14
#define PORTDRIVER_CHANNEL_FUNCTION_F2_TRD0                14
#define PORTDRIVER_CHANNEL_FUNCTION_F1_TRD1                14




typedef uint8_t PortDriver_Channel_ExtIntOperation;
#define PortDriver_Channel_ExtIntOperation_Disable		    0
#define PortDriver_Channel_ExtIntOperation_Enable		    1

typedef uint8_t PortDriver_Channel_ExtINTSense;
#define PortDriver_Channel_INTSense_EdgeSensitive	    	0
#define PortDriver_Channel_INTSense_LevelSensitive			1
#define PortDriver_Channel_Exti_BothEdge	 				2

typedef uint8_t PortDriver_Channel_ExtIntEdgeLevel;
#define PortDriver_Channel_Exti_Falling_Low				    0
#define PortDriver_Channel_Exti_Rising_High			    	1



typedef enum
{
	PortDriver_PortNum_A,
	PortDriver_PortNum_B,
	PortDriver_PortNum_C,
	PortDriver_PortNum_D,
	PortDriver_PortNum_E,
	PortDriver_PortNum_F
}PortDriver_PortNumType;

typedef enum
{
	PortDriver_Channel_A0,
	PortDriver_Channel_A1,
	PortDriver_Channel_A2,
	PortDriver_Channel_A3,
	PortDriver_Channel_A4,
	PortDriver_Channel_A5,
	PortDriver_Channel_A6,
	PortDriver_Channel_A7,
	
	PortDriver_Channel_B0,
	PortDriver_Channel_B1,
	PortDriver_Channel_B2,
	PortDriver_Channel_B3,
	PortDriver_Channel_B4,
	PortDriver_Channel_B5,
	PortDriver_Channel_B6,
	PortDriver_Channel_B7,
	
	PortDriver_Channel_C0,
	PortDriver_Channel_C1,
	PortDriver_Channel_C2,
	PortDriver_Channel_C3,
	PortDriver_Channel_C4,
	PortDriver_Channel_C5,
	PortDriver_Channel_C6,
	PortDriver_Channel_C7,
	
	PortDriver_Channel_D0,
	PortDriver_Channel_D1,
	PortDriver_Channel_D2,
	PortDriver_Channel_D3,
	PortDriver_Channel_D4,
	PortDriver_Channel_D5,
	PortDriver_Channel_D6,
	PortDriver_Channel_D7,
	
	PortDriver_Channel_E0,
	PortDriver_Channel_E1,
	PortDriver_Channel_E2,
	PortDriver_Channel_E3,
	PortDriver_Channel_E4,
	PortDriver_Channel_E5,
	PortDriver_Channel_E6,
	PortDriver_Channel_E7_Reserved,
	
	PortDriver_Channel_F0,
	PortDriver_Channel_F1,
	PortDriver_Channel_F2,
	PortDriver_Channel_F3,
	PortDriver_Channel_F4,
	PortDriver_Channel_F5,
	PortDriver_Channel_F6_Reserved,
	PortDriver_Channel_F7_Reserved,
	
	
}PortDriver_ChannelType;
typedef struct
{
	PortDriver_ChannelType				Channel;
	PortDriver_Channel_DirectionType	PortDriver_Channel_Direction;
	PortDriver_Channel_Current_mAType	PortDriver_Channel_Current_mA;
	PortDriver_Channel_SlewRateType		PortDriver_Channel_SlewRate;
	PortDriver_Channel_AttachmentType	PortDriver_Channel_Attachment;
	PortDriver_Channel_FunctionType		PortDriver_Channel_Function;
	PortDriver_Channel_ExtIntOperation  PortDriver_Channel_IntOperation;
	PortDriver_Channel_ExtINTSense	    PortDriver_Channel_IntSense;
	PortDriver_Channel_ExtIntEdgeLevel  PortDriver_Channel_IntEdgeLevel;
}PortDriver_CfgChannel;


typedef struct
{
	PortDriver_CfgChannel Channels[NUMBER_OF_CONFIGURED_CHANNELS];
}PortDriver_CfgType;
/***************************************************************************/


/************************************APIs***********************************/
void PortDriver_Init(void);
/***************************************************************************/
