{
  'targets': [
    {
      'target_name': 'libmcnet',
      'type': 'static_library',
      'sources': [
        'src/parser.c',
        'src/metadata.c',
        'src/slot.c',
        'src/read.c',
      ],
      'include_dirs': [
        'include',
      ],
    },
  ],
}
