#include "NVIC.h"
#include "System_Control.h"
#include "processor.h"
int main(void)
{
		NVIC_init();
		SysControl();
	  Switch_Level(UNPREVILLIGE);
		while(1)
		{

		}
}