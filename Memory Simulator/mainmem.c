#include <stdio.h>
#include "memory_system.h"
#include "memory.h"

int main (int arch, char **argv) {
	
	memory_store(100,7);
	printf("%d\n", memory_fetch(100));
	
	memory_store_word(0x78, 0x12345678);
	printf("%x\n", memory_fetch_word(0x78));
	printf("%x\n", memory_fetch(0x78));
	printf("%x\n", memory_fetch(0x7c));
	
	
	//printf("mem_dump\n");
	memory_store(101, 8);
	//printf("memory_fetch %x\n", memory_fetch(101));
	//mem_dump();
	
	//for(int i = 0; i < 200; i++) {
	//	printf("%d %x\n", i, memory_fetch(i));
	//}
	
	memory_fill (100, 45, 5);
	//for (int i = 0; i < 5; i++) {
	//	printf("memory_fetch %d 0x%x\n", i, memory_fetch(100 + i));
	//}
	memory_dump(100,5);
	memory_store_word(12, 0x0a0b0c0d);
	printf("memory_fetch_word(12): 0x%08x\n", memory_fetch_word(12));
	char filename[30];
	printf("Enter a file name:");
	scanf("%s",filename);
	load_memory(filename);
	memory_dump(8,20);
	
	
	
}

