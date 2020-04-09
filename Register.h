/*
 ============================================================================
 Name        : GPIO_Cfg.c
 Author      : Muhammed Gamal
 Description :
 ============================================================================
 */

/*********************************includes**********************************/
#include "std_types.h"
/***************************************************************************/


/***********************************NVIC*************************************************/
#define NVIC_APINT                         (*((volatile uint32_t*)0xE000ED0C))
#define NVIC_EN0                           (*((volatile uint32_t*)0xE000E100))
#define NVIC_PRI0                          (*((volatile uint32_t*)0xE000E400))

/*******************************System Control***************************************/
#define RCC2                               (*((volatile uint32_t*)0x400FE070))
/*******RCC2 BIits********/
#define USERCC2                            31
#define OSCSRC2_1                          4
#define OSCSRC2_2                          5
#define OSCSRC2_3                          3
#define DIV400                             30
#define SYSDIV2LSB                         22


/****************************************GPIO******************************************/
#define RCGCGPIO                           (*((volatile uint32_t*)0x400FE608))
#define PORTA_GPIODIR                      (*((volatile uint32_t*)0x40004400))
#define PORTB_GPIODIR                      (*((volatile uint32_t*)0x40005400))
#define PORTC_GPIODIR                      (*((volatile uint32_t*)0x40006400))
#define PORTD_GPIODIR                      (*((volatile uint32_t*)0x40007400))
#define PORTE_GPIODIR                      (*((volatile uint32_t*)0x40024400))
#define PORTF_GPIODIR                      (*((volatile uint32_t*)0x40025400))

#define PORTA_GPIOAFSEL                    (*((volatile uint32_t*)0x40004420))
#define PORTB_GPIOAFSEL                    (*((volatile uint32_t*)0x40005420))
#define PORTC_GPIOAFSEL                    (*((volatile uint32_t*)0x40006420))
#define PORTD_GPIOAFSEL                    (*((volatile uint32_t*)0x40007420))
#define PORTE_GPIOAFSEL                    (*((volatile uint32_t*)0x40024420))
#define PORTF_GPIOAFSEL                    (*((volatile uint32_t*)0x40025420))
/****************************************************************************************/
