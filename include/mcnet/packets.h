#ifndef MCNET_PACKETS_H
#define MCNET_PACKETS_H

#include <stdint.h>

#include "metadata.h"

#define BOOL(name) int8_t name;
#define BYTE(name) uint8_t name;
#define SHORT(name) int16_t name;
#define INT(name) int32_t name;
#define LONG(name) int64_t name;
#define FLOAT(name) float name;
#define DOUBLE(name) double name;
#define STRING8(name) int16_t name##_len; char* name;
#define STRING16(name) STRING8(name)
#define METADATA(name) int16_t name##_len; mcnet_metadata_t* name;

#define MCNET_PACKET_FIELDS uint8_t pid;

#define PACKET(id, code) typedef struct mcnet_packet_##id##_s { \
  MCNET_PACKET_FIELDS \
  code \
} mcnet_packet_##id##_t;

typedef struct mcnet_packet_s {
  MCNET_PACKET_FIELDS
} mcnet_packet_t;

PACKET(00,
  INT(id)
)

PACKET(01,
  INT(eid)
  STRING16(username)
  STRING16(level_type)
  INT(server_mode)
  INT(dimension)
  BYTE(difficulty)
  BYTE(world_height)
  BYTE(max_players)
)

PACKET(02,
  STRING16(data)
)

PACKET(03,
  STRING16(data)
)

PACKET(04,
  LONG(time)
)

PACKET(05,
  INT(eid)
  SHORT(slot)
  SHORT(itemid)
  SHORT(damage)
)

PACKET(06,
  INT(x)
  INT(y)
  INT(z)
)

PACKET(07,
  INT(user)
  INT(target)
  BYTE(mouse)
)

PACKET(08,
  SHORT(health)
  SHORT(hunger)
  FLOAT(saturation)
)

PACKET(09,
  INT(dimension)
  BYTE(difficulty)
  BYTE(server_mode)
  SHORT(world_height)
  STRING16(level_type)
)

PACKET(0A,
  BYTE(on_ground)
)

PACKET(0B,
  DOUBLE(x)
  DOUBLE(y)
  DOUBLE(stance)
  DOUBLE(z)
  BYTE(on_ground)
)

PACKET(0E,
  BYTE(status)
  SHORT(x)
  BYTE(y)
  SHORT(z)
  BYTE(face)
)

PACKET(0F,
  BYTE(status)
  SHORT(x)
  BYTE(y)
  SHORT(z)
  BYTE(direction)
)

PACKET(10,
  SHORT(slot_id)
)

PACKET(11,
  INT(entity_id)
  BYTE(unused)
  INT(x)
  SHORT(y)
  INT(z)
)

PACKET(12,
  INT(eid)
  BYTE(animation)
)

PACKET(13,
  INT(eid)
  BYTE(action)
)

PACKET(14,
  INT(eid)
  STRING16(name)
  INT(x)
  INT(y)
  INT(z)
  BYTE(yaw)
  BYTE(pitch)
  SHORT(current_item)
)

PACKET(15,
  INT(eid)
  SHORT(item_id)
  BYTE(count)
  SHORT(damage)
  INT(x)
  INT(y)
  INT(z)
  BYTE(rotation)
  BYTE(pitch)
  BYTE(roll)
)

PACKET(16,
  INT(collected)
  INT(collector)
)

PACKET(17,
  INT(eid)
  BYTE(type)
  INT(x)
  INT(y)
  INT(z)
  INT(thrower)
  SHORT(speed_x)
  SHORT(speed_y)
  SHORT(speed_z)
)

PACKET(18,
  INT(eid)
  BYTE(type)
  INT(x)
  INT(y)
  INT(z)
  BYTE(yaw)
  BYTE(pitch)
  BYTE(head_yaw)
  METADATA(metadata)
)

#endif
