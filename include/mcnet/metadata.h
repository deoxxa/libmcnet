#ifndef MCNET_METADATA_H
#define MCNET_METADATA_H

#include <stdint.h>

#define MCNET_METADATA_FIELDS uint8_t info;

typedef struct mcnet_metadata_s {
  MCNET_METADATA_FIELDS
} mcnet_metadata_t;

typedef struct mcnet_metadata_byte_s {
  MCNET_METADATA_FIELDS
  int8_t data;
} mcnet_metadata_byte_t;

typedef struct mcnet_metadata_short_s {
  MCNET_METADATA_FIELDS
  int16_t data;
} mcnet_metadata_short_t;

typedef struct mcnet_metadata_int_s {
  MCNET_METADATA_FIELDS
  int32_t data;
} mcnet_metadata_int_t;

typedef struct mcnet_metadata_float_s {
  MCNET_METADATA_FIELDS
  float data;
} mcnet_metadata_float_t;

typedef struct mcnet_metadata_string_s {
  MCNET_METADATA_FIELDS
  short data_length;
  uint8_t* data;
} mcnet_metadata_string_t;

typedef struct mcnet_metadata_sbs_s {
  MCNET_METADATA_FIELDS
  int16_t a;
  int8_t b;
  int16_t c;
} mcnet_metadata_sbs_t;

typedef struct mcnet_metadata_iii_s {
  MCNET_METADATA_FIELDS
  int32_t a;
  int32_t b;
  int32_t c;
} mcnet_metadata_iii_t;

#endif
