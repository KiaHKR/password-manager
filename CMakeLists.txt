cmake_minimum_required(VERSION 3.15)
include(FetchContent)


project(PasswordManager VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files for the project
set(SOURCE_FILES
  src/Main.cpp
  src/PasswordManager.cpp
  src/HelperFunctions.cpp
)

FetchContent_Declare(Sodium GIT_REPOSITORY https://github.com/robinlinden/libsodium-cmake.git)

set(SODIUM_DISABLE_TESTS ON)
FetchContent_MakeAvailable(Sodium)

# Define the executable
add_executable(PasswordManager ${SOURCE_FILES})

# Include directories
target_include_directories(PasswordManager PRIVATE 
  ${PROJECT_SOURCE_DIR}/include
)

# Link Boost libraries
target_link_libraries(PasswordManager PRIVATE sodium)
