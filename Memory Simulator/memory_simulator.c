#include "memory_system.h"
#include "memory.h"
#include "decoder.h"
#include <stdio.h>

void memory_store(int address, unsigned char b) {
	int lower5 = address & 0x1F;
	int upper5 = (address >> 5) & 0x1F;
	unsigned int row_sel = decoder (lower5);
	unsigned int col_sel = decoder (upper5);
	mem_put (row_sel, col_sel, b);
}

unsigned char memory_fetch(int address) {
	int lower5 = address & 0x1F;
	int upper5 = (address >> 5) & 0x1F;
	unsigned int row_sel = decoder (lower5);
	unsigned int col_sel = decoder (upper5);
	unsigned char b = mem_get (row_sel, col_sel);
	return b;
}

unsigned int memory_fetch_word(int address) {	
	unsigned char b1, b2, b3, b4;
	
	b1 = memory_fetch (address);
	b2 = memory_fetch (address + 1);
	b3 = memory_fetch (address + 2);
	b4 = memory_fetch (address + 3);
	
	return b4 << 24 | b3 << 16 | b2 << 8| b1;
}

void memory_store_word(int address, unsigned int value) {
	unsigned char b1 = value & 0xff;
	unsigned char b2 = (value >> 8) & 0xff;
	unsigned char b3 = (value >> 16) & 0xff;
	unsigned char b4 = (value >> 24) & 0xff;
	
	memory_store(address, b1);
	memory_store(address + 1, b2);
	memory_store(address + 2, b3);
	memory_store(address + 3, b4);
}

void memory_fill(int start_address, unsigned char value, int num_bytes){
	for (int i = 0; i < num_bytes; i ++){
		memory_store(start_address + i, value);
	}
}

void memory_dump(int start_address, int num_bytes) {
	for(int i = 0; i < num_bytes; i++){
		printf("0x%x\n", memory_fetch(start_address+i));
	}
}
void load_memory(char *filename){
	 FILE *fp;
    fp = fopen(filename,"r");
    int value;
    int address= 0;
    fscanf(fp,"%x",&address);
    while (1) {
        if (fscanf(fp, "%x",&value) == EOF) 
            break;
         memory_store_word(address,value);
         address +=4;
        
    }
   
    fclose(fp);
    
    
}


