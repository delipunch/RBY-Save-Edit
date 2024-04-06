#include "functions.h"
#include "pokemon_defines.h"
#include <gb/gb.h>

extern uint8_t monBuffer[];
void readMonIntoBuffer(uint8_t slotNo)
{
	uint8_t* slotPtr;
	switch (slotNo)
	{
		case 1:
			slotPtr = partyMon1Gen1;
			break;
		case 2:
			slotPtr = partyMon2Gen1;
			break;
		case 3:
			slotPtr = partyMon3Gen1;
			break;
		case 4:
			slotPtr = partyMon4Gen1;
			break;
		case 5:
			slotPtr = partyMon5Gen1;
			break;
		case 6:
			slotPtr = partyMon6Gen1;
			break;
	}
	
	ENABLE_RAM; // Enable RAM
	SWITCH_RAM(1); // Switch to RAM Bank 1, the main bank for save data
	for (uint8_t bufferCopyProgress = 0; bufferCopyProgress < partyMonLengthGen1; bufferCopyProgress++)
	{
		monBuffer[bufferCopyProgress]=read8(slotPtr+bufferCopyProgress); //copy from the save into a buffer
	}
	DISABLE_RAM; //Disable RAM, we're done with it for now
}

uint8_t read8(uint8_t* ptr)
{
	return ptr[0];
}

uint16_t read16(uint8_t* ptr)
{
	return ptr[1] | ptr[0]<<8;
}

uint32_t read24(uint8_t* ptr)
{
	return ptr[2] | ptr[1]<<8 | ptr[0]<<16 & 0x00FFFFFF;
}

uint32_t read32(uint8_t* ptr)
{
	return ptr[3] | ptr[2]<<8 | ptr[1]<<16 | ptr[0]<<24;
}

uint8_t read4(uint8_t* ptr, bool highNibble)
{
	if (highNibble)
	{
		return ptr[0] >> 4 & 0x0F;
	}
	else
	{
		return ptr[0] & 0x0F;
	}
}

//Byte swaps lifted from https://stackoverflow.com/a/2637138
//! Byte swap unsigned short
uint16_t swap_uint16( uint16_t val ) 
{
    return (val << 8) | (val >> 8 );
}

//! Byte swap short
int16_t swap_int16( int16_t val ) 
{
    return (val << 8) | ((val >> 8) & 0xFF);
}

//! Byte swap unsigned int
uint32_t swap_uint32( uint32_t val )
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | (val >> 16);
}

//! Byte swap int
int32_t swap_int32( int32_t val )
{
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | ((val >> 16) & 0xFFFF);
}

/*
uint16_t byteSwap16(uint16_t input)
{
	uint16_t output =   ((input>>8)&0xFF) | // move high byte to the right and ensure zeros were shifted in
						((input<<8)&0xFF00); //same as above, but low byyte to the left
	return output;
}

uint32_t byteSwap32(uint32_t input)
{
	uint32_t output =   ((input>>24)&0xff) | // move byte 3 to byte 0
						((input<<8)&0xff0000) | // move byte 1 to byte 2
						((input>>8)&0xff00) | // move byte 2 to byte 1
						((input<<24)&0xff000000); // byte 0 to byte 3
	return output;
}
*/



/*
void cls() // lifted from https://github.com/tomvdb/gameboy-menu
{
    // dirty cls
    int c = 0;
    for ( c = 0; c < 18; c++ )
    {
        gotoxy( 1, c );
        printf( "                    ");
    }
    gotoxy(1, 1);
}
*/

uint8_t checksumBank(uint8_t bankNo)
{
	switch (bankNo)
	{
		case 1://not working currently
			uint8_t checksumBank1 = 255;
			ENABLE_RAM;
			SWITCH_RAM(1);
			for (uint16_t checksumProgress=0;checksumProgress<0xF8A;checksumProgress++)
			{
				uint8_t* checksumPtr = 0xA598;
				checksumBank1 -= checksumPtr[checksumProgress];
			}
			DISABLE_RAM;
			return checksumBank1;
			break;
			/*
		case 2:
			uint8_t checksumBank2 = 255;
			uint8_t checksumBank2Box1 = 255;
			uint8_t checksumBank2Box2 = 255;
			uint8_t checksumBank2Box3 = 255;
			uint8_t checksumBank2Box4 = 255;
			uint8_t checksumBank2Box5 = 255;
			uint8_t checksumBank2Box6 = 255;
			*/
	}
}