#include "NVIC.h"

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
			char i;
			
			/*SET THE COMPINATION APINT*(xxx,xxy,xyy...*/
			NVIC_APINT |= ( 0xffff0000 | (0x05FA<<16));
			NVIC_APINT |= ( 0x00000700 | (0x6<<8));  /*xyy*/
			
			for (i=0;i<NUMBER_OF_ACTIVATED_INTERRUPTS;i++)
			{
						temp_interrupt_number=NVIC_INTsConfiguration.Pool[i].interrupt_number;  
						temp_group_priority=NVIC_INTsConfiguration.Pool[i].group_priority;
						temp_subgroup_priority=NVIC_INTsConfiguration.Pool[i].subgroup_priority;
						
						/*ENABLE INTERRUPT USING EN0,EN1...*/
						INT_Enable_Register_Number=temp_interrupt_number/32;   
						if(temp_interrupt_number<32)
						{
							INT_Enable_Bit_Number=temp_interrupt_number;  
						}
						else
						{
							INT_Enable_Bit_Number=temp_interrupt_number%32;     
						}
						INT_register_address=NVIC_EN0+((INT_Enable_Register_Number+1)*4);       /* address of ENT0 is the start address*/
						(*((volatile unsigned long *)INT_register_address))  |=  (1<<INT_Enable_Bit_Number);
						
						/*SET PEIORITY(group and subgroup)USING PR0 ,PR1 ...*/
						Priority_Register_Number=temp_interrupt_number/4;
						Priority_Filed_Number=temp_interrupt_number%4;      /* 0=>A , 1=>B , 3=>C, 4=>D*/
						char temp=((Priority_Register_Number *4)+ Priority_Filed_Number);	 	
						Priority_register_address=NVIC_PRI0+((INT_Enable_Register_Number+1)*4);       /* 0xE000E440 is the address of PRI0*/
						(*((volatile unsigned long *)Priority_register_address))  |=  (temp_subgroup_priority<<((Priority_Filed_Number*8)+5));      
						(*((volatile unsigned long *)Priority_register_address))  |=  (temp_group_priority<<((Priority_Filed_Number*8)+7));               
				}
}