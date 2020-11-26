//
// Created by gunther on 26/11/20.
//

#include "../Headers/PainterFactory.h"

Painter * PainterFactory::createPainter(PainterType painterType) {

    switch (painterType) {

        case PainterType::BACKTRCKING:

            BacktrackingPainter* backtrackingPainter = new BacktrackingPainter();
            return (Painter*) backtrackingPainter;

        /*case PainterType::DIVIDEANDCONQUER:
            DivideConquerPainter *divideConquerPainter = new DivideConquerPainter();
            return (Painter*) divideConquerPainter;

        case PainterType::DYNAMIC:
            DynamicPainter* dynamicPainter = new DynamicPainter();
            return (Painter*) dynamicPainter;*/
    }
}