//
// Created by gunther on 18/11/20.
//

#include "SvgManager.h"

#ifndef KINDERCOLORING_PAINTER_H
#define KINDERCOLORING_PAINTER_H


class Painter {

protected:

    //Fields
    SvgManager* svgManager;

private:

    //Fields
    char* svgFileName;


public:

    //Constructor
    Painter();

    //Setters & Getters
    void setSvgManager(SvgManager* svgManager);
    //Metodo para guardar en disco
    //Thread para lasy witting

    //Paint System

};


#endif //KINDERCOLORING_PAINTER_H
