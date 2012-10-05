CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(libmcnet)

INCLUDE_DIRECTORIES(include)

SET(CMAKE_C_FLAGS "-std=c99")

ADD_LIBRARY(mcnet
  src/metadata.c
  src/parser.c
  src/read.c
  src/slot.c
)

ADD_EXECUTABLE(example
  example.c
)
ADD_DEPENDENCIES(example mcnet)
TARGET_LINK_LIBRARIES(example mcnet)
