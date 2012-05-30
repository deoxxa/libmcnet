#include <stdlib.h>
#include <sys/types.h>
#define __USE_BSD
#include <endian.h>

#include "../include/mcnet/packets.h"
#include "../include/mcnet/structs.h"
#include "../include/mcnet/metadata.h"
#include "../include/mcnet/parser.h"

#define PACKET(id, code) case 0x##id: { return mcnet_parser_parse_##id(parser, settings, data, data_len); }

size_t mcnet_parser_execute(mcnet_parser_t* parser, mcnet_parser_settings_t* settings, char* data, size_t data_len) {
  if (data_len < 1) {
    return 0;
  }

  switch (data[0]) {
    PACKETS

    default: {
      if (settings->on_error != NULL) {
        settings->on_error(parser, -1);
      }

      return 0;
    }
  }

  return 0;
}

#undef PACKET

#define PACKET(id, code) PARSER_SIGNATURE(id) { \
  mcnet_packet_##id##_t packet; \
  size_t nparsed = 0; \
  code \
  if (settings->on_packet != NULL) { \
    settings->on_packet(parser, (mcnet_packet_t*)&packet); \
  } \
  return nparsed; \
}

#define BYTE(name) if (data_len < nparsed + 1) { return 0; } packet.name = *((int8_t*)(data + nparsed)); nparsed += 1;
#define UBYTE(name) if (data_len < nparsed + 1) { return 0; } packet.name = *((uint8_t*)(data + nparsed)); nparsed += 1;
#define SHORT(name) if (data_len < nparsed + 2) { return 0; } packet.name = htobe16(*((int16_t*)(data + nparsed))); nparsed += 2;
#define INT(name) if (data_len < nparsed + 4) { return 0; } packet.name = htobe32(*((int32_t*)(data + nparsed))); nparsed += 4;
#define LONG(name) if (data_len < nparsed + 8) { return 0; } packet.name = htobe64(*((int64_t*)(data + nparsed))); nparsed += 8;
#define FLOAT(name) if (data_len < nparsed + 4) { return 0; } packet.name = (float)htobe32(*((int32_t*)(data + nparsed))); nparsed += 4;
#define DOUBLE(name) if (data_len < nparsed + 8) { return 0; } packet.name = (double)htobe64(*((int64_t*)(data + nparsed))); nparsed += 8;
#define BLOB(name, length) if (data_len < nparsed + length) { return 0; } packet.name = data + nparsed; nparsed += length;
#define STRING8(name) INT(name##_len) BLOB(name, packet.name##_len)
#define STRING16(name) INT(name##_len) BLOB(name, packet.name##_len * 2)
#define METADATA(name)

PACKETS

#undef BOOL
#undef BYTE
#undef UBYTE
#undef SHORT
#undef INT
#undef LONG
#undef FLOAT
#undef DOUBLE
#undef STRING8
#undef STRING16
#undef METADATA

#undef PACKET
