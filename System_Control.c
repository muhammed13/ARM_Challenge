
#include "System_Control.h"

void  SysControl(void)
{
	
			/* setting the "USERCC2" filed to write ion the RCC2 register */ 
			RCC2 |= (1<<USERCC2);
		
			switch(frequency)
			{
					/*if the internal OSC supports the choosen freq*/
					case 16000000:
							RCC2 |= (1<<OSCSRC2_1) ;     			         /* 1  => internal oscillator*/
					break;

					case 4000000:
							RCC2 |= (1<<OSCSRC2_2) ;                 /* 2  => internal oscillator/4*/
					break;

					/*if the internal OSC dos'nt supports the choosen freq*/
					case 44000000:
							RCC2 = 0;                                /* 0  => main oscillator */ 

							RCC2 |= (1<<DIV400) ;          /* 0  => main oscillator*/ 
															                                	/* 1   => append the "SYSDIV2LSB" to the "SYSDIV2"*/ 
							RCC2 |= (0x1F000000) & (0x03<<24);
					break;

					case 40000000:
							RCC2 = 0;                                 /* 0  => main oscillator */ 
					
							RCC2 |= (1<<DIV400) ;          /* 0  => main oscillator*/ 
												                                 				/* 1   => append the "SYSDIV2LSB" to the "SYSDIV2"*/ 
							RCC2 |= (0x1F000000) & (0x03<<24);
							RCC2 |= (1<<SYSDIV2LSB) ; 
					break;
			}
			
	
}