
#include "NVIC_Lcfg.h"
#include "Register.h"
#include "std_types.h"
/********************DEFINITIONS*********************/

#define NVIC_INT0       0
#define NVIC_INT1       1
#define NVIC_INT2       2
/****************************************************/

typedef struct
{
			uint8_t interrupt_number;
			uint8_t group_priority;
			uint8_t subgroup_priority;
			/*compination parameter*/       /*this parameter will be added later*/
} NVIC_ConfigChannel;

typedef struct
{
			NVIC_ConfigChannel Pool[NUMBER_OF_ACTIVATED_INTERRUPTS];
} NVIC_ConfigType;



void NVIC_init(void);