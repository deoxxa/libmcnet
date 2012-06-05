#ifndef MCNET_PARSER_H
#define MCNET_PARSER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

#include "packets.h"

#define MCNET_PARSER_TYPE_CLIENT 1
#define MCNET_PARSER_TYPE_SERVER 2

typedef struct mcnet_parser_s {
  void* data;
  char type;
} mcnet_parser_t;

typedef void (*packet_cb)(mcnet_parser_t* parser, mcnet_packet_t* packet);
typedef void (*error_cb)(mcnet_parser_t* parser, int err);

typedef struct mcnet_parser_settings_s {
  packet_cb on_packet;
  error_cb on_error;
} mcnet_parser_settings_t;

size_t mcnet_parser_execute(mcnet_parser_t* parser, mcnet_parser_settings_t* settings, uint8_t* data, size_t data_len);

#ifdef __cplusplus
}
#endif

#endif
