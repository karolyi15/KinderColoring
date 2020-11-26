//
// Created by gunther on 18/11/20.
//

#include <map>
#include "iostream"
#include "../../Models/Headers/MapNode.h"

#ifndef KINDERCOLORING_PAINTER_H
#define KINDERCOLORING_PAINTER_H


class Painter {

protected:

    char* id;
    bool painting;
    int  colorSet;

public:

    //Constructor
    Painter();

    //Painting System
    virtual void start() = 0;

    //Setters & Getters
    void setId(char* id);
    char* getId();

    void setPainting(bool painting);
    bool isPainting();

    void setColorSet(int colorSet);
    int getColorSet();

    virtual void setInputData(std::map<char*, MapNode*>* inputData) = 0;
};


#endif //KINDERCOLORING_PAINTER_H
