#include "NVIC.h"


/*PLEASE NOTE THAT: I let all magic numbers in this version as it's just to make it easier for you to understand the code*/


extern NVIC_ConfigType NVIC_INTsConfiguration;

void NVIC_init(void)
{
	uint8_t temp_interrupt_number;
	uint8_t temp_group_priority;
	uint8_t temp_subgroup_priority;
	uint8_t INT_Enable_Register_Number;
	uint8_t INT_Enable_Bit_Number;
	uint8_t Priority_Register_Number;
	uint8_t Priority_Filed_Number;
	uint32_t INT_register_address;
	uint32_t Priority_register_address;
	uint8_t i;

	/*SET THE COMPINATION APINT*(xxx,xxy,xyy...*/
	NVIC_APINT |= ( 0xffff0000 | (0x05FA<<16)) | ( 0x00000700 | (0x6<<8)); /*this  field must be written to this value in order to change the bits in this register*/
														                   /*set the priority compination to be xyy (goup subgroup subgroup)*/

	for (i=0;i<NUMBER_OF_ACTIVATED_INTERRUPTS;i++)
	{
	   /* save each interrupt information in a temporary variables */
		temp_interrupt_number=NVIC_INTsConfiguration.Pool[i].interrupt_number;
		temp_group_priority=NVIC_INTsConfiguration.Pool[i].group_priority;
		temp_subgroup_priority=NVIC_INTsConfiguration.Pool[i].subgroup_priority;

		/*ENABLE INTERRUPT USING EN0,EN1...*/
		INT_Enable_Register_Number=temp_interrupt_number/32;   /*divide by 32 since each register have 32 interrupt enable bit for 32 interrupt*/
		if(temp_interrupt_number<32)
		{
			  /*if the interrupt locates at the first register*/
				INT_Enable_Bit_Number=temp_interrupt_number;
		}
		else
		{
			   /*if the interrupt dos'nt locate at the first register */
				INT_Enable_Bit_Number=temp_interrupt_number%32;
		}
		/* to find the register address => I added the  address of ENT0  which is the start address here to enable register number multiplied by 4
		*  since the registers size is 4bytes. I added one because the First register number is zero*/
		INT_register_address=NVIC_EN0+((INT_Enable_Register_Number+1)*4);
		(*((volatile uint32_t *)INT_register_address))  |=  (1<<INT_Enable_Bit_Number);    /*set the interrupt enable bit by 1*/

		/*SET PEIORITY(group and subgroup)USING PR0 ,PR1 ...*/
		Priority_Register_Number=temp_interrupt_number/4;  /*divide by 4 since each register has four interrupts*/
		Priority_Filed_Number=temp_interrupt_number%4;      /* determine whhich field (0=>A , 1=>B , 3=>C, 4=>D)*/
		Priority_register_address=NVIC_PRI0+((INT_Enable_Register_Number+1)*4);       /* same as how I get the INT_register_address*/
		/*set the priority register by the subgroup priority value shifted by the priority field number mulltiplied by 8 difference between the start of a field and the start of
		* the next field is 8 bits. and I added 5 since the first field in the register started at bit 5*/
		(*((volatile uint32_t *)Priority_register_address))  |=  (temp_subgroup_priority<<((Priority_Filed_Number*8)+5));
		(*((volatile uint32_t *)Priority_register_address))  |=  (temp_group_priority<<((Priority_Filed_Number*8)+7));  /*I added 7 here instead of 5 since first group priority bit is  bit 7*/
	}
}
