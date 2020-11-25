//
// Created by gunther on 18/11/20.
//

#ifndef KINDERCOLORING_DIVIDECONQUERPAINTER_H
#define KINDERCOLORING_DIVIDECONQUERPAINTER_H

#include "Painter.h"

class DivideConquerPainter {

private:

    //Fields
    vector<string> countriesID;
    SvgManager *svgManager;
    vector<char*> *colors;

public:
    //Constructor
    DivideConquerPainter(SvgManager *svgManager);
    void initCountries(map<string, Country*>* countriesHashMap);

    //Setters & Getter
    void setSvgManager(SvgManager * svgManager);
    //Paint System
    void initColors();
    void paint();
    void divideConquer(vector<string> countriesList);
    char* verifyColor(vector<string> *openSet);
};


#endif //KINDERCOLORING_DIVIDECONQUERPAINTER_H
