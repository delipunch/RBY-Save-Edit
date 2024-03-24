#include <stdio.h>
#include <stdint.h>
#include <gb/gb.h>

//char *saved = (char *)0xa000; // Pointer to memory address - ingore, from template

uint16_t *num1 = (uint16_t *)0xA605; // address for TID in Cart RAM, Bank 1
uint8_t *num2 = (uint8_t *)0xAF2C; // address for the count of party Pokemon in Cart RAM, Bank 1

void main()

{	
	ENABLE_RAM; // Enable RAM
	
	SWITCH_RAM(1); // Switch to RAM Bank 1, the main bank for save data
	printf("Value 0xA605:\n%u\n\n", num1[0]);
	printf("Value 0xAF37:\n%u\n\n", num2[0]);
	
	DISABLE_RAM; // Disable RAM
}