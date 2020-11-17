//
// Created by gunther on 14/11/20.
//

#ifndef KINDERCOLORING_SVGMANAGER_H
#define KINDERCOLORING_SVGMANAGER_H


#include <map>
#include "XmlManager.h"
#include "Country.h"

class SvgManager{

private:

    //Fields
    char* svgPath;
    map<char*, Country*> *countries;
    XmlManager* xmlManager;

public:

    //Constructor
    SvgManager(char* svgPath);

    //Parse System
    void parseCountries();
    void printCountries();

    //Setters & Getters
    map<char*, Country*>* getCountries();

};


#endif //KINDERCOLORING_SVGMANAGER_H
