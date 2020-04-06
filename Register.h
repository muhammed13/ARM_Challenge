
/***********************************NVIC*************************************************/
#define NVIC_APINT                        (*((volatile unsigned long*)0xE000ED0C))
#define NVIC_EN0                           (*((volatile unsigned long *)0xE000E100))
#define NVIC_PRI0                          (*((volatile unsigned long *)0xE000E400))  
	
/****************************************************************************************/



/*******************************System Control***************************************/
#define RCC2                       (*((volatile unsigned long*)0x400FE070))
	            /***********************RCC2 BIits************************/
#define USERCC2                            31
#define OSCSRC2_1                         4
#define OSCSRC2_2                         5
#define OSCSRC2_3                         3
#define DIV400                                 30
#define SYSDIV2LSB                        22
	
/****************************************************************************************/