//
// Created by gunther on 25/11/20.
//

#include "AbstractMapBuilder.h"

#ifndef KINDERCOLORING_MAPBUILDER_H
#define KINDERCOLORING_MAPBUILDER_H


class MapBuilder: public AbstractMapBuilder {

private:

    Map* result;

public:

    //Build System
    void reset();

    void setFileManager(FileManager *fileManager);
    void setNodeFactory(MapNodeFactory *factory);
    void setDataPath(char* dataPath);
    void setPainter(Painter *painter);

    //Setters & Getters
    Map* getResult();


};


#endif //KINDERCOLORING_MAPBUILDER_H
