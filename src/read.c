#include <stdint.h>

#include "../include/mcnet/read.h"

#ifdef __cplusplus
extern "C" {
#endif

int8_t mcnet_read_bool(uint8_t* in) {
  return (*((int8_t*)(in)) == 0) ? 0 : 1;
}

int8_t mcnet_read_int8(uint8_t* in) {
  return *((int8_t*)(in));
}

uint8_t mcnet_read_uint8(uint8_t* in) {
  return *((uint8_t*)(in));
}

int16_t mcnet_read_int16(uint8_t* in) {
  int16_t out;

  uint8_t* t = (uint8_t*)&out;

  t[0] = in[1];
  t[1] = in[0];

  return out;
}

uint16_t mcnet_read_uint16(uint8_t* in) {
  uint16_t out;

  uint8_t* t = (uint8_t*)&out;

  t[0] = in[1];
  t[1] = in[0];

  return out;
}

int32_t mcnet_read_int32(uint8_t* in) {
  int32_t out;

  uint8_t* t = (uint8_t*)&out;

  t[0] = in[3];
  t[1] = in[2];
  t[2] = in[1];
  t[3] = in[0];

  return out;
}

int64_t mcnet_read_int64(uint8_t* in) {
  int64_t out;

  uint8_t* t = (uint8_t*)&out;

  t[0] = in[7];
  t[1] = in[6];
  t[2] = in[5];
  t[3] = in[4];
  t[4] = in[3];
  t[5] = in[2];
  t[6] = in[1];
  t[7] = in[0];

  return out;
}

float mcnet_read_float(uint8_t* in) {
  float out;

  uint8_t* t = (uint8_t*)&out;

  t[0] = in[3];
  t[1] = in[2];
  t[2] = in[1];
  t[3] = in[0];

  return out;
}

double mcnet_read_double(uint8_t* in) {
  double out;

  uint8_t* t = (uint8_t*)&out;

  t[0] = in[7];
  t[1] = in[6];
  t[2] = in[5];
  t[3] = in[4];
  t[4] = in[3];
  t[5] = in[2];
  t[6] = in[1];
  t[7] = in[0];

  return out;
}

#ifdef __cplusplus
}
#endif
