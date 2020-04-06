
#include "Processor.h"

uint8_t level_status;
void Switch_Level(char level)
{
			switch (level)
			{
				case PREVILLIGE:        
						asm("SVC #0");
						level_status=0;
				break;
				
				case UNPREVILLIGE:       
						level_status=1;
						asm("MOVT    R0,#0X01");
						asm("MSR	   CONTROL, R0");
				break;
			}
}


void SVCHandler(void)
{
			if(level_status==1)
			{
				level_status=0;
				asm("MOVT    R0,#0X00");
				asm("MSR	   CONTROL, R0");
			}
}