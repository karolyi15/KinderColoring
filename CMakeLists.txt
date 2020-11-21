cmake_minimum_required(VERSION 3.17)
project(KinderColoring)

set(CMAKE_CXX_STANDARD 14)

add_executable(KinderColoring main.cpp Sources/XmlManager.cpp Headers/XmlManager.h Sources/Country.cpp Headers/Country.h Sources/SvgManager.cpp Headers/SvgManager.h Sources/SvgManager.cpp Sources/Painter.cpp Headers/Painter.h Sources/DivideConquerPainter.cpp Headers/DivideConquerPainter.h Sources/DynamicPainter.cpp Headers/DynamicPainter.h Sources/BacktrackingPainter.cpp Headers/BacktrackingPainter.h)

include_directories("_Libraries/rapidxml-1.13")
