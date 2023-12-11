cmake_minimum_required(VERSION 3.26.0)
project(program VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all -O2"
    CACHE STRING "Compiler flags in asan build"
    FORCE)

set(CMAKE_CXX_FLAGS_SHADREL "-O2 -DNDEBUG"
    CACHE STRING "Compiler flags for the release version that executes on Yandex.Contest"
    FORCE)

message("General compiler flags: " ${CMAKE_CXX_FLAGS})
message("Debug build compiler flags: " ${CMAKE_CXX_FLAGS_DEBUG})
message("ASAN build compiler flags: " ${CMAKE_CXX_FLAGS_ASAN})
message("ShadRel build compiler flags: " ${CMAKE_CXX_FLAGS_SHADREL})
file(GLOB_RECURSE SOURCES "*src/*.cpp")
file(GLOB_RECURSE HEADERS "*src/*.h")
file(COPY config.txt DESTINATION ${CMAKE_BINARY_DIR})



#main program
add_executable(program ${SOURCES} ${HEADERS})

find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )
target_link_libraries( program ${CURSES_LIBRARIES} )