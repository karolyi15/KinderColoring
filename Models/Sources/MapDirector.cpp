//
// Created by gunther on 25/11/20.
//

#include "../Headers/MapDirector.h"

//Constructor
MapDirector::MapDirector(AbstractMapBuilder* builder) {

    this->builder = builder;
}

//Build System
Map * MapDirector::buildWorldMap(char* dataPath, FileManager* fileManager, MapNodeFactory* mapNodeFactory, Painter* painter) {

    MapBuilder* mapBuilder = (MapBuilder*) this->builder;
    mapBuilder->reset();

    mapBuilder->setFileManager(fileManager);
    mapBuilder->setNodeFactory(mapNodeFactory);
    mapBuilder->setPainter(painter);
    mapBuilder->setDataPath(dataPath);

    return mapBuilder->getResult();
}

//Setters & Getters
void MapDirector::changeBuilder(AbstractMapBuilder *builder) {

    this->builder = builder;
}