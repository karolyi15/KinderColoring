//
// Created by gunther on 25/11/20.
//

#include "MapBuilder.h"

#ifndef KINDERCOLORING_MAPDIRECTOR_H
#define KINDERCOLORING_MAPDIRECTOR_H


class MapDirector {

private:

    //Builder
    AbstractMapBuilder* builder;

public:

    //Constructor
    MapDirector(AbstractMapBuilder* builder);

    //Build System
    Map* buildWorldMap(char* dataPath, FileManager* fileManager, MapNodeFactory* mapNodeFactory, Painter* painter);

    //Setters & Getters
    void changeBuilder(AbstractMapBuilder* builder);
};


#endif //KINDERCOLORING_MAPDIRECTOR_H
