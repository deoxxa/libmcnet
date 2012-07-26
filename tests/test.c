#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mcnet.h>

int test_id = 0, test_mode = 0;

/* generate the test callback functions */

#define ONLY_SERVER(code) if (test_mode == MCNET_TYPE_SERVER) { code }
#define ONLY_CLIENT(code) if (test_mode == MCNET_TYPE_CLIENT) { code }
#define PARSER_CODE(code)
#define GENERATOR_CODE(code)

#define BOOL(name) if (packet->name == 1) { printf("ok %04d - %02X/" #name " (bool) was correct\n", test_id++, packet->pid); } else { printf("not ok %04d - %02X/" #name " (bool) was incorrect\n", test_id++, packet->pid); }
#define BYTE(name) if (packet->name == 2) { printf("ok %04d - %02X/" #name " (byte) was correct\n", test_id++, packet->pid); } else { printf("not ok %04d - %02X/" #name " (byte) was incorrect\n", test_id++, packet->pid); }
#define UBYTE(name) if (packet->name == 3) { printf("ok %04d - %02X/" #name " (unsigned byte) was correct\n", test_id++, packet->pid); } else { printf("not ok %04d - %02X/" #name " (unsigned byte) was incorrect\n", test_id++, packet->pid); }
#define SHORT(name) if (packet->name == 4) { printf("ok %04d - %02X/" #name " (short) was correct\n", test_id++, packet->pid); } else { printf("not ok %04d - %02X/" #name " (short) was incorrect\n", test_id++, packet->pid); }
#define USHORT(name) if (packet->name == 5) { printf("ok %04d - %02X/" #name " (unsigned short) was correct\n", test_id++, packet->pid); } else { printf("not ok %04d - %02X/" #name " (unsigned short) was incorrect\n", test_id++, packet->pid); }
#define INT(name) if (packet->name == 6) { printf("ok %04d - %02X/" #name " (int) was correct\n", test_id++, packet->pid); } else { printf("not ok %04d - %02X/" #name " (int) was incorrect\n", test_id++, packet->pid); }
#define LONG(name) if (packet->name == 7) { printf("ok %04d - %02X/" #name " (long) was correct\n", test_id++, packet->pid); } else { printf("not ok %04d - %02X/" #name " (long) was incorrect\n", test_id++, packet->pid); }
#define FLOAT(name) if (packet->name == 8) { printf("ok %04d - %02X/" #name " (float) was correct\n", test_id++, packet->pid); } else { printf("not ok %04d - %02X/" #name " (float) was incorrect\n", test_id++, packet->pid); }
#define DOUBLE(name) if (packet->name == 9) { printf("ok %04d - %02X/" #name " (double) was correct\n", test_id++, packet->pid); } else { printf("not ok %04d - %02X/" #name " (double) was incorrect\n", test_id++, packet->pid); }
#define BLOB(name, length) { char good = 1; int i = 0; for (i=0;i<packet->length;++i) { if (packet->name[i] != 10) { good = 0; break; } } if (good == 1) { printf("ok %04d - %02X/" #name " (blob) was correct\n", test_id++, packet->pid); } else { printf("not ok %04d - %02X/" #name " (blob) was incorrect\n", test_id++, packet->pid); } }
#define STRING8(name) SHORT(name##_len) BLOB(name, name##_len)
#define STRING16(name) SHORT(name##_len) BLOB(name, name##_len * 2)
#define METADATA(name)
#define SLOT(name)
#define SLOTS(name, count)

#define PACKET(id, code) void packet_callback_##id(mcnet_parser_t* parser, mcnet_packet_t* _packet) { \
  printf("ok %04d - parsing packet " #id " was successful\n", test_id++); \
  mcnet_packet_##id##_t* packet = (mcnet_packet_##id##_t*)_packet; \
  (void)packet; \
  code \
}

PACKETS

#undef PACKET

#define PACKET(id, code) void error_callback_##id(mcnet_parser_t* parser, int err) { \
  printf("not ok %04d - parsing packet " #id " failed\n", test_id++); \
}

PACKETS

#undef PACKET

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

#undef ONLY_SERVER
#undef ONLY_CLIENT
#undef PARSER_CODE
#undef GENERATOR_CODE
    
/* application entry point */

int main(int argc, char** argv) {
/* first we need to initialise various data structures */

  mcnet_parser_t parser = { .data = NULL, .type = test_mode };
  mcnet_generator_t generator = { .type = test_mode };

#define ONLY_SERVER(code) if (test_mode == MCNET_TYPE_SERVER) { code }
#define ONLY_CLIENT(code) if (test_mode == MCNET_TYPE_CLIENT) { code }
#define PARSER_CODE(code)
#define GENERATOR_CODE(code)

#define BOOL(name)
#define BYTE(name)
#define UBYTE(name)
#define SHORT(name)
#define USHORT(name)
#define INT(name)
#define LONG(name)
#define FLOAT(name)
#define DOUBLE(name)
#define BLOB(name, length)
#define STRING8(name)
#define STRING16(name)
#define METADATA(name)
#define SLOT(name)
#define SLOTS(name, count)

#define PACKET(id, code) \
  mcnet_packet_##id##_t packet_##id; \
  memset(&packet_##id, 0, sizeof(mcnet_packet_##id##_t));

PACKETS

#undef PACKET

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

#undef ONLY_SERVER
#undef ONLY_CLIENT
#undef PARSER_CODE
#undef GENERATOR_CODE

/* now we set some sample values */

#define ONLY_SERVER(code) if (test_mode == MCNET_TYPE_SERVER) { code }
#define ONLY_CLIENT(code) if (test_mode == MCNET_TYPE_CLIENT) { code }
#define PARSER_CODE(code)
#define GENERATOR_CODE(code)

#define BOOL(name) packet->name = 1;
#define BYTE(name) packet->name = 2;
#define UBYTE(name) packet->name = 3;
#define SHORT(name) packet->name = 4;
#define USHORT(name) packet->name = 5;
#define INT(name) packet->name = 6;
#define LONG(name) packet->name = 7;
#define FLOAT(name) packet->name = 8;
#define DOUBLE(name) packet->name = 9;
#define BLOB(name, length) packet->name = malloc(packet->length); memset(packet->name, 10, packet->length);
#define STRING8(name) SHORT(name##_len) BLOB(name, name##_len)
#define STRING16(name) SHORT(name##_len) BLOB(name, name##_len * 2)
#define METADATA(name)
#define SLOT(name)
#define SLOTS(name, count)

/* THIS JUST IN: PROGRAMMER ABUSES BLOCKS IN A MINECRAFT LIBRARY; IRONY LOST ON MOST USERS. */

#define PACKET(id, code) { \
  mcnet_packet_##id##_t* packet = &packet_##id; \
  (void)packet; \
  packet->pid = 0x##id; \
  code \
}

PACKETS

#undef PACKET

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

#undef ONLY_SERVER
#undef ONLY_CLIENT
#undef PARSER_CODE
#undef GENERATOR_CODE

/* generate packets */

#define ONLY_SERVER(code) if (test_mode == MCNET_TYPE_SERVER) { code }
#define ONLY_CLIENT(code) if (test_mode == MCNET_TYPE_CLIENT) { code }
#define PARSER_CODE(code)
#define GENERATOR_CODE(code)

#define BOOL(name)
#define BYTE(name)
#define UBYTE(name)
#define SHORT(name)
#define USHORT(name)
#define INT(name)
#define LONG(name)
#define FLOAT(name)
#define DOUBLE(name)
#define BLOB(name, length)
#define STRING8(name)
#define STRING16(name)
#define METADATA(name)
#define SLOT(name)
#define SLOTS(name, count)

/* THIS JUST IN: PROGRAMMER ABUSES BLOCKS IN A MINECRAFT LIBRARY; IRONY LOST ON MOST USERS. */

#define PACKET(id, code) \
  size_t packet_##id##_len = mcnet_generator_size(&generator, (mcnet_packet_t*)&packet_##id); \
  if (packet_##id##_len == MCNET_EAGAIN) { \
    printf("not ok %04d - couldn't get packet length for " #id " (not enough data)\n", test_id++); \
  } else if (packet_##id##_len == MCNET_EINVALID) { \
    printf("not ok %04d - couldn't get packet length for " #id " (invalid data encountered)\n", test_id++); \
  } else { \
    printf("ok %04d - getting size for packet " #id " was successful (%lu bytes)\n", test_id++, packet_##id##_len); \
  } \
  uint8_t* packet_##id##_buffer = malloc(packet_##id##_len); \
  memset(packet_##id##_buffer, 0, packet_##id##_len); \
  size_t generator_res_##id = mcnet_generator_write(&generator, (mcnet_packet_t*)&packet_##id, packet_##id##_buffer); \
  if (generator_res_##id == MCNET_EAGAIN) { \
    printf("not ok %04d - couldn't generate packet " #id " (not enough data)\n", test_id++); \
  } else if (generator_res_##id == MCNET_EINVALID) { \
    printf("not ok %04d - couldn't generate packet " #id " (invalid data encountered)\n", test_id++); \
  } else if (packet_##id##_len != generator_res_##id) { \
    printf("not ok %04d - generating packet " #id " dubious (expected and actual sizes didn't match)\n", test_id++); \
  } else { \
    printf("ok %04d - packet " #id " generation was successful (%lu bytes)\n", test_id++, generator_res_##id); \
  }

PACKETS

#undef PACKET

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

#undef ONLY_SERVER
#undef ONLY_CLIENT
#undef PARSER_CODE
#undef GENERATOR_CODE

/* parse the generated packets */

#define ONLY_SERVER(code) if (test_mode == MCNET_TYPE_SERVER) { code }
#define ONLY_CLIENT(code) if (test_mode == MCNET_TYPE_CLIENT) { code }
#define PARSER_CODE(code)
#define GENERATOR_CODE(code)

#define BOOL(name)
#define BYTE(name)
#define UBYTE(name)
#define SHORT(name)
#define USHORT(name)
#define INT(name)
#define LONG(name)
#define FLOAT(name)
#define DOUBLE(name)
#define BLOB(name, length)
#define STRING8(name)
#define STRING16(name)
#define METADATA(name)
#define SLOT(name)
#define SLOTS(name, count)

#define PACKET(id, code) \
  mcnet_parser_settings_t parser_settings_##id = { .on_packet = packet_callback_##id, .on_error = error_callback_##id }; \
  size_t parser_res_##id = mcnet_parser_execute(&parser, &parser_settings_##id, packet_##id##_buffer, packet_##id##_len); \
  if (parser_res_##id == MCNET_EAGAIN) { \
    printf("not ok %04d - couldn't parse packet " #id " (not enough data)\n", test_id++); \
  } \
  if (parser_res_##id == MCNET_EINVALID) { \
    printf("not ok %04d - couldn't parse packet " #id " (invalid data encountered)\n", test_id++); \
  }

PACKETS

#undef PACKET

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

#undef ONLY_SERVER
#undef ONLY_CLIENT
#undef PARSER_CODE
#undef GENERATOR_CODE

  return 0;
}
