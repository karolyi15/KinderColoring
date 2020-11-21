//
// Created by gunther on 18/11/20.
//

#include "../Headers/Painter.h"

//Constructor
Painter::Painter() {

    this->svgFileName = "test.svg";

    this->colors = {"", //
                    "",
                    "",
                    };
}

//Setters & Getters

void Painter::setSvgManager(SvgManager* svgManager) {

    this->svgManager = svgManager;
}