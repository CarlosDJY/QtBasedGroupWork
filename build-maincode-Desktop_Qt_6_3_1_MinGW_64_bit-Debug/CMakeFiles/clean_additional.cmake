# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\maincode_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\maincode_autogen.dir\\ParseCache.txt"
  "maincode_autogen"
  )
endif()
