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
    map<string, Country*> *countries;
    XmlManager* xmlManager;

    xml_document<> * xmlData;

    //Parsing System
    void parseCountries();
    bool validateIntersection(vector<pair<float, float>>* countryPoints, vector<pair<float, float>>* tempCountryPoints);
    void calculateCountriesBounds();

    //
    void limits();

public:

    //Constructor
    SvgManager(char* svgPath);

    //Parsing System
    void printCountries();

    //Setters & Getters
    void setPath(char* svgPath);
    char* getPath();

    map<string, Country*>* getCountries();

    //
    void writeSvg(char* svgPath);

};


#endif //KINDERCOLORING_SVGMANAGER_H
