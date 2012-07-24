#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "../include/mcnet/packets.h"
#include "../include/mcnet/structs.h"
#include "../include/mcnet/metadata.h"
#include "../include/mcnet/generator.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PACKET(pid, code) case 0x##pid: { \
  mcnet_packet_##pid##_t* _packet = (mcnet_packet_##pid##_t*)(packet); \
  (void)_packet; \
  code \
  break; \
};

#define ONLY_SERVER(code) if (1) { code }
#define ONLY_CLIENT(code) if (1) { code }
#define PARSER_CODE(code)
#define GENERATOR_CODE(code) code
#define BOOL(name) res += 1;
#define BYTE(name) res += 1;
#define UBYTE(name) res += 1;
#define SHORT(name) res += 2;
#define USHORT(name) res += 2;
#define INT(name) res += 4;
#define LONG(name) res += 8;
#define FLOAT(name) res += 4;
#define DOUBLE(name) res += 8;
#define BLOB(name, length) res += _packet->length;
#define STRING8(name) SHORT(name##_len) BLOB(name, name##_len)
#define STRING16(name) SHORT(name##_len) BLOB(name, name##_len * 2)
#define METADATA(name) SHORT(name##_len) BLOB(name, name##_len)
#define SLOT(name) res += 5;
#define SLOTS(name, len) res += 5 * _packet->name##_len;

size_t mcnet_generator_size(mcnet_packet_t* packet) {
  size_t res = 0;

  res += 1;

  switch (packet->pid) {
PACKETS
  }

  return res;
}

#undef ONLY_SERVER
#undef ONLY_CLIENT
#undef PARSER_CODE
#undef GENERATOR_CODE
#undef BOOL
#undef BYTE
#undef UBYTE
#undef SHORT
#undef USHORT
#undef INT
#undef LONG
#undef FLOAT
#undef DOUBLE
#undef BLOB
#undef STRING8
#undef STRING16
#undef METADATA
#undef SLOT
#undef SLOTS

#undef PACKET

#ifdef __cplusplus
}
#endif
