//
// Created by gunther on 25/11/20.
//

#include "Map.h"

#ifndef KINDERCOLORING_ABSTRACTBUILDER_H
#define KINDERCOLORING_ABSTRACTBUILDER_H


class AbstractMapBuilder {

public:

    //Build System
    virtual void reset() = 0;
    virtual Map* getResult() = 0;

};


#endif //KINDERCOLORING_ABSTRACTBUILDER_H
