cmake_minimum_required(VERSION 3.17)
project(KinderColoring)

set(CMAKE_CXX_STANDARD 14)

add_executable(KinderColoring main.cpp Sources/XmlManager.cpp Headers/XmlManager.h Sources/Country.cpp Headers/Country.h ../DataStructures/Headers/Node.h ../DataStructures/Headers/LinkedList.cpp ../DataStructures/Headers/LinkedList.h ../DataStructures/Headers/GraphBuilder.h ../DataStructures/Headers/MapGraph.h Sources/SvgManager.cpp Headers/SvgManager.h)

include_directories("_Libraries/rapidxml-1.13")
