#include "functions.h"

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
	return ptr[2] | ptr[1]<<8 | ptr[0]<<16;
}

uint32_t read32(uint8_t* ptr)
{
	return ptr[3] | ptr[2]<<8 | ptr[1]<<16 | ptr[0]<<24;
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
