#include <stdlib.h>
#include <sys/types.h>
#define __USE_BSD
#include <endian.h>

#include "parser.h"
#include "packets.h"

#define EXECUTE_CASE(x) case 0x##x: { return mcnet_parser_parse_##x(parser, settings, data, data_len); }

size_t mcnet_parser_execute(mcnet_parser_t* parser, mcnet_parser_settings_t* settings, char* data, size_t data_len) {
  if (data_len < 1) {
    return 0;
  }

  switch (data[0]) {
    EXECUTE_CASE(00);
    EXECUTE_CASE(01);
    EXECUTE_CASE(02);
    EXECUTE_CASE(03);
    EXECUTE_CASE(04);
    EXECUTE_CASE(05);
    EXECUTE_CASE(06);
    EXECUTE_CASE(07);
    EXECUTE_CASE(08);
    EXECUTE_CASE(09);
    EXECUTE_CASE(0A);
    EXECUTE_CASE(0B);
    EXECUTE_CASE(0E);
    EXECUTE_CASE(0F);

    default: {
      if (settings->on_error != NULL) {
        settings->on_error(parser, -1);
      }

      return 0;
    }
  }

  return 0;
}

#define PARSER(id, code) PARSER_DEFINITION(id) { \
  mcnet_packet_##id##_t packet; \
  size_t nparsed = 0; \
  code \
  if (settings->on_packet != NULL) { \
    settings->on_packet(parser, (mcnet_packet_t*)&packet); \
  } \
  return nparsed; \
}

#define PARSE_BYTE(name) if (data_len < nparsed + 1) { return 0; } packet.name = *((uint8_t*)(data + nparsed)); nparsed += 1;
#define PARSE_SHORT(name) if (data_len < nparsed + 2) { return 0; } packet.name = htobe16(*((int16_t*)(data + nparsed))); nparsed += 2;
#define PARSE_INT(name) if (data_len < nparsed + 4) { return 0; } packet.name = htobe32(*((int32_t*)(data + nparsed))); nparsed += 4;
#define PARSE_LONG(name) if (data_len < nparsed + 8) { return 0; } packet.name = htobe64(*((int64_t*)(data + nparsed))); nparsed += 8;
#define PARSE_FLOAT(name) if (data_len < nparsed + 4) { return 0; } packet.name = (float)htobe32(*((int32_t*)(data + nparsed))); nparsed += 4;
#define PARSE_DOUBLE(name) if (data_len < nparsed + 8) { return 0; } packet.name = (double)htobe64(*((int64_t*)(data + nparsed))); nparsed += 8;
#define PARSE_BLOB(name, length) if (data_len < nparsed + length) { return 0; } packet.name = data + nparsed; nparsed += length;
#define PARSE_STRING16(name) PARSE_INT(name##_len) PARSE_BLOB(name, packet.name##_len * 2)

PARSER(00,
  PARSE_BYTE(pid)
  PARSE_INT(id)
)

PARSER(01,
  PARSE_BYTE(pid)
  PARSE_INT(eid)
  PARSE_STRING16(username)
  PARSE_STRING16(level_type)
  PARSE_INT(server_mode)
  PARSE_INT(dimension)
  PARSE_BYTE(difficulty)
  PARSE_BYTE(world_height)
  PARSE_BYTE(max_players)
)

PARSER(02,
  PARSE_BYTE(pid)
  PARSE_STRING16(data)
)

PARSER(03,
  PARSE_BYTE(pid)
  PARSE_STRING16(data)
)

PARSER(04,
  PARSE_BYTE(pid)
  PARSE_LONG(time)
)

PARSER(05,
  PARSE_BYTE(pid)
  PARSE_INT(eid)
  PARSE_SHORT(slot)
  PARSE_SHORT(itemid)
  PARSE_SHORT(damage)
)

PARSER(06,
  PARSE_BYTE(pid)
  PARSE_INT(x)
  PARSE_INT(y)
  PARSE_INT(z)
)

PARSER(07,
  PARSE_BYTE(pid)
  PARSE_INT(user)
  PARSE_INT(target)
  PARSE_BYTE(mouse)
)

PARSER(08,
  PARSE_BYTE(pid)
  PARSE_SHORT(health)
  PARSE_SHORT(hunger)
  PARSE_FLOAT(saturation)
)

PARSER(09,
  PARSE_BYTE(pid)
  PARSE_INT(dimension)
  PARSE_BYTE(difficulty)
  PARSE_BYTE(server_mode)
  PARSE_SHORT(world_height)
  PARSE_STRING16(level_type)
)

PARSER(0A,
  PARSE_BYTE(pid)
  PARSE_BYTE(on_ground)
)

PARSER(0B,
  PARSE_BYTE(pid)
  PARSE_DOUBLE(x)
  PARSE_DOUBLE(y)
  PARSE_DOUBLE(stance)
  PARSE_DOUBLE(z)
  PARSE_BYTE(on_ground)
)

PARSER(0E,
  PARSE_BYTE(pid)
  PARSE_BYTE(status)
  PARSE_SHORT(x)
  PARSE_BYTE(y)
  PARSE_SHORT(z)
  PARSE_BYTE(face)
)

PARSER(0F,
  PARSE_BYTE(pid)
  PARSE_BYTE(status)
  PARSE_SHORT(x)
  PARSE_BYTE(y)
  PARSE_SHORT(z)
  PARSE_BYTE(direction)
)
