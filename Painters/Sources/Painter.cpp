//
// Created by gunther on 18/11/20.
//

#include "../Headers/Painter.h"

//Constructor
Painter::Painter() {

    this->id = "test.svg";
    this->painting = false;
    this->colorSet = 0;

    this->blankNodes = 0;
    this->paintedNodes = 0;
}

//Setters & Getters
void Painter::setId(char *id) {

    this->id = id;
}
char * Painter::getId() {

    return this->id;
}

void Painter::setPainting(bool painting) {

    this->painting = painting;
}
bool Painter::isPainting() {

    return this->painting;
}

void Painter::setColorSet(int colorSet) {

    this->colorSet = colorSet;
}

int Painter::getColorSet() {


    return this->colorSet;
}

int Painter::getPaintedNodes() {

    return this->paintedNodes;
}

int Painter::getBlankNodes() {

    return this->blankNodes;
}