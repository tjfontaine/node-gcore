{
  'targets': [
    {
      'target_name': 'gcore',
      'sources': [ 'src/gcore.cc' ],
      'conditions': [
        [ 'OS=="linux"', {
          'dependencies': [ 'deps/google-coredumper/google-coredumper.gyp:coredumper', ],
          'include_dirs': [ 'deps/google-coredumper/src', ],
          'sources': [ 'src/linux.cc', ]
        }],
      ],
    }
  ]
}
