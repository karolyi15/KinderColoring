//
// Created by gunther on 25/11/20.
//

#include "../Headers/MapBuilder.h"

//Build System
void MapBuilder::reset() {

    this->result = new Map();
}

void MapBuilder::setFileManager(FileManager *fileManager) {

    this->result->setXmlManager((XmlManager*)fileManager);
}

void MapBuilder::setNodeFactory(MapNodeFactory *factory) {

    this->result->setNodeFactory(factory);
}

void MapBuilder::setDataPath(char *dataPath) {

    this->result->setDataPath(dataPath);
}

void MapBuilder::setPainter(Painter *painter) {

    this->result->setPainter(painter);
}


//Setters & Getters
Map * MapBuilder::getResult() {

    return this->result;
}