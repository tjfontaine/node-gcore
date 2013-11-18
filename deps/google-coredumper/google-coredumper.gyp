{
  'targets': [
    {
      'target_name': 'coredumper',
      'library': 'static_library',
      'type': 'static_library',
      'cflags': [ '-fPIC' ],
      'sources': [
        'src/coredumper.c',
        'src/coredumper.h',
        'src/thread_lister.c',
        'src/thread_lister.h',
        'src/elfcore.c',
        'src/elfcore.h',
        'src/linuxthreads.c',
        'src/linuxthreads.h',
	'src/linux_syscall_support.h',
	'src/google/coredumper.h',
      ],
      'link_settings': {
        'libraries': [
        ],
      },
    },
  ],
}
