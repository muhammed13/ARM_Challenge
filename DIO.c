/*
 ============================================================================
 Name        : DIO.c
 Author      : Muhammed Gamal
 Description : 
 ============================================================================
 */

/*********************************includes**********************************/
#include "DIO.h"
/***************************************************************************/


/*********************************definitions*******************************/
#define PORTA_APB_BASE_ADD                 0x40004000
#define PORTB_APB_BASE_ADD                 0x40005000
#define PORTC_APB_BASE_ADD                 0x40006000
#define PORTD_APB_BASE_ADD                 0x40007000
#define PORTE_APB_BASE_ADD                 0x40024000
#define PORTF_APB_BASE_ADD                 0x40025000
#define GPIODATA_REG_OFFSET                0x000 

#define INITIAL_VALUE                      0
#define NUM_OF_BINS_PER_PORT               8
#define CLEAR                              0
/***************************************************************************/


/******************************global variables*****************************/

/***************************************************************************/


/****************************local functions APIs***************************/
static void GetChannelInfo(Dio_ChannelType ChannelId , uint8_t *PortNum, uint8_t *PinNum, uint32_t *BaseAdd);
static void GetBaseAdd(Dio_PortType PortNum, uint32_t *BaseAdd);
/***************************************************************************/


void Dio_WritePort(Dio_PortType PortId, uint8_t Data)
{
	uint32_t *au32_DataReg;
	uint32_t au32_Base_Add;
	GetBaseAdd(PortId, &au32_Base_Add);
	au32_DataReg = (uint32_t*)(au32_Base_Add+GPIODATA_REG_OFFSET);
	*au32_DataReg = Data;
}


void Dio_ReadPort(Dio_PortType PortId, uint8_t *Data)
{
	uint32_t *au32_DataReg;
	uint32_t au32_Base_Add;
	GetBaseAdd(PortId, &au32_Base_Add);
	au32_DataReg = (uint32_t*)(au32_Base_Add+GPIODATA_REG_OFFSET);
	*Data = *au32_DataReg;
}


void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level)
{
	uint32_t *au32_DataReg;
	uint32_t au32_Base_Add;
	uint8_t au8_port_num;
	uint8_t au8_pin_num;
	GetChannelInfo(ChannelId , &au8_port_num, &au8_pin_num, &au32_Base_Add);
	au32_DataReg = (uint32_t*)(au32_Base_Add+GPIODATA_REG_OFFSET);
	if(Level == STD_low)
	{
		*au32_DataReg &= ~(1<<au8_pin_num);
	}
	else
	{
		*au32_DataReg |= (1<<au8_pin_num);
	}
}


void Dio_ReadChannel(Dio_ChannelType ChannelId,STD_levelType *Data)
{
	uint32_t *au32_DataReg;
	uint32_t au32_Base_Add;
	uint8_t au8_port_num;
	uint8_t au8_pin_num;
	GetChannelInfo(ChannelId , &au8_port_num, &au8_pin_num, &au32_Base_Add);
	au32_DataReg = (uint32_t*)(au32_Base_Add+GPIODATA_REG_OFFSET);
	*Data = ((*au32_DataReg) & (1<<au8_pin_num));
}


void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
	uint32_t *au32_DataReg;
	uint32_t au32_Base_Add;
	uint8_t au8_port_num;
	uint8_t au8_pin_num;
	GetChannelInfo(ChannelId , &au8_port_num, &au8_pin_num, &au32_Base_Add);
	*au32_DataReg ^= (1<<au8_pin_num);
}


static void GetChannelInfo(Dio_ChannelType ChannelId , uint8_t *PortNum, uint8_t *PinNum, uint32_t *BaseAdd)
{
	*PortNum = ChannelId / NUM_OF_BINS_PER_PORT;
	*PinNum = ChannelId % NUM_OF_BINS_PER_PORT;
	
	switch(*PortNum)
	{
	case Dio_Port_A:
		*BaseAdd=PORTA_APB_BASE_ADD;
	break;
	case Dio_Port_B:
		*BaseAdd=PORTB_APB_BASE_ADD;
	break;
	case Dio_Port_C:
		*BaseAdd=PORTC_APB_BASE_ADD;
	break;
	case Dio_Port_D:
		*BaseAdd=PORTD_APB_BASE_ADD;
	break;
	case Dio_Port_E:
		*BaseAdd=PORTE_APB_BASE_ADD;
	break;
	case Dio_Port_F:
		*BaseAdd=PORTF_APB_BASE_ADD;
	break;
	}
}


static void GetBaseAdd(Dio_PortType PortNum, uint32_t *BaseAdd)
{
	switch(PortNum)
	{
	case Dio_Port_A:
		*BaseAdd=PORTA_APB_BASE_ADD;
	break;
	case Dio_Port_B:
		*BaseAdd=PORTB_APB_BASE_ADD;
	break;
	case Dio_Port_C:
		*BaseAdd=PORTC_APB_BASE_ADD;
	break;
	case Dio_Port_D:
		*BaseAdd=PORTD_APB_BASE_ADD;
	break;
	case Dio_Port_E:
		*BaseAdd=PORTE_APB_BASE_ADD;
	break;
	case Dio_Port_F:
		*BaseAdd=PORTF_APB_BASE_ADD;
	break;
	}
}