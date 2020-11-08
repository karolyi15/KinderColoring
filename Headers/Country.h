//
// Created by gunther on 7/11/20.
//

#include "LinkedList.h"
#ifndef KINDERCOLORING_COUNTRY_H
#define KINDERCOLORING_COUNTRY_H


class Country {

private:

    char* id;
    char* color;
    LinkedList<float> *points;
    LinkedList<Country> *bounds;

public:

    //Constructor
    Country(char* id, LinkedList<float> points, LinkedList<Country> bounds);

    //Setters & Getters
    void setColor(char* color);
};


#endif //KINDERCOLORING_COUNTRY_H
