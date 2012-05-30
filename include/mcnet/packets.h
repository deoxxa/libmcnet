#ifndef MCNET_PACKETS_H
#define MCNET_PACKETS_H

#define PACKETS \
PACKET(00, UBYTE(pid) INT(id)) \
PACKET(01, UBYTE(pid) INT(eid) STRING16(username) STRING16(level_type) INT(server_mode) INT(dimension) BYTE(difficulty) UBYTE(world_height) BYTE(max_players)) \
PACKET(02, UBYTE(pid) STRING16(data)) \
PACKET(03, UBYTE(pid) STRING16(data)) \
PACKET(04, UBYTE(pid) LONG(time)) \
PACKET(05, UBYTE(pid) INT(eid) SHORT(slot) SHORT(itemid) SHORT(damage)) \
PACKET(06, UBYTE(pid) INT(x) INT(y) INT(z)) \
PACKET(07, UBYTE(pid) INT(user) INT(target) BYTE(mouse)) \
PACKET(08, UBYTE(pid) SHORT(health) SHORT(hunger) FLOAT(saturation)) \
PACKET(09, UBYTE(pid) INT(dimension) BYTE(difficulty) BYTE(server_mode) SHORT(world_height) STRING16(level_type)) \
PACKET(0A, UBYTE(pid) BYTE(on_ground)) \
PACKET(0B, UBYTE(pid) DOUBLE(x) DOUBLE(y) DOUBLE(stance) DOUBLE(z) BYTE(on_ground)) \
PACKET(0E, UBYTE(pid) BYTE(status) SHORT(x) BYTE(y) SHORT(z) BYTE(face)) \
PACKET(0F, UBYTE(pid) BYTE(status) SHORT(x) BYTE(y) SHORT(z) BYTE(direction)) \
PACKET(10, UBYTE(pid) SHORT(slot_id)) \
PACKET(11, UBYTE(pid) INT(eid) BYTE(unused) INT(x) SHORT(y) INT(z)) \
PACKET(12, UBYTE(pid) INT(eid) BYTE(animation)) \
PACKET(13, UBYTE(pid) INT(eid) BYTE(action)) \
PACKET(14, UBYTE(pid) INT(eid) STRING16(name) INT(x) INT(y) INT(z) BYTE(yaw) BYTE(pitch) SHORT(current_item)) \
PACKET(15, UBYTE(pid) INT(eid) SHORT(item_id) BYTE(count) SHORT(damage) INT(x) INT(y) INT(z) BYTE(rotation) BYTE(pitch) BYTE(roll)) \
PACKET(16, UBYTE(pid) INT(eid) INT(collected_by)) \
PACKET(17, UBYTE(pid) INT(eid) BYTE(type) INT(x) INT(y) INT(z) INT(thrower) SHORT(speed_x) SHORT(speed_y) SHORT(speed_z)) \
PACKET(18, UBYTE(pid) INT(eid) BYTE(type) INT(x) INT(y) INT(z) BYTE(yaw) BYTE(pitch) BYTE(head_yaw) METADATA(metadata)) \
PACKET(19, UBYTE(pid) INT(eid) STRING16(title) INT(x) INT(y) INT(z) INT(direction)) \
PACKET(1A, UBYTE(pid) INT(eid) INT(x) INT(y) INT(z) SHORT(count)) \
PACKET(1C, UBYTE(pid) INT(eid) SHORT(x) SHORT(y) SHORT(z)) \
PACKET(1D, UBYTE(pid) INT(eid)) \
PACKET(1E, UBYTE(pid) INT(eid)) \
PACKET(1F, UBYTE(pid) INT(eid) BYTE(x) BYTE(y) BYTE(z)) \
PACKET(20, UBYTE(pid) INT(eid) BYTE(yaw) BYTE(pitch)) \
PACKET(21, UBYTE(pid) INT(eid) BYTE(x) BYTE(y) BYTE(z) BYTE(yaw) BYTE(pitch)) \
PACKET(22, UBYTE(pid) INT(eid) INT(x) INT(y) INT(z) BYTE(yaw) BYTE(pitch)) \
PACKET(23, UBYTE(pid) INT(eid) BYTE(yaw)) \
PACKET(26, UBYTE(pid) INT(eid) BYTE(status)) \
PACKET(27, UBYTE(pid) INT(eid) INT(attached_to)) \
PACKET(28, UBYTE(pid) INT(eid) METADATA(metadata)) \
PACKET(29, UBYTE(pid) INT(eid) BYTE(effect) BYTE(amplification) SHORT(duration)) \
PACKET(2A, UBYTE(pid) INT(eid) BYTE(effect))

#endif
