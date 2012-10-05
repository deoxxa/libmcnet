#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void mcnet_write_bool(uint8_t* out, int8_t in) {
  out[0] = ((in >> 0) & 0x01);
}

void mcnet_write_int8(uint8_t* out, int8_t in) {
  out[0] = ((in >> 0) & 0xFF);
}

void mcnet_write_uint8(uint8_t* out, uint8_t in) {
  out[0] = ((in >> 0) & 0xFF);
}

void mcnet_write_int16(uint8_t* out, int16_t in) {
  out[0] = ((in >> 8) & 0xFF);
  out[1] = ((in >> 0) & 0xFF);
}

void mcnet_write_uint16(uint8_t* out, uint16_t in) {
  out[0] = ((in >> 8) & 0xFF);
  out[1] = ((in >> 0) & 0xFF);
}

void mcnet_write_int32(uint8_t* out, int32_t in) {
  out[0] = ((in >> 24) & 0xFF);
  out[1] = ((in >> 16) & 0xFF);
  out[2] = ((in >> 8) & 0xFF);
  out[3] = ((in >> 0) & 0xFF);
}

void mcnet_write_uint32(uint8_t* out, uint32_t in) {
  out[0] = ((in >> 24) & 0xFF);
  out[1] = ((in >> 16) & 0xFF);
  out[2] = ((in >> 8) & 0xFF);
  out[3] = ((in >> 0) & 0xFF);
}

void mcnet_write_int64(uint8_t* out, int64_t in) {
  out[0] = ((in >> 56) & 0xFF);
  out[1] = ((in >> 48) & 0xFF);
  out[2] = ((in >> 40) & 0xFF);
  out[3] = ((in >> 32) & 0xFF);
  out[4] = ((in >> 24) & 0xFF);
  out[5] = ((in >> 16) & 0xFF);
  out[6] = ((in >> 8) & 0xFF);
  out[7] = ((in >> 0) & 0xFF);
}

void mcnet_write_uint64(uint8_t* out, uint64_t in) {
  out[0] = ((in >> 56) & 0xFF);
  out[1] = ((in >> 48) & 0xFF);
  out[2] = ((in >> 40) & 0xFF);
  out[3] = ((in >> 32) & 0xFF);
  out[4] = ((in >> 24) & 0xFF);
  out[5] = ((in >> 16) & 0xFF);
  out[6] = ((in >> 8) & 0xFF);
  out[7] = ((in >> 0) & 0xFF);
}

void mcnet_write_float(uint8_t* out, float in) {
  uint8_t* t = (uint8_t*)&in;

  out[0] = t[3];
  out[1] = t[2];
  out[2] = t[1];
  out[3] = t[0];
}

void mcnet_write_double(uint8_t* out, double in) {
  uint8_t* t = (uint8_t*)&in;

  out[0] = t[7];
  out[1] = t[6];
  out[2] = t[5];
  out[3] = t[4];
  out[4] = t[3];
  out[5] = t[2];
  out[6] = t[1];
  out[7] = t[0];
}

#ifdef __cplusplus
}
#endif
