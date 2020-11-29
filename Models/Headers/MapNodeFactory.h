//
// Created by gunther on 23/11/20.
//

#include "MapNode.h"

#ifndef KINDERCOLORING_MAPNODEFACTORY_H
#define KINDERCOLORING_MAPNODEFACTORY_H


class MapNodeFactory {

public :

    //Creation System
    virtual MapNode* createNode() = 0;

};


#endif //KINDERCOLORING_MAPNODEFACTORY_H
