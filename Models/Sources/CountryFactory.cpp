//
// Created by gunther on 23/11/20.
//

#include "../Headers/CountryFactory.h"

//Creation System
MapNode * CountryFactory::createNode() {

    Country* country = new Country();
    return  (MapNode*) country;
}