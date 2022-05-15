set (CMAKE_SYSTEM_NAME "Generic"             CACHE STRING "")
set (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER CACHE STRING "")
set (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY NEVER CACHE STRING "")
set (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER CACHE STRING "")

set (CMAKE_C_COMPILER   "${CROSS_PREFIX}gcc")
set (CMAKE_CXX_COMPILER "${CROSS_PREFIX}g++")
# _exit is in the BSP rather than in libgcc, leaving this out
# causes errors in try_compile on ARM generic.
set (CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# vim: expandtab:ts=2:sw=2:smartindent
