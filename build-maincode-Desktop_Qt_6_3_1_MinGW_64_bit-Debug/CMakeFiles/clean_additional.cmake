# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\mainCode_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\mainCode_autogen.dir\\ParseCache.txt"
  "mainCode_autogen"
  )
endif()
