#ifndef MCNET_PARSER_H
#define MCNET_PARSER_H

#include "packets.h"

typedef struct mcnet_parser_s {
  void* data;
} mcnet_parser_t;

typedef void (*packet_cb)(mcnet_parser_t* parser, mcnet_packet_t* packet);
typedef void (*error_cb)(mcnet_parser_t* parser, int err);

typedef struct mcnet_parser_settings_s {
  packet_cb on_packet;
  error_cb on_error;
} mcnet_parser_settings_t;

#define PARSER_SIGNATURE(id) size_t mcnet_parser_parse_##id(mcnet_parser_t* parser, mcnet_parser_settings_t* settings, char* data, size_t data_len)

size_t mcnet_parser_execute(mcnet_parser_t* parser, mcnet_parser_settings_t* settings, char* data, size_t data_len);

#define PACKET(id, code) PARSER_SIGNATURE(id);

PACKETS

#undef PACKET

#endif
