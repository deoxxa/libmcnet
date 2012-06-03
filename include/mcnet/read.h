#ifndef MCNET_READ_H
#define MCNET_READ_H

#include <stdint.h>

int8_t mcnet_read_bool(uint8_t* in);
int8_t mcnet_read_int8(uint8_t* in);
uint8_t mcnet_read_uint8(uint8_t* in);
int16_t mcnet_read_int16(uint8_t* in);
uint16_t mcnet_read_uint16(uint8_t* in);
int32_t mcnet_read_int32(uint8_t* in);
int64_t mcnet_read_int64(uint8_t* in);
float mcnet_read_float(uint8_t* in);
double mcnet_read_double(uint8_t* in);

#endif