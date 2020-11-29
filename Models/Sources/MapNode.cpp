//
// Created by gunther on 22/11/20.
//

#include "../Headers/MapNode.h"

//Constructor
MapNode::MapNode() {}
MapNode::MapNode(char *id) {

    this->id = id;
}

//Setters & Getters
void MapNode::setId(char *id) {

    this->id =id;
}

char * MapNode::getId() {

    return this->id;
}