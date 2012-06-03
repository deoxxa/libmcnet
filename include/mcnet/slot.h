#ifndef MCNET_SLOT_H
#define MCNET_SLOT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mcnet_slot_s {
  int16_t item;
  int8_t count;
  int16_t meta;
  int16_t data_len;
  uint8_t* data;
} mcnet_slot_t;

struct mcnet_slot_parser_s;
typedef void (*mcnet_slot_parser_complete_cb)(struct mcnet_slot_parser_s* parser, mcnet_slot_t* slot);
typedef void (*mcnet_slot_parser_error_cb)(struct mcnet_slot_parser_s* parser, int error);

typedef struct mcnet_slot_parser_s {
  void* data;
  mcnet_slot_parser_complete_cb on_complete;
  mcnet_slot_parser_error_cb on_error;
} mcnet_slot_parser_t;

size_t mcnet_slot_parser_parse(mcnet_slot_parser_t* parser, uint8_t* data, size_t len);

#ifdef __cplusplus
}
#endif

#endif
