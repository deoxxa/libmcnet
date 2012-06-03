#ifndef MCNET_PACKETS_H
#define MCNET_PACKETS_H

#define PACKETS \
PACKET(00, INT(id)) \
PACKET(01, INT(eid) STRING16(username) STRING16(level_type) INT(server_mode) INT(dimension) BYTE(difficulty) UBYTE(world_height) BYTE(max_players)) \
PACKET(02, STRING16(data)) \
PACKET(03, STRING16(data)) \
PACKET(04, LONG(time)) \
PACKET(05, INT(eid) SHORT(slot) SHORT(itemid) SHORT(damage)) \
PACKET(06, INT(x) INT(y) INT(z)) \
PACKET(07, INT(user) INT(target) BYTE(mouse)) \
PACKET(08, SHORT(health) SHORT(hunger) FLOAT(saturation)) \
PACKET(09, INT(dimension) BYTE(difficulty) BYTE(server_mode) SHORT(world_height) STRING16(level_type)) \
PACKET(0A, BYTE(on_ground)) \
PACKET(0B, DOUBLE(x) DOUBLE(y) DOUBLE(stance) DOUBLE(z) BYTE(on_ground)) \
PACKET(0C, FLOAT(yaw) FLOAT(pitch) BOOL(on_ground)) \
PACKET(0D, DOUBLE(x) DOUBLE(y) DOUBLE(stance) DOUBLE(z) FLOAT(yaw) FLOAT(pitch) BOOL(on_ground)) \
PACKET(0E, BYTE(status) SHORT(x) BYTE(y) SHORT(z) BYTE(face)) \
PACKET(0F, BYTE(status) SHORT(x) BYTE(y) SHORT(z) BYTE(direction)) \
PACKET(10, SHORT(slot_id)) \
PACKET(11, INT(eid) BYTE(unused) INT(x) SHORT(y) INT(z)) \
PACKET(12, INT(eid) BYTE(animation)) \
PACKET(13, INT(eid) BYTE(action)) \
PACKET(14, INT(eid) STRING16(name) INT(x) INT(y) INT(z) BYTE(yaw) BYTE(pitch) SHORT(current_item)) \
PACKET(15, INT(eid) SHORT(item_id) BYTE(count) SHORT(damage) INT(x) INT(y) INT(z) BYTE(rotation) BYTE(pitch) BYTE(roll)) \
PACKET(16, INT(eid) INT(collected_by)) \
PACKET(17, INT(eid) BYTE(type) INT(x) INT(y) INT(z) INT(thrower) SHORT(speed_x) SHORT(speed_y) SHORT(speed_z)) \
PACKET(18, INT(eid) BYTE(type) INT(x) INT(y) INT(z) BYTE(yaw) BYTE(pitch) BYTE(head_yaw) METADATA(metadata)) \
PACKET(19, INT(eid) STRING16(title) INT(x) INT(y) INT(z) INT(direction)) \
PACKET(1A, INT(eid) INT(x) INT(y) INT(z) SHORT(count)) \
PACKET(1C, INT(eid) SHORT(x) SHORT(y) SHORT(z)) \
PACKET(1D, INT(eid)) \
PACKET(1E, INT(eid)) \
PACKET(1F, INT(eid) BYTE(x) BYTE(y) BYTE(z)) \
PACKET(20, INT(eid) BYTE(yaw) BYTE(pitch)) \
PACKET(21, INT(eid) BYTE(x) BYTE(y) BYTE(z) BYTE(yaw) BYTE(pitch)) \
PACKET(22, INT(eid) INT(x) INT(y) INT(z) BYTE(yaw) BYTE(pitch)) \
PACKET(23, INT(eid) BYTE(yaw)) \
PACKET(26, INT(eid) BYTE(status)) \
PACKET(27, INT(eid) INT(attached_to)) \
PACKET(28, INT(eid) METADATA(metadata)) \
PACKET(29, INT(eid) BYTE(effect) BYTE(amplification) SHORT(duration)) \
PACKET(2A, INT(eid) BYTE(effect)) \
PACKET(2B, FLOAT(experience_bar) SHORT(level) SHORT(experience)) \
PACKET(32, INT(x) INT(z) BOOL(mode)) \
PACKET(33, INT(x) INT(z) BOOL(solid) USHORT(primary_bitmap) USHORT(add_bitmap) INT(data_len) INT(unused) BLOB(data, data_len)) \
PACKET(34, INT(x) INT(z) SHORT(count) INT(data_len) BLOB(data, data_len)) \
PACKET(35, INT(x) BYTE(y) INT(z) BYTE(type) BYTE(meta)) \
PACKET(36, INT(x) BYTE(y) INT(z) BYTE(one) BYTE(two)) \
PACKET(3C, DOUBLE(x) DOUBLE(y) DOUBLE(z) FLOAT(radius) INT(count) BLOB(data, count * 3)) \
PACKET(3D, INT(effect_id) INT(x) BYTE(y) INT(z) INT(data)) \
PACKET(46, BYTE(reason) BYTE(mode)) \
PACKET(47, INT(eid) BOOL(unknown) INT(x) INT(y) INT(z)) \
PACKET(64, BYTE(window) BYTE(type) STRING16(title) BYTE(slots)) \
PACKET(65, BYTE(window)) \
PACKET(66, BYTE(window) SHORT(slot) BYTE(right_click) SHORT(action) BOOL(shift) SLOT(slot_data)) \
PACKET(67, BYTE(window) SHORT(slot) SLOT(slot_data)) \
PACKET(68, BYTE(window) SHORT(count) SLOTS(slot_data, count)) \
PACKET(69, BYTE(window) SHORT(property) SHORT(value)) \
PACKET(6A, BYTE(window) SHORT(action) BOOL(accepted)) \
PACKET(6B, SHORT(slot) SLOT(slot_data)) \
PACKET(6C, BYTE(window) BYTE(echantment)) \
PACKET(82, INT(x) SHORT(y) INT(z) STRING16(line1) STRING16(line2) STRING16(line3) STRING16(line4)) \
PACKET(83, SHORT(type) SHORT(id) UBYTE(data_len) BLOB(data, data_len)) \
PACKET(84, INT(x) SHORT(y) INT(z) BYTE(action) INT(custom1) INT(custom2) INT(custom3)) \
PACKET(C8, INT(statistic) BYTE(amount)) \
PACKET(C9, STRING16(name) BOOL(online) SHORT(ping)) \
PACKET(CA, BOOL(invincible) BOOL(flying) BOOL(can_fly) BOOL(instant_destroy)) \
PACKET(FA, STRING16(channel) SHORT(data_length) BLOB(data, data_length)) \
PACKET(FE, ) \
PACKET(FF, STRING16(reason))

#endif
