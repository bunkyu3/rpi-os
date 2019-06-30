#include "printf.h"
#include "utils.h"
#include "mini_uart.h"

void kernel_main(void){
	uart_init();
	init_printf(0, putc);

	int a = 1;
	printf("printf test: %d \r\n", a);

	while(1){
		uart_send(uart_recv());
	}
}

