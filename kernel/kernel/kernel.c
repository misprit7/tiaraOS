#include <stdio.h>
#include <stdint.h>

#include <kernel/tty.h>
#include <kernel/paging.h>

void kernel_main(void) {

	paging_init();
	terminal_init();
	printf("Hello, kernel World!\n");
}
