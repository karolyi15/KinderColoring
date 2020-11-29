//
// Created by gunther on 22/11/20.
//
#include "iostream"

#ifndef KINDERCOLORING_MAPNODE_H
#define KINDERCOLORING_MAPNODE_H


class MapNode {

protected:

    //Fields
    char* id;

public:

    //Constructors
    MapNode();
    MapNode(char* id);

    //Setters & Getters
    void setId(char* id);
    char* getId();

    virtual std::string toString() = 0;

};


#endif //KINDERCOLORING_MAPNODE_H
