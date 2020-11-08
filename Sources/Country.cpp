//
// Created by gunther on 7/11/20.
//

#include "../Headers/Country.h"

//Constructor
Country::Country(char *id, LinkedList<float> points, LinkedList<Country> bounds) {

    this->id = id;
    this->color = "#f2f2f2";
    this->points = &points;
    this-> bounds = &bounds;
}

//Setters & Getters
void Country::setColor(char *color) {

    this->color = color;
}