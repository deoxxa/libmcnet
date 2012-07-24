#ifndef MCNET_WRITE_H
#define MCNET_WRITE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void mcnet_write_bool(uint8_t* out, int8_t in);
void mcnet_write_int8(uint8_t* out, int8_t in);
void mcnet_write_uint8(uint8_t* out, uint8_t in);
void mcnet_write_int16(uint8_t* out, int16_t in);
void mcnet_write_uint16(uint8_t* out, uint16_t in);
void mcnet_write_int32(uint8_t* out, int32_t in);
void mcnet_write_uint32(uint8_t* out, uint32_t in);
void mcnet_write_int64(uint8_t* out, int64_t in);
void mcnet_write_uint64(uint8_t* out, uint64_t in);
void mcnet_write_float(uint8_t* out, float in);
void mcnet_write_double(uint8_t* out, double in);

#ifdef __cplusplus
}
#endif

#endif
