cmake_minimum_required(VERSION 3.17)
project(KinderColoring)

set(CMAKE_CXX_STANDARD 14)

add_executable(KinderColoring main.cpp Sources/XmlManager.cpp Headers/XmlManager.h)

include_directories("Libraries/rapidxml-1.13")
