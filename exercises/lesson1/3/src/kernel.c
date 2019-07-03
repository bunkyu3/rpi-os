#include "mini_uart.h"
#include "utils.h"

void kernel_main(void){
	unsigned long id;
	id = getcpuid();

	if(id == 0){
		uart_init();
	}else{
		delay(100000*id);
	}
	uart_send_string("Hello, from processor ");
	uart_send((char)id+0x30);
	uart_send_string("\r\n");

	if(id == 0){
		while(1){
			uart_send(uart_recv());
		}
	}else{
		while(1){}
	}
}
