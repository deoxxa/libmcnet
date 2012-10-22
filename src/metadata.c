#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "../include/mcnet/error.h"
#include "../include/mcnet/read.h"
#include "../include/mcnet/write.h"
#include "../include/mcnet/metadata.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t mcnet_metadata_parser_parse(mcnet_metadata_parser_t* parser, uint8_t* data, size_t len) {
  size_t nparsed = 0, this_round = 0;

  while (1) {
    this_round = mcnet_metadata_parser_execute(parser, data + nparsed, len - nparsed);

    if ((this_round == MCNET_EAGAIN) || (this_round == MCNET_EINVALID)) {
      return this_round;
    }

    nparsed += this_round;

    if (this_round == 1) {
      if (parser && parser->on_complete) { parser->on_complete(parser); }

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
    case MCNET_METADATA_TYPE_BYTE: {
      mcnet_metadata_entry_byte_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 1) { return MCNET_EAGAIN; }
      entry.data = mcnet_read_int8(data + nparsed);
      nparsed += 1;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case MCNET_METADATA_TYPE_SHORT: {
      mcnet_metadata_entry_short_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 2) { return MCNET_EAGAIN; }
      entry.data = mcnet_read_int16(data + nparsed);
      nparsed += 2;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case MCNET_METADATA_TYPE_INT: {
      mcnet_metadata_entry_int_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 4) { return MCNET_EAGAIN; }
      entry.data = mcnet_read_int32(data + nparsed);
      nparsed += 4;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case MCNET_METADATA_TYPE_FLOAT: {
      mcnet_metadata_entry_float_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 4) { return MCNET_EAGAIN; }
      entry.data = mcnet_read_float(data + nparsed);
      nparsed += 4;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case MCNET_METADATA_TYPE_STRING16: {
      mcnet_metadata_entry_string16_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 2) { return MCNET_EAGAIN; }
      entry.data_length = mcnet_read_int16(data + nparsed);
      nparsed += 2;

      if (len < nparsed + entry.data_length * 2) { return MCNET_EAGAIN; }
      entry.data = data + nparsed;
      nparsed += entry.data_length * 2;

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case MCNET_METADATA_TYPE_SLOT: {
      mcnet_metadata_entry_sbs_t entry;

      entry.type = type;
      entry.index = index;

      if (len < nparsed + 2) { return MCNET_EAGAIN; }

      entry.id = mcnet_read_int16(data + nparsed);
      nparsed += 2;

      if (entry.id >= 0) {
        if (len < nparsed + 3) { return MCNET_EAGAIN; }

        entry.count = mcnet_read_int8(data + nparsed);
        nparsed += 1;
        entry.damage = mcnet_read_int16(data + nparsed);
        nparsed += 2;
      }

      if (parser && parser->on_entry) { parser->on_entry(parser, (mcnet_metadata_entry_t*)&entry); }

      return nparsed;
    }
    case MCNET_METADATA_TYPE_INTS: {
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

size_t mcnet_metadata_generator_size(mcnet_metadata_t* metadata) {
  size_t res = 0;

  int i;
  for (i = 0; i < metadata->count; ++i) {
    res += 1;

    if (metadata->entries[i] == NULL) {
      return MCNET_EINVALID;
    }

    switch (metadata->entries[i]->type) {
      case MCNET_METADATA_TYPE_BYTE: {
        res += 1;
        break;
      }
      case MCNET_METADATA_TYPE_SHORT: {
        res += 2;
        break;
      }
      case MCNET_METADATA_TYPE_INT: {
        res += 4;
        break;
      }
      case MCNET_METADATA_TYPE_FLOAT: {
        res += 4;
        break;
      }
      case MCNET_METADATA_TYPE_STRING16: {
        mcnet_metadata_entry_string16_t* _entry = (mcnet_metadata_entry_string16_t*)(metadata->entries[i]);
        res += 2;
        res += _entry->data_length;
        break;
      }
      case MCNET_METADATA_TYPE_SLOT: {
        mcnet_metadata_entry_sbs_t* _entry = (mcnet_metadata_entry_sbs_t*)(metadata->entries[i]);
        res += 2;
        if (_entry->id >= 0) {
          res += 3;
        }
        break;
      }
      case MCNET_METADATA_TYPE_INTS: {
        res += 12;
        break;
      }
    }
  }

  res += 1;

  return res;
}

size_t mcnet_metadata_generator_write(mcnet_metadata_t* metadata, uint8_t* out) {
  size_t offset = 0;

  int i;
  for (i = 0; i < metadata->count; ++i) {
    out[offset] = ((metadata->entries[i]->type & 0x08) << 5) + (metadata->entries[i]->index & 0xe0);
    offset += 1;

    if (metadata->entries[i] == NULL) {
      return MCNET_EINVALID;
    }

    switch (metadata->entries[i]->type) {
      case MCNET_METADATA_TYPE_BYTE: {
        mcnet_metadata_entry_byte_t* _entry = (mcnet_metadata_entry_byte_t*)(metadata->entries[i]);
        out[offset] = _entry->data;
        offset += 1;
        break;
      }
      case MCNET_METADATA_TYPE_SHORT: {
        mcnet_metadata_entry_short_t* _entry = (mcnet_metadata_entry_short_t*)(metadata->entries[i]);
        mcnet_write_int16(out + offset, _entry->data);
        offset += 2;
        break;
      }
      case MCNET_METADATA_TYPE_INT: {
        mcnet_metadata_entry_int_t* _entry = (mcnet_metadata_entry_int_t*)(metadata->entries[i]);
        mcnet_write_int32(out + offset, _entry->data);
        offset += 4;
        break;
      }
      case MCNET_METADATA_TYPE_FLOAT: {
        mcnet_metadata_entry_float_t* _entry = (mcnet_metadata_entry_float_t*)(metadata->entries[i]);
        mcnet_write_float(out + offset, _entry->data);
        offset += 4;
        break;
      }
      case MCNET_METADATA_TYPE_STRING16: {
        mcnet_metadata_entry_string16_t* _entry = (mcnet_metadata_entry_string16_t*)(metadata->entries[i]);
        mcnet_write_uint16(out + offset, _entry->data_length);
        offset += 2;
        memcpy(out + offset, _entry->data, _entry->data_length * 2);
        offset += _entry->data_length * 2;
        break;
      }
      case MCNET_METADATA_TYPE_SLOT: {
        mcnet_metadata_entry_sbs_t* _entry = (mcnet_metadata_entry_sbs_t*)(metadata->entries[i]);
        mcnet_write_uint16(out + offset, _entry->id);
        offset += 2;
        if (_entry->id >= 0) {
          mcnet_write_uint16(out + offset, _entry->count);
          offset += 1;
          mcnet_write_uint16(out + offset, _entry->damage);
          offset += 2;
        }
        break;
      }
      case MCNET_METADATA_TYPE_INTS: {
        mcnet_metadata_entry_iii_t* _entry = (mcnet_metadata_entry_iii_t*)(metadata->entries[i]);
        mcnet_write_uint32(out + offset, _entry->data[0]);
        offset += 4;
        mcnet_write_uint32(out + offset, _entry->data[1]);
        offset += 4;
        mcnet_write_uint32(out + offset, _entry->data[2]);
        offset += 4;
        break;
      }
    }
  }

  out[offset] = 0x7f;

  return offset;
}

#ifdef __cplusplus
}
#endif
