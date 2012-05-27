#ifndef MCNET_PARSER_H
#define MCNET_PARSER_H

#include <sys/types.h>

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

#define PARSER_DEFINITION(id) size_t mcnet_parser_parse_##id(mcnet_parser_t* parser, mcnet_parser_settings_t* settings, char* data, size_t data_len)

size_t mcnet_parser_execute(mcnet_parser_t* parser, mcnet_parser_settings_t* settings, char* data, size_t data_len);

PARSER_DEFINITION(00);
PARSER_DEFINITION(01);
PARSER_DEFINITION(02);
PARSER_DEFINITION(03);
PARSER_DEFINITION(04);
PARSER_DEFINITION(05);
PARSER_DEFINITION(06);
PARSER_DEFINITION(07);
PARSER_DEFINITION(08);
PARSER_DEFINITION(09);
PARSER_DEFINITION(0A);
PARSER_DEFINITION(0B);
PARSER_DEFINITION(0E);
PARSER_DEFINITION(0F);

#endif
