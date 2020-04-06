#include "NVIC.h"
#include "System_Control.h"

int main(void)
{
	NVIC_init();
	SysControl();
	while(1)
	{

	}
}
