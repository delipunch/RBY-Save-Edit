#include <stdio.h>
#include <stdint.h>
#include <gb/gb.h>
#include "functions.h"
#include "pokemon_constants.h"
#include "pokemon_defines.h"

uint8_t monBuffer[partyMonLengthGen1];

void main()
{	
	//while (true)
	//{
		ENABLE_RAM; // Enable RAM
		
		SWITCH_RAM(1); // Switch to RAM Bank 1, the main bank for save data
		
		uint8_t* saveChecksum = 0xB523;
		
		printf("Read checksum:\n%hx\n",read8(saveChecksum));
		printf("\nCalc checksum:\n%hx\n",checksumBank(1));
		
		DISABLE_RAM;
		
		/*
			printf("Trainer ID:\n %u\n\n ", read16(0xA605));
			printf("Party Count:\n %u\n", read8(0xAF2C));
			printf("1st Pokemon Species:%s\n ", species_index[read8(0xAF2D)]);
			printf("1st Pokemon XP:\n %u\n", read24(0xAF42));
			printf("2nd Pokemon Species:%s\n ", species_index[read8(0xAF2E)]);
			printf("2nd Pokemon XP:\n %u\n", read24(0xAF6E));
			printf("3rd Pokemon Species:%s\n ", species_index[read8(0xAF2F)]);
			printf("3rd Pokemon XP:\n %u\n", read24(0xAF9A));
		*/
		/*
		printf("1st Pokemon Data\n\n\n");
		printf("1st Pokemon Species: %s\n", species_index[read8(0xAF34)]);
		printf("1st Pokemon Cur HP:\n %u\n", read16(0xAF35));
		printf("1st Pokemon Level:\n %u\n", read8(0xAF37));
		printf("1st Pokemon Status:\n %u\n", read8(0xAF38));
		printf("1st Pokemon Type 1:\n %u\n", read8(0xAF39));
		printf("1st Pokemon Type 2:\n %u\n", read8(0xAF3A));
		printf("1st Pokemon Item:\n %u\n", read8(0xAF3B));
		DISABLE_RAM;
		
		waitpad(J_A);
		waitpadup();
		
		ENABLE_RAM;
		SWITCH_RAM(1);
		printf("1st Pokemon Move 1:\n %s\n", move_index[read8(0xAF3C)]);
		printf("1st Pokemon Move 2:\n %s\n", move_index[read8(0xAF3D)]);
		printf("1st Pokemon Move 3:\n %s\n", move_index[read8(0xAF3E)]);
		printf("1st Pokemon Move 4:\n %s\n", move_index[read8(0xAF3F)]);
		printf("1st Pokemon OT ID:\n %u\n", read16(0xAF40));
		printf("1st Pokemon XP:\n %u\n", read24(0xAF42));
		printf("1st Pokemon HP SXP:\n %u\n", read16(0xAF45));
		printf("1st Pokemon Atk SXP: %u\n", read16(0xAF47));
		printf("1st Pokemon Def SXP: %u\n", read16(0xAF49));
		DISABLE_RAM;
		
		waitpad(J_A);
		waitpadup();
		
		ENABLE_RAM;
		SWITCH_RAM(1);
		printf("1st Pokemon Spe SXP: %u\n", read16(0xAF4B));
		printf("1st Pokemon Spc SXP: %u\n", read16(0xAF4D));
		printf("1st Pokemon Atk DV:\n %u\n", read4(0xAF4F,true));
		printf("1st Pokemon Def DV:\n %u\n", read4(0xAF4F,false));
		printf("1st Pokemon Spe DV:\n %u\n", read4(0xAF50,true));
		printf("1st Pokemon Spc DV:\n %u\n", read4(0xAF50,false));
		printf("1st Pokemon Move1PP: %u\n", read8(0xAF51));
		printf("1st Pokemon Move2PP: %u\n", read8(0xAF52));
		printf("1st Pokemon Move3PP: %u\n", read8(0xAF53));
		DISABLE_RAM;
		
		waitpad(J_A);
		waitpadup();
		
		ENABLE_RAM;
		SWITCH_RAM(1);
		printf("1st Pokemon Move4PP: %u\n", read8(0xAF54));
		printf("1st Pokemon Level:\n %u\n", read8(0xAF55));
		printf("1st Pokemon Max HP:\n %u\n", read16(0xAF56));
		printf("1st Pokemon Cur Atk: %u\n", read16(0xAF58));
		printf("1st Pokemon Cur Def: %u\n", read16(0xAF5A));
		printf("1st Pokemon Cur Spe: %u\n", read16(0xAF5C));
		printf("1st Pokemon Cur Spc:%u\n", read16(0xAF5E));
		
		DISABLE_RAM; // Disable RAM
		
		waitpad(J_A);
		waitpadup();
		*/
	//}
}	