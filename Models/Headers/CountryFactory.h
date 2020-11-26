//
// Created by gunther on 23/11/20.
//

#include "MapNodeFactory.h"
#include "Country.h"

#ifndef KINDERCOLORING_COUNTRYFACTORY_H
#define KINDERCOLORING_COUNTRYFACTORY_H


class CountryFactory: public MapNodeFactory {

public:

    //Creation System
    MapNode* createNode();

};


#endif //KINDERCOLORING_COUNTRYFACTORY_H
