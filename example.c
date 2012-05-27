#include <stdio.h>
#include <stdlib.h>

#include <mcnet.h>

void on_packet(mcnet_parser_t* parser, mcnet_packet_t* packet) {
  printf("[%p] packet type: %02x\n", parser->data, packet->pid);

  if (packet->pid == 0x00) {
    mcnet_packet_00_t* packet_00 = (mcnet_packet_00_t*)packet;
    printf("-> id: %d\n", packet_00->id);
  }
}

void on_error(mcnet_parser_t* parser, int err) {
  printf("[%p] error %d\n", parser->data, err);
}

int main() {
  mcnet_parser_t parser = { .data = NULL };
  mcnet_parser_settings_t settings = { .on_packet = on_packet, .on_error = on_error };

  char data[] = { 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02 };

  size_t nparsed = 0, offset = 0;

  while ((nparsed = mcnet_parser_execute(&parser, &settings, data + offset, 10 - offset)) != 0) {
    printf("parsed %d bytes\n", nparsed);
    offset += nparsed;
  }

  return 0;
}
