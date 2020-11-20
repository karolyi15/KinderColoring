//
// Created by gunther on 18/11/20.
//

#include "../Headers/DivideConquerPainter.h"

//Constructor
DivideConquerPainter::DivideConquerPainter() {

    //Init Country List
    this->initCountries(this->svgManager->getCountries());




}

void DivideConquerPainter::initCountries(map<char *, Country *> *countriesHashMap) {

    //Define Iterator
    map<char*, Country*>::iterator itr;

    //
    for(itr = countriesHashMap->begin(); itr != countriesHashMap->end(); itr++){

       this->countriesID.push_back(itr->second->getId());
    }
}