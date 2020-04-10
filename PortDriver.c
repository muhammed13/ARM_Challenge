/*
 ============================================================================
 Name        : PortDriver.c
 Author      : Muhammed Gamal
 Description : 
 ============================================================================
 */


/*********************************includes**********************************/
#include "PortDriver.h"
/***************************************************************************/


/*********************************definitions*******************************/
#define NUM_OF_BINS_PER_PORT               8
#define PORTA_APB_BASE_ADD                 0x40004000
#define PORTB_APB_BASE_ADD                 0x40005000
#define PORTC_APB_BASE_ADD                 0x40006000
#define PORTD_APB_BASE_ADD                 0x40007000
#define PORTE_APB_BASE_ADD                 0x40024000
#define PORTF_APB_BASE_ADD                 0x40025000
#define GPIODIR_REG_OFFSET                 0x400
#define GPIOAFSEL_REG_OFFSET               0x420
#define GPIOPCTL_REG_OFFSET                0x52C
#define GPIOLOCK_REG_OFFSET                0x520
#define GPIOCR_REG_OFFSET                  0x524
#define GPIODEN_REG_OFFSET                 0x51C
#define GPIOPDR_REG_OFFSET                 0x514
#define GPIOPUR_REG_OFFSET                 0x510
#define GPIODR2R_REG_OFFSET                0x500
#define GPIODR4R_REG_OFFSET                0x504
#define GPIODR8R_REG_OFFSET                0x508
#define GPIOSLR_REG_OFFSET                 0x518
#define GPIOODR_REG_OFFSET                 0x50C
#define GPIOPUR_REG_OFFSET                 0x510
#define GPIOPDR_REG_OFFSET                 0x514
#define GPIOIM_REG_OFFSET                  0x410
#define GPIOIM_REG_OFFSET                  0x410
#define GPIOIS_REG_OFFSET                  0x404
#define GPIOIBE_REG_OFFSET                 0x408
#define GPIOIEV_REG_OFFSET                 0x40C

#define INPUT                              0
#define INITIAL_VALUE                      0
#define GPIOPCTL_FIELD_SIZE                4
#define REGISTER_SIZE                      4
#define GPIOLOCK_ENABLE_VALUE              0x4C4F434B
#define ZERO_MASK                          0x00000000
#define CLEAR                              0
/***************************************************************************/


/******************************global variables*****************************/
extern const PortDriver_CfgType Port_Configuration;
/***************************************************************************/


void PortDriver_Init(void)
{
	uint8_t au8_loop_counter;
	uint8_t au8_channel_num;
	uint8_t au8_channel_dir;
	uint8_t au8_channel_port;
	uint8_t au8_channel_function;
	uint8_t au8_channel_current;
	uint8_t au8_channel_slew_rate;
	uint8_t au8_channel_attachment;
	uint8_t au8_channel_interrupt_operation;
	uint8_t au8_channel_interrupt_sensitivity;
	uint8_t au8_channel_interrupt_edgelevel;
	uint32_t au32_Base_Add;
	uint32_t *au32_GPIODIR_Reg;
	uint32_t *au32_GPIOAFSEL_Reg;
	uint32_t *au32_GPIOPCTL_Reg;
	uint32_t *au32_GPIOLOCK_Reg;
	uint32_t *au32_GPIOCR_Reg;
	uint32_t *au32_GPIODEN_Reg;
	uint32_t *au32_GPIOODR_Reg;
	uint32_t *au32_GPIOPUR_Reg;
	uint32_t *au32_GPIOPDR_Reg;
	uint32_t *au32_GPIODRXR_Reg;
	uint32_t *au32_GPIOSLR_Reg;
	uint32_t *au32_GPIOAttachmet_Reg;
	uint32_t *au32_GPIOIM_Reg;
	uint32_t *au32_GPIOINTSENS_Reg;
	uint32_t *au32_GPIOIEV_Reg;
	uint8_t au8_GPIOAFSEL_Field;

	au32_GPIOAFSEL_Reg = (uint32_t*)(au32_Base_Add+GPIOAFSEL_REG_OFFSET);
	au32_GPIOPCTL_Reg = (uint32_t*)(au32_Base_Add+GPIOPCTL_REG_OFFSET);
	au32_GPIOLOCK_Reg = (uint32_t*)(au32_Base_Add+GPIOLOCK_REG_OFFSET);
	au32_GPIODEN_Reg = (uint32_t*)(au32_Base_Add+GPIODEN_REG_OFFSET);
	au32_GPIOODR_Reg = (uint32_t*)(au32_Base_Add+GPIOPDR_REG_OFFSET);
	au32_GPIOPUR_Reg = (uint32_t*)(au32_Base_Add+GPIOPUR_REG_OFFSET);
	au32_GPIOPDR_Reg = (uint32_t*)(au32_Base_Add+GPIOPDR_REG_OFFSET);
	au32_GPIOSLR_Reg = (uint32_t*)(au32_Base_Add+GPIOSLR_REG_OFFSET);
	au32_GPIOIM_Reg = (uint32_t*)(au32_Base_Add+GPIOIM_REG_OFFSET);
	au32_GPIOIEV_Reg = (uint32_t*)(au32_Base_Add+GPIOIEV_REG_OFFSET);

	for(au8_loop_counter=INITIAL_VALUE;au8_loop_counter<NUMBER_OF_CONFIGURED_CHANNELS;au8_loop_counter++)
	{
		au8_channel_num = Port_Configuration.Channels[au8_loop_counter].Channel;
		au8_channel_dir = (Port_Configuration.Channels[au8_loop_counter].PortDriver_Channel_Direction);
		au8_channel_port = au8_channel_num/NUM_OF_BINS_PER_PORT;
		au8_channel_function = Port_Configuration.Channels[au8_loop_counter].PortDriver_Channel_Function;
		au8_channel_current = Port_Configuration.Channels[au8_loop_counter].PortDriver_Channel_Current_mA;
		au8_channel_slew_rate = Port_Configuration.Channels[au8_loop_counter].PortDriver_Channel_SlewRate;
		au8_channel_attachment = Port_Configuration.Channels[au8_loop_counter].PortDriver_Channel_Attachment;
		au8_channel_interrupt_operation = Port_Configuration.Channels[au8_loop_counter].PortDriver_Channel_IntOperation;
		au8_channel_interrupt_sensitivity = Port_Configuration.Channels[au8_loop_counter].PortDriver_Channel_IntSense;
		au8_channel_interrupt_edgelevel = Port_Configuration.Channels[au8_loop_counter].PortDriver_Channel_IntEdgeLevel;
		switch(au8_channel_port)
		{
		case PortDriver_PortNum_A:
			au32_Base_Add=PORTA_APB_BASE_ADD;
		break;
		case PortDriver_PortNum_B:
			au32_Base_Add=PORTB_APB_BASE_ADD;
		break;
		case PortDriver_PortNum_C:
			au32_Base_Add=PORTC_APB_BASE_ADD;
		break;
		case PortDriver_PortNum_D:
			au32_Base_Add=PORTD_APB_BASE_ADD;
		break;
		case PortDriver_PortNum_E:
			au32_Base_Add=PORTE_APB_BASE_ADD;
		break;
		case PortDriver_PortNum_F:
			au32_Base_Add=PORTF_APB_BASE_ADD;
		break;
		}

		*au32_GPIOLOCK_Reg = GPIOLOCK_ENABLE_VALUE; /*enable write access to GPIOCR*/
		*au32_GPIOCR_Reg |= (1<<au8_channel_num);  /*enable write access to GPIOAFSEL, GPIODEN, GPIOPDR, GPIOPUR and GPIOPCTL*/

		/*---Enable the clock for a dedicated port---*/
		RCGCGPIO |= (1<<au8_channel_port);

		/*---Set the direction of the pin---*/
		au32_GPIODIR_Reg = (uint32_t*)(au32_Base_Add+GPIODIR_REG_OFFSET);
		if(au8_channel_dir==INPUT)
		{
			*au32_GPIODIR_Reg &= ~(1<<au8_channel_num);
		}
		else
		{
			*au32_GPIODIR_Reg |= (1<<au8_channel_num);
		}

		/*---Set the functionality of the pin---*/
		if(au32_GPIOAFSEL_Reg==PortDriver_Channel_Function_X_DIO)
		{
			*au32_GPIOAFSEL_Reg &= ~(1<<au8_channel_num);
		}
		else
		{
			*au32_GPIOAFSEL_Reg |= (1<<au8_channel_num);
			*au32_GPIOPCTL_Reg |= ((ZERO_MASK | au8_channel_function)<<(au8_channel_num*GPIOPCTL_FIELD_SIZE));
		}

		/*---Set the current of the pin---*/
		au32_GPIODRXR_Reg = (uint32_t*)(au32_Base_Add+GPIODR2R_REG_OFFSET+(au8_channel_current*REGISTER_SIZE));
		*au32_GPIODRXR_Reg |= (1<<au8_channel_num);

		/*---Set the slew rate for the pin---*/
		if(au8_channel_slew_rate==PortDriver_Channel_SlewRate_Disable)
		{
			*au32_GPIOSLR_Reg &= ~(1<<au8_channel_num);
		}
		else
		{
			*au32_GPIOSLR_Reg |= (1<<au8_channel_num);
		}

		/*---Set the attachment for the pin---*/
		if(au8_channel_attachment==PortDriver_Channel_Attachment_NotConnected)
		{
			/*clear GPIOODR, GPIOPUR and GPIOPDR register*/
			*au32_GPIOODR_Reg &= ~(1<<au8_channel_num);
			*au32_GPIOPUR_Reg &= ~(1<<au8_channel_num);
			*au32_GPIOPDR_Reg &= ~(1<<au8_channel_num);
		}
		else
		{
			au32_GPIOAttachmet_Reg = (uint32_t*)(au32_Base_Add+GPIOODR_REG_OFFSET+((au8_channel_attachment-1)*REGISTER_SIZE));
			*au32_GPIOAttachmet_Reg |= (1<<au8_channel_num);
		}

		/*---external interrupts---*/
		/*---set the interrupt operation of the pin---*/
		if(au8_channel_interrupt_operation==PortDriver_Channel_ExtIntOperation_Disable)
		{
			*au32_GPIOIM_Reg &= ~(1<<au8_channel_num);
		}
		else
		{
			*au32_GPIOIM_Reg |= (1<<au8_channel_num);
		}

		/*---set the interrupt sensitivity of the pin---*/
		if(au8_channel_interrupt_sensitivity==PortDriver_Channel_INTSense_EdgeSensitive)
		{
			au32_GPIOINTSENS_Reg = (uint32_t*)(au32_Base_Add+GPIOIS_REG_OFFSET);
			*au32_GPIOINTSENS_Reg &= ~(1<<au8_channel_num);
		}
		else
		{
			au32_GPIOINTSENS_Reg = (uint32_t*)(au32_Base_Add+GPIOIS_REG_OFFSET+((au8_channel_interrupt_sensitivity-1)*REGISTER_SIZE));
			*au32_GPIOINTSENS_Reg |= (1<<au8_channel_num);
		}

		/*---set the interrupt with dedicated edge or level of the pin---*/
		if(au8_channel_interrupt_edgelevel==PortDriver_Channel_Exti_Falling_Low)
		{
			*au32_GPIOIEV_Reg &= ~(1<<au8_channel_num);
		}
		else
		{
			*au32_GPIOIEV_Reg |= (1<<au8_channel_num);
		}

		/*--accessing disable--*/
		*au32_GPIOCR_Reg &= ~(1<<au8_channel_num);  /*disable write access to GPIOAFSEL, GPIODEN, GPIOPDR, GPIOPUR and GPIOPCTL*/
		*au32_GPIOLOCK_Reg = CLEAR; /*disable write access to GPIOCR*/
	}

}
