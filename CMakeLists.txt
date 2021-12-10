cmake_minimum_required(VERSION 3.10)

project(windfish C)

set(WINDFISH_EXE_NAME windfish)
set(WINDFISH_LIB_NAME libwindfish)

set(CMAKE_MODULE_PATH "${windfish_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(SDL2 REQUIRED)

set(WINDFISH_LINK_DIRS
  ${SDL2_LIBRARY}
)

set(WINDFISH_INCLUDE_DIRS
  ${SDL2_INCLUDE_DIR}
)

set(WINDFISH_LINK_LIBRARIES
  ${SDL2_LIBRARY}
)

include_directories(
  src
  ${WINDFISH_INCLUDE_DIRS}
)

link_directories(
  ${WINDFISH_LINK_DIRS}
)

set(WINDFISH_SRC
  src/engine.c
  src/graphics.c
  src/statemanager.c
)

message("SDL2_LIBRARY: ${SDL2_LIBRARY}")
message("SDL_LINK_DIR: ${SDL_LINK_DIR}")
message("SDL2_INCLUDE_DIR: ${SDL2_INCLUDE_DIR}")

add_library(${WINDFISH_LIB_NAME} SHARED ${WINDFISH_SRC})
target_link_libraries(${WINDFISH_LIB_NAME} ${WINDFISH_LINK_LIBRARIES})

add_executable(${WINDFISH_EXE_NAME} src/windfish.c)
target_link_libraries(${WINDFISH_EXE_NAME} ${WINDFISH_LIB_NAME})

# tests
enable_testing()
add_executable(statemanager_test src/statemanager.test.c)
target_link_libraries(statemanager_test ${WINDFISH_LIB_NAME})

add_test(NAME statemanager_test COMMAND statemanager_test)