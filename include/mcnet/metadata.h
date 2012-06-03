#ifndef MCNET_METADATA_H
#define MCNET_METADATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

typedef struct mcnet_metadata_s {
  int8_t count;
  int8_t length;
  struct mcnet_metadata_entry_s* entries;
} mcnet_metadata_t;

#define MCNET_METADATA_ENTRY_FIELDS uint8_t type; uint8_t index;

typedef struct mcnet_metadata_entry_s {
  MCNET_METADATA_ENTRY_FIELDS
} mcnet_metadata_entry_t;

typedef struct mcnet_metadata_entry_byte_s {
  MCNET_METADATA_ENTRY_FIELDS
  int8_t data;
} mcnet_metadata_entry_byte_t;

typedef struct mcnet_metadata_entry_short_s {
  MCNET_METADATA_ENTRY_FIELDS
  int16_t data;
} mcnet_metadata_entry_short_t;

typedef struct mcnet_metadata_entry_int_s {
  MCNET_METADATA_ENTRY_FIELDS
  int32_t data;
} mcnet_metadata_entry_int_t;

typedef struct mcnet_metadata_entry_float_s {
  MCNET_METADATA_ENTRY_FIELDS
  float data;
} mcnet_metadata_entry_float_t;

typedef struct mcnet_metadata_entry_string16_s {
  MCNET_METADATA_ENTRY_FIELDS
  short data_length;
  uint8_t* data;
} mcnet_metadata_entry_string16_t;

typedef struct mcnet_metadata_entry_sbs_s {
  MCNET_METADATA_ENTRY_FIELDS
  int16_t id;
  int8_t count;
  int16_t damage;
} mcnet_metadata_entry_sbs_t;

typedef struct mcnet_metadata_entry_iii_s {
  MCNET_METADATA_ENTRY_FIELDS
  int32_t data[3];
} mcnet_metadata_entry_iii_t;

#define MCNET_METADATA_PARSER_EAGAIN -1
#define MCNET_METADATA_PARSER_EINVALID -2

struct mcnet_metadata_parser_s;
typedef void (*mcnet_metadata_parser_entry_cb)(struct mcnet_metadata_parser_s* parser, mcnet_metadata_entry_t* entry);
typedef void (*mcnet_metadata_parser_complete_cb)(struct mcnet_metadata_parser_s* parser);
typedef void (*mcnet_metadata_parser_error_cb)(struct mcnet_metadata_parser_s* parser, int error);

typedef struct mcnet_metadata_parser_s {
  void* data;
  mcnet_metadata_parser_entry_cb on_entry;
  mcnet_metadata_parser_complete_cb on_complete;
  mcnet_metadata_parser_error_cb on_error;
} mcnet_metadata_parser_t;

size_t mcnet_metadata_parser_parse(mcnet_metadata_parser_t* parser, uint8_t* data, size_t len);
size_t mcnet_metadata_parser_execute(mcnet_metadata_parser_t* parser, uint8_t* data, size_t len);

#ifdef __cplusplus
}
#endif

#endif
