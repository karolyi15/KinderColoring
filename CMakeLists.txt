cmake_minimum_required(VERSION 3.17)
project(KinderColoring)

set(CMAKE_CXX_STANDARD 14)

add_executable(KinderColoring main.cpp Sources/XmlManager.cpp Headers/XmlManager.h Sources/Country.cpp Headers/Country.h Sources/Node.cpp Headers/Node.h Sources/LinkedList.cpp Headers/LinkedList.h)

include_directories("_Libraries/rapidxml-1.13")
