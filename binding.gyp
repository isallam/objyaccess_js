{
  "targets": [
    {
      'target_name': "addon",
      'include_dirs' : [
        "<!(node -e \"require('nan')\")",
        "/opt/Objectivity/12.5/include"
      ],
      'sources': [
        'addon.cpp', 'objyAccess.cpp'
      ],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'link_settings': {
        'library_dirs': [
          '/opt/Objectivity/12.5/lib',
        ],
        'libraries': [
          '-loo.12.5', '-looSessionManager.12.5', '-looObjectModel.12.5', 
          '-looData.12.5', '-looPolicy.12.5', '-looStatement.12.5'
        ],
      },
    }
  ]
}
