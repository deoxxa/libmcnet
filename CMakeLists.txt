CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(libmcnet)

INCLUDE_DIRECTORIES(include)

SET(CMAKE_C_FLAGS "-std=c99")

ADD_LIBRARY(mcnet
  src/generator.c
  src/metadata.c
  src/parser.c
  src/read.c
  src/slot.c
  src/write.c
)

ADD_EXECUTABLE(example
  example.c
)
ADD_DEPENDENCIES(example mcnet)
TARGET_LINK_LIBRARIES(example mcnet)

ADD_EXECUTABLE(test-packets
  tests/packets.c
)
ADD_DEPENDENCIES(test-packets mcnet)
TARGET_LINK_LIBRARIES(test-packets mcnet)

ADD_EXECUTABLE(test-metadata
  tests/metadata.c
)
ADD_DEPENDENCIES(test-metadata mcnet)
TARGET_LINK_LIBRARIES(test-metadata mcnet)

ADD_EXECUTABLE(test-slot
  tests/slot.c
)
ADD_DEPENDENCIES(test-slot mcnet)
TARGET_LINK_LIBRARIES(test-slot mcnet)
