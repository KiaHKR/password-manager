cmake_minimum_required(VERSION 3.1...3.29)


project(
  ModernCMakeExample
  VERSION 1.0
  LANGUAGES CXX)


  set(SOURCE_FILES
  src/math/3d_circle.cpp
  src/path_finding.cpp
  src/spacial_conv.cpp
  src/mark2_0_fixed.cpp
  src/motors.cpp
  src/robot.cpp
)

add_executable(PasswordManager ${SOURCE_FILES})