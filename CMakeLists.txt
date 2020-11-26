cmake_minimum_required(VERSION 3.17)
project(KinderColoring)

set(CMAKE_CXX_STANDARD 14)

add_executable(KinderColoring main.cpp FileManagers/Sources/XmlManager.cpp FileManagers/Headers/XmlManager.h ../DataStructures/Headers/Node.h ../DataStructures/Headers/LinkedList.h ../DataStructures/Headers/GraphBuilder.h ../DataStructures/Headers/MapGraph.h Painters/Sources/Painter.cpp Painters/Headers/Painter.h Painters/Sources/DivideConquerPainter.cpp Painters/Headers/DivideConquerPainter.h Painters/Sources/DynamicPainter.cpp Painters/Headers/DynamicPainter.h Painters/Sources/BacktrackingPainter.cpp Painters/Headers/BacktrackingPainter.h Models/Sources/ColorType.cpp Models/Headers/ColorType.h Models/Sources/MapNode.cpp Models/Headers/MapNode.h Models/Sources/MapNodeFactory.cpp Models/Headers/MapNodeFactory.h Models/Sources/CountryFactory.cpp Models/Headers/CountryFactory.h Models/Sources/Country.cpp Models/Headers/Country.h FileManagers/Sources/StringSplitter.cpp FileManagers/Headers/StringSplitter.h Models/Sources/MapDirector.cpp Models/Headers/MapDirector.h Models/Sources/MapBuilder.cpp Models/Headers/MapBuilder.h Models/Sources/Map.cpp Models/Headers/Map.h Models/Sources/AbstractMapBuilder.cpp Models/Headers/AbstractMapBuilder.h FileManagers/Sources/FileManager.cpp FileManagers/Headers/FileManager.h FileManagers/Sources/FileManagerFactory.cpp FileManagers/Headers/FileManagerFactory.h Painters/Sources/PainterFactory.cpp Painters/Headers/PainterFactory.h)

include_directories("_Libraries/rapidxml-1.13")
