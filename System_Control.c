
#include "System_Control.h"

/*PLEASE NOTE THAT :  not all fruqencies are provided here in this version but the sample fruqencies here covers all branches
                                      also note that I let the magic numbers here just to make it easier for you to understand the code*/
void  SysControl(void)
{
	
			/* setting the "USERCC2" filed to write ion the RCC2 register */ 
			RCC2 |= (1<<USERCC2);
		
			switch(frequency)
			{
					/*if the internal OSC supports the choosen freq*/
					case FREQUENCY_16M:
							RCC2 |= (1<<OSCSRC2_1) ;     			         /* 1  => internal oscillator*/
					break;

					case FREQUENCY_4M:
							RCC2 |= (1<<OSCSRC2_2) ;                 /* 2  => internal oscillator/4*/
					break;

					/*if the internal OSC dos'nt supports the choosen freq*/
					case FREQUENCY_44M:
							RCC2 = 0;                                /* 0  => main oscillator */ 

							RCC2 |= (1<<DIV400) ;          /* 0  => main oscillator*/ 
															                                	/* 1   => append the "SYSDIV2LSB" to the "SYSDIV2"*/ 
							RCC2 |= (0x1F000000) & (0x03<<24);
					break;

					case FREQUENCY_40M:
							RCC2 = 0;                                 /* 0  => main oscillator */ 
					
							RCC2 |= (1<<DIV400) ;          /* 0  => main oscillator*/ 
												                                 				/* 1   => append the "SYSDIV2LSB" to the "SYSDIV2"*/ 
							RCC2 |= (0x1F000000) & (0x03<<24);
							RCC2 |= (1<<SYSDIV2LSB) ; 
					break;
			}
			
	
}