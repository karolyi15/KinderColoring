//
// Created by gunther on 26/11/20.
//

#include "Painter.h"
#include "DivideConquerPainter.h"
#include "BacktrackingPainter.h"
#include "DynamicPainter.h"

#ifndef KINDERCOLORING_PAINTERFACTORY_H
#define KINDERCOLORING_PAINTERFACTORY_H

enum class PainterType{

    BACKTRCKING,
    DIVIDEANDCONQUER,
    DYNAMIC,
};

class PainterFactory {

public:

    //Creation System
    Painter* createPainter(PainterType painterType);
};


#endif //KINDERCOLORING_PAINTERFACTORY_H
