/*
 ============================================================================
 Name        : DIO.h
 Author      : Muhammed Gamal
 Description : 
 ============================================================================
 */



/*********************************includes**********************************/
#include "std_types.h"
/***************************************************************************/

/***************************types and definitions***************************/
typedef enum
{
    STD_low=0,
    STD_high=!STD_low
}STD_levelType;

typedef enum
{
    Dio_Channel_A0,
    Dio_Channel_A1,
    Dio_Channel_A2,
    Dio_Channel_A3,
    Dio_Channel_A4,
    Dio_Channel_A5,
    Dio_Channel_A6,
    Dio_Channel_A7,

    Dio_Channel_B0,
    Dio_Channel_B1,
    Dio_Channel_B2,
    Dio_Channel_B3,
    Dio_Channel_B4,
    Dio_Channel_B5,
    Dio_Channel_B6,
    Dio_Channel_B7,


    Dio_Channel_C0,
    Dio_Channel_C1,
    Dio_Channel_C2,
    Dio_Channel_C3,
    Dio_Channel_C4,
    Dio_Channel_C5,
    Dio_Channel_C6,
    Dio_Channel_C7,


    Dio_Channel_D0,
    Dio_Channel_D1,
    Dio_Channel_D2,
    Dio_Channel_D3,
    Dio_Channel_D4,
    Dio_Channel_D5,
    Dio_Channel_D6,
    Dio_Channel_D7,

    Dio_Channel_E0,
    Dio_Channel_E1,
    Dio_Channel_E2,
    Dio_Channel_E3,
    Dio_Channel_E4,
    Dio_Channel_E5,
    Dio_Channel_E6_NA,
    Dio_Channel_E7_NA,

    Dio_Channel_F0,
    Dio_Channel_F1,
    Dio_Channel_F2,
    Dio_Channel_F3,
    Dio_Channel_F4

}Dio_ChannelType;

typedef enum
{
    Dio_Port_A,
    Dio_Port_B,
    Dio_Port_C,
    Dio_Port_D,
    Dio_Port_E,
    Dio_Port_F
}Dio_PortType;

/***************************************************************************/

/******************************global variables*****************************/

/***************************************************************************/

/***********************************APIs************************************/
void Dio_WritePort(Dio_PortType PortId, uint8_t Data);
void Dio_ReadPort(Dio_PortType PortId, uint8_t *Data);
void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level);
void Dio_ReadChannel(Dio_ChannelType ChannelId,STD_levelType *Data);
void Dio_FlipChannel( Dio_ChannelType ChannelId);
/***************************************************************************/
