#include <stdint.h>
#include <stdbool.h> 

uint8_t read8(uint8_t* ptr);
uint16_t read16(uint8_t* ptr);
uint32_t read24(uint8_t* ptr);
uint32_t read32(uint8_t* ptr);
uint8_t read4(uint8_t* ptr, bool highNibble);

uint16_t swap_uint16( uint16_t val );
int16_t swap_int16( int16_t val );
uint32_t swap_uint32( uint32_t val );
int32_t swap_int32( int32_t val );