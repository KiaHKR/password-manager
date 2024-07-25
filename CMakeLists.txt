cmake_minimum_required(VERSION 3.10)

project(
  PasswordManager
  VERSION 1.0
  LANGUAGES CXX
)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCE_FILES
  src/Main.cpp
  src/PasswordManager.cpp
  src/FileManager.cpp
  src/HelperFunctions.cpp
)

find_package(Boost REQUIRED CONFIG)

add_executable(PasswordManager ${SOURCE_FILES})

target_link_libraries(PasswordManager PRIVATE Boost)
