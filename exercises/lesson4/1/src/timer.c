#include "utils.h"
#include "printf.h"
#include "sched.h"
#include "peripherals/timer.h"

const unsigned int interval = 200000;
unsigned int curVal = 0;

void timer_init(void){
	curVal = get32(TIMER_CL0);
	curVal += interval;
	put32(TIMER_C1, curVal);
}

void handle_timer_irq(void){
	curVal += interval;
	put32(TIMER_C1, curVal);
	put32(TIMER_CS, TIMER_CS_M1);
	printf("\r\nhandle timer irq\r\n");
	timer_tick();
}
