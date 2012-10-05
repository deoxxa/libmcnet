#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mcnet.h>

int test_id = 0;

int main(int argc, char** argv) {
  mcnet_metadata_t metadata;
  metadata.count = 1;
  metadata.entries = malloc(sizeof(void *) * metadata.count);
  metadata.entries[0] = malloc(sizeof(mcnet_metadata_entry_byte_t));
  ((mcnet_metadata_entry_byte_t*)metadata.entries[0])->data = 1;
  
  return 0;
}
