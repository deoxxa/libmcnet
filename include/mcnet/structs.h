#ifndef MCNET_STRUCTS_H
#define MCNET_STRUCTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "packets.h"

#define ONLY_SERVER(code) code
#define ONLY_CLIENT(code) code
#define BOOL(name) int8_t name;
#define BYTE(name) int8_t name;
#define UBYTE(name) uint8_t name;
#define SHORT(name) int16_t name;
#define USHORT(name) uint16_t name;
#define INT(name) int32_t name;
#define LONG(name) int64_t name;
#define FLOAT(name) float name;
#define DOUBLE(name) double name;
#define BLOB(name, length) uint8_t* name;
#define STRING8(name) int16_t name##_len; BLOB(name, )
#define STRING16(name) STRING8(name)
#define METADATA(name) SHORT(name##_len) BLOB(name, )
#define SLOT(name) SHORT(name##_len) BLOB(name, )
#define SLOTS(name, count) SHORT(name##_len) BLOB(name, )
#define PARSER_CODE(code)
#define GENERATOR_CODE(code)

#define PACKET(id, code) typedef struct mcnet_packet_##id##_s { \
  UBYTE(pid) \
  code \
} mcnet_packet_##id##_t;

typedef struct mcnet_packet_s {
  UBYTE(pid)
} mcnet_packet_t;

PACKETS

#undef PACKET

#undef ONLY_SERVER
#undef ONLY_CLIENT
#undef BOOL
#undef BYTE
#undef UBYTE
#undef SHORT
#undef USHORT
#undef INT
#undef LONG
#undef FLOAT
#undef DOUBLE
#undef STRING8
#undef STRING16
#undef BLOB
#undef METADATA
#undef SLOT
#undef SLOTS
#undef PARSER_CODE
#undef GENERATOR_CODE

#ifdef __cplusplus
}
#endif

#endif
