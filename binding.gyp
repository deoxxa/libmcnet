{
  "targets": [
    {
      "target_name": "libmcnet",
      "type": "static_library",
      "sources": [
        "src/parser.c",
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
        "libmcnet"
      ],
      "sources": [
        "example.c",
      ],
    },
  ],
}
