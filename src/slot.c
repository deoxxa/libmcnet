#include <stdint.h>
#include <stddef.h>

#include "../include/mcnet/error.h"
#include "../include/mcnet/read.h"
#include "../include/mcnet/slot.h"

size_t mcnet_slot_parser_parse(mcnet_slot_parser_t* parser, uint8_t* data, size_t len) {
  mcnet_slot_t slot;
  size_t nparsed = 0;

  slot.item = 0;
  slot.count = 0;
  slot.meta = 0;
  slot.data_len = 0;
  slot.data = NULL;

  if (len < nparsed + 2) {
    return MCNET_EAGAIN;
  }

  slot.item = mcnet_read_int16(data + nparsed);
  nparsed += 2;

  if (slot.item == -1) {
    if (parser && parser->on_complete) { parser->on_complete(parser, &slot); }

    return nparsed;
  }

  if (len < nparsed + 3) {
    return MCNET_EAGAIN;
  }

  slot.count = mcnet_read_int8(data + nparsed);
  nparsed += 1;
  slot.meta = mcnet_read_int16(data + nparsed);
  nparsed += 2;

  if (!((slot.item == 256) || (slot.item == 257) || (slot.item == 258) || (slot.item == 259) || (slot.item == 261) || (slot.item == 267) || (slot.item == 268) || (slot.item == 269) || (slot.item == 270) || (slot.item == 271) || (slot.item == 272) || (slot.item == 273) || (slot.item == 274) || (slot.item == 275) || (slot.item == 276) || (slot.item == 277) || (slot.item == 278) || (slot.item == 279) || (slot.item == 283) || (slot.item == 284) || (slot.item == 285) || (slot.item == 286) || (slot.item == 290) || (slot.item == 291) || (slot.item == 292) || (slot.item == 293) || (slot.item == 294) || (slot.item == 298) || (slot.item == 299) || (slot.item == 300) || (slot.item == 301) || (slot.item == 302) || (slot.item == 303) || (slot.item == 304) || (slot.item == 305) || (slot.item == 306) || (slot.item == 307) || (slot.item == 308) || (slot.item == 309) || (slot.item == 310) || (slot.item == 311) || (slot.item == 312) || (slot.item == 313) || (slot.item == 314) || (slot.item == 315) || (slot.item == 316) || (slot.item == 317) || (slot.item == 346) || (slot.item == 359))) {
    if (parser && parser->on_complete) { parser->on_complete(parser, &slot); }

    return nparsed;
  }

  if (len < nparsed + 2) {
    return MCNET_EAGAIN;
  }

  slot.data_len = mcnet_read_int16(data + nparsed);
  nparsed += 2;

  if (slot.data_len != -1) {
    if (len < nparsed + slot.data_len) {
      return MCNET_EAGAIN;
    }

    slot.data = data + nparsed;
    nparsed += slot.data_len;
  }

  if (parser && parser->on_complete) { parser->on_complete(parser, &slot); }

  return nparsed;
}
