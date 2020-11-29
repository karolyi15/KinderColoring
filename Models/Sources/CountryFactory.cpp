//
// Created by gunther on 23/11/20.
//

#include "../Headers/CountryFactory.h"

MapNode * CountryFactory::createNode() {

    Country* country = new Country();
    return  (MapNode*) country;
}