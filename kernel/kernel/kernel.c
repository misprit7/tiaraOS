#include <stdio.h>
#include <stdint.h>

#include <kernel/tty.h>

void kernel_main(void) {

	terminal_init();
	printf("Hello from kernel space!\n");

}
