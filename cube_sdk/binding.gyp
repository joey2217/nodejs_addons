{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "addon.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "cube/include",
      ],
      'link_settings': {
        'library_dirs': [
          'cube/lib',
          'cube/dll',
        ],
        'libraries':[
          'cube_api64'
        ]
      }
    }
  ]
}
