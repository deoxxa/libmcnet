#include <stdio.h>
#include <stdlib.h>

#include <mcnet.h>

#define PACKET(id, code) case 0x##id: { mcnet_packet_##id##_t* tmp = (mcnet_packet_##id##_t*)packet; printf("Packet ID: %d\n", tmp->pid); code break; };

#define BYTE(name)     printf("  [byte]     %d\n",   tmp->name);
#define UBYTE(name)    printf("  [ubyte]    %u\n",   tmp->name);
#define SHORT(name)    printf("  [short]    %d\n",   tmp->name);
#define INT(name)      printf("  [int]      %d\n",   tmp->name);
#define LONG(name)     printf("  [long]     %lld\n", tmp->name);
#define FLOAT(name)    printf("  [float]    %f\n",   tmp->name);
#define DOUBLE(name)   printf("  [double]   %f\n",   tmp->name);
#define STRING16(name) printf("  [string16] %d\n",   tmp->name##_len);
#define METADATA(name) printf("  [metadata] %d\n",   tmp->name##_len);

void on_packet(mcnet_parser_t* parser, mcnet_packet_t* packet) {
  printf("[%p] packet type: %02x\n", parser->data, packet->pid);

  switch(packet->pid) {
    PACKETS
    default: { printf("Unknown packet type: %d\n", packet->pid); break; };
  }
}

#undef BYTE
#undef UBYTE
#undef SHORT
#undef INT
#undef LONG
#undef FLOAT
#undef DOUBLE
#undef STRING16
#undef METADATA

#undef PACKET

void on_error(mcnet_parser_t* parser, int err) {
  printf("[%p] error %d\n", parser->data, err);
}

int main() {
  mcnet_parser_t parser = { .data = NULL };
  mcnet_parser_settings_t settings = { .on_packet = on_packet, .on_error = on_error };

  char data[] = {
    0x00, 0x00, 0x00, 0x00, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x02,
    0x17, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0x00, 0x09
  };

  size_t nparsed = 0, offset = 0;

  while ((nparsed = mcnet_parser_execute(&parser, &settings, data + offset, sizeof(data) - offset)) != 0) {
    printf("parsed %d bytes\n", nparsed);
    offset += nparsed;
  }

  return 0;
}
