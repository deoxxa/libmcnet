{
  "targets": [
    {
      "target_name": "libmcnet",
      "type": "static_library",
      "sources": [
        "src/parser.c",
        "src/generator.c",
        "src/metadata.c",
        "src/slot.c",
        "src/read.c",
        "src/write.c",
      ],
      "include_dirs": [
        "./include",
      ],
      "direct_dependent_settings": {
        "include_dirs": [
          "./include",
        ],
      },
    },
    {
      "target_name": "example",
      "type": "executable",
      "dependencies": [
        "libmcnet",
      ],
      "sources": [
        "example.c",
      ],
    },
    {
      "target_name": "test-packets",
      "type": "executable",
      "dependencies": [
        "libmcnet",
      ],
      "sources": [
        "tests/packets.c",
      ],
    },
    {
      "target_name": "test-metadata",
      "type": "executable",
      "dependencies": [
        "libmcnet",
      ],
      "sources": [
        "tests/metadata.c",
      ],
    },
    {
      "target_name": "test-slot",
      "type": "executable",
      "dependencies": [
        "libmcnet",
      ],
      "sources": [
        "tests/slot.c",
      ],
    },
  ],
}
