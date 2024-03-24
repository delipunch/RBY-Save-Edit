#include <stdio.h>
#include <stdint.h>
#include <gb/gb.h>
#include "functions.h"
#include "pokemon_constants.h"

#define TID 0xA605

//uint16_t *num1 = (uint16_t *)0xA605; // address for TID in Cart RAM, Bank 1
//uint8_t *num2 = (uint8_t *)0xAF2C; // address for the count of party Pokemon in Cart RAM, Bank 1

void main()
{	
	ENABLE_RAM; // Enable RAM
	
	SWITCH_RAM(1); // Switch to RAM Bank 1, the main bank for save data
	
	printf("Trainer ID:\n%u\n\n", read16(0xA605));
	printf("Party Count:\n%u\n", read8(0xAF2C));
	printf("1st Pokemon Species:%s\n", species_index[read8(0xAF2D)]);
	printf("1st Pokemon XP:\n%u\n", read24(0xAF42));
	printf("2nd Pokemon Species:%s\n", species_index[read8(0xAF2E)]);
	printf("2nd Pokemon XP:\n%u\n", read24(0xAF6E));
	printf("3rd Pokemon Species:%s\n", species_index[read8(0xAF2F)]);
	printf("3rd Pokemon XP:\n%u\n", read24(0xAF9A));
	
	DISABLE_RAM; // Disable RAM
}