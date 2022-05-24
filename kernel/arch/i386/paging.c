
#include <stdint.h>

// Statically allocate with compiler align
uint32_t page_directory[1024] __attribute__((aligned(4096)));
uint32_t first_page_table[1024] __attribute__((aligned(4096)));

// Defined in boot.S
extern void loadPageDirectory(uint32_t*);
extern void enablePaging();

/**
 * @brief Initializes paging directory+pages
 */
void paging_init(void){
	for(int i = 0; i < 1024; ++i){
		page_directory[i] = 0x02;
	}
	for(int i = 0; i < 1024; ++i){
		first_page_table[i] = (i * 0x1000) | 3;
	}

	page_directory[0] = ((unsigned int)first_page_table) | 3;

	loadPageDirectory(page_directory);
	enablePaging();
}

