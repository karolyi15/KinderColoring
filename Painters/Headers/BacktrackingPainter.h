//
// Created by gunther on 18/11/20.
//


#ifndef KINDERCOLORING_BACKTRACKINGPAINTER_H
#define KINDERCOLORING_BACKTRACKINGPAINTER_H


#include <vector>
#include "Painter.h"
#include "../../Models/Headers/Country.h"


class BacktrackingPainter: public Painter {

private:

    std::vector<Country*> inputData;

public:

    //Constructor
    BacktrackingPainter();

    //Analyse Input Data
    void setInputData(std::map<char*, MapNode*>* inputData);

    //Painting System
    void start();

    bool paintLimits(std::vector <MapNode*>* limitCountries, int cantidadColores);
    int backtracking(int paisActual,int cantidadColores,int colorActual);

};


#endif //KINDERCOLORING_BACKTRACKINGPAINTER_H
