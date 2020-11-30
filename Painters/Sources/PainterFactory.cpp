//
// Created by gunther on 26/11/20.
//

#include "../Headers/PainterFactory.h"

//Creation System
Painter * PainterFactory::createPainter(PainterType painterType) {

    switch (painterType) {

        case PainterType::DYNAMIC:
            return (Painter*)  new DynamicPainter();

        case PainterType::BACKTRCKING:
            return (Painter*) new BacktrackingPainter();

        case PainterType::DIVIDEANDCONQUER:
            return (Painter*) new DivideConquerPainter();


    }
}