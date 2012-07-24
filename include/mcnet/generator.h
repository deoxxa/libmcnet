#ifndef MCNET_GENERATOR_H
#define MCNET_GENERATOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "packets.h"

size_t mcnet_generator_size(mcnet_packet_t* packet);

#ifdef __cplusplus
}
#endif

#endif