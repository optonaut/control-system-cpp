
cmake_minimum_required(VERSION 2.8)
project(optonaut-stitcher)
include(GNUInstallDirs)

find_package( OpenCV REQUIRED )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wunreachable-code -std=c++1y -g -O0 -Werror")
add_subdirectory(tests)
