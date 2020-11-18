//
// Created by gunther on 18/11/20.
//

#ifndef KINDERCOLORING_DIVIDECONQUERPAINTER_H
#define KINDERCOLORING_DIVIDECONQUERPAINTER_H

#include "Painter.h"

class DivideConquerPainter:Painter {

private:

    //
    vector<char*> countriesID;

public:
    //Constructor
    DivideConquerPainter();
    void initCountries(map<char*, Country*>* countriesHashMap);
};


#endif //KINDERCOLORING_DIVIDECONQUERPAINTER_H
