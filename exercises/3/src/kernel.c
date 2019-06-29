#include "mini_uart.h"
#include "utils.h"

void kernel_main(void){
	uart_init();

	unsigned long id;
	id = getcpuid();
	uart_send_string("Hello, from processor ");
	uart_send((char)id+0x30);
	uart_send_string("\r\n");

	while(1){
		uart_send(uart_recv());
	}
}

