//
// Created by gunther on 18/11/20.
//
#include <vector>
#include "Painter.h"
#include "iostream"
#include "../../Models/Headers/Country.h"

#ifndef KINDERCOLORING_DYNAMICPAINTER_H
#define KINDERCOLORING_DYNAMICPAINTER_H


using namespace std;
class DynamicPainter: public Painter {

private:

    std::vector<Country*> inputData;

public:

    //Constructor
    DynamicPainter();

    //Analyse Input Data
    void setInputData(std::map<char*, MapNode*>* inputData);

    //Painting System
    void start();

    std::vector<Color> optimizarColores(std::vector <MapNode*>* limitCountries, int cantidadColores);
    int dynamic(int paisActual,int cantidadColores);

};


#endif //KINDERCOLORING_DYNAMICPAINTER_H
