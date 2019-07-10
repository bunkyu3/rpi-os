#include "utils.h"
#include "printf.h"
#include "peripherals/local_timer.h"

void local_timer_init(void){
	unsigned int interval = 800;
	put32(LOCAL_TIMER_CTRL, LOCAL_TIMER_CTRL_23bit|LOCAL_TIMER_CTRL_PRESCALE256| \
							LOCAL_TIMER_CTRL_ENABLE|LOCAL_TIMER_CTRL_INT_ENABLE);
	put32(LOCAL_TIMER_LOAD, interval);
}

void handle_local_timer_irq(void){
	printf("Local timer interrupt received\r\n");
	put32(LOCAL_TIMER_IRQ_CLEAR, 0);
}
