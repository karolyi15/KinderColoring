//
// Created by gunther on 18/11/20.
//

#ifndef KINDERCOLORING_DIVIDECONQUERPAINTER_H
#define KINDERCOLORING_DIVIDECONQUERPAINTER_H

#include <vector>
#include "Painter.h"
#include "../../Models/Headers/Country.h"

class DivideConquerPainter: public Painter {

private:

    std::vector<Country*> inputData;

public:

    //Constructor
    DivideConquerPainter();

    //Analyse Input Data
    void setInputData(std::map<char*, MapNode*>* inputData);

    //Painting System
    void start();

    void divideConquer(std::vector<Country*> countriesList);
    Color verifyColor(std::vector<Color> *openSet);
};


#endif //KINDERCOLORING_DIVIDECONQUERPAINTER_H
