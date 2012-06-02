#include <stdint.h>
#include <stddef.h>

#include "../include/mcnet/error.h"
#include "../include/mcnet/read.h"
#include "../include/mcnet/metadata.h"

size_t mcnet_metadata_parser_parse(mcnet_metadata_parser_t* parser, uint8_t* data, size_t len) {
  size_t nparsed = 0, this_round = 0;

  while (1) {
    this_round = mcnet_metadata_parser_execute(parser, data + nparsed, len - nparsed);

    if ((this_round == MCNET_EAGAIN) || (this_round == MCNET_EINVALID)) {
      return this_round;
    }

    nparsed += this_round;

    if (this_round == 1) {
      break;
    }
  }

  return nparsed;
}

size_t mcnet_metadata_parser_execute(mcnet_metadata_parser_t* parser, uint8_t* data, size_t len) {
  size_t nparsed = 0;

  if (len < nparsed + 1) {
    return MCNET_EAGAIN;
  }

  uint8_t x = *(data + nparsed);
  nparsed += 1;

  if (x == 127) {
    return nparsed;
  }

  uint8_t index = x &  0x1F,
          type  = x >> 5;

  switch (type) {
    case 0: {
      mcnet_metadata_entry_byte_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 1) { return MCNET_EAGAIN; }
      entry.data = mcnet_read_int8(data + nparsed);
      nparsed += 1;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case 1: {
      mcnet_metadata_entry_short_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 2) { return MCNET_EAGAIN; }
      entry.data = mcnet_read_int16(data + nparsed);
      nparsed += 2;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case 2: {
      mcnet_metadata_entry_int_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 4) { return MCNET_EAGAIN; }
      entry.data = mcnet_read_int32(data + nparsed);
      nparsed += 4;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case 3: {
      mcnet_metadata_entry_float_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 4) { return MCNET_EAGAIN; }
      entry.data = mcnet_read_float(data + nparsed);
      nparsed += 4;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case 4: {
      mcnet_metadata_entry_string16_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 2) { return MCNET_EAGAIN; }
      entry.data_length = mcnet_read_int16(data + nparsed);
      nparsed += 2;

      if (len < nparsed + entry.data_length * 2) { return MCNET_EAGAIN; }
      entry.data = data;
      nparsed += entry.data_length * 2;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case 5: {
      mcnet_metadata_entry_sbs_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 5) { return MCNET_EAGAIN; }

      entry.id = mcnet_read_int16(data + nparsed);
      nparsed += 2;
      entry.count = mcnet_read_int8(data + nparsed);
      nparsed += 1;
      entry.damage = mcnet_read_int16(data + nparsed);
      nparsed += 2;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case 6: {
      mcnet_metadata_entry_iii_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 12) { return MCNET_EAGAIN; }

      entry.data[0] = mcnet_read_int32(data + nparsed);
      nparsed += 4;
      entry.data[1] = mcnet_read_int32(data + nparsed);
      nparsed += 4;
      entry.data[2] = mcnet_read_int32(data + nparsed);
      nparsed += 4;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    default: {
      if (parser && parser->on_error) { parser->on_error(parser, MCNET_EINVALID); }

      return MCNET_EINVALID;
    }
  }
}
