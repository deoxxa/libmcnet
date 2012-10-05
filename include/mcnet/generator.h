#ifndef MCNET_GENERATOR_H
#define MCNET_GENERATOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

#include "packets.h"

typedef struct mcnet_generator_s {
  char type;
} mcnet_generator_t;

size_t mcnet_generator_size(mcnet_generator_t* generator, mcnet_packet_t* packet);
size_t mcnet_generator_write(mcnet_generator_t* generator, mcnet_packet_t* packet, uint8_t* out);

#ifdef __cplusplus
}
#endif

#endif
