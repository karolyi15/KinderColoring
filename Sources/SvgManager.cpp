//
// Created by gunther on 14/11/20.
//

#include "../Headers/SvgManager.h"

//Constructor
SvgManager::SvgManager(char* svgPath) {

    this->svgPath = svgPath;
    this->countries = new map<char*, Country*>;
    this->xmlManager = XmlManager::getInstance();

    this->parseCountries();
}

//Setters & Getters
map<char*, Country*> * SvgManager::getCountries() {

    return this->countries;
}

//Parse System
void SvgManager::parseCountries() {

    //Parse Svg Data
    xml_document<> *xmlData = xmlManager->parseXML(this-> svgPath);

    //Access First Country Node
    xml_node<> *country = xmlData->first_node()->first_node("path");

    while( country != NULL){

        //Create TempCountry
        char* tempCountryId = country->first_attribute("id")->value();
        char* tempCountryStringPoints = country->first_attribute("d")->value();
        Country* tempCountry = new Country(tempCountryId, tempCountryStringPoints);

        //Add Country to Hash Map
        this->countries->insert(std::make_pair(tempCountryId,tempCountry));

        //Update Country Node
        country = country->next_sibling();

    }
}

void SvgManager::printCountries() {

    //Define Iterator
    map<char*, Country*>::iterator itr;

    //
    cout << "*** Hash Map Countries ***" << endl;
    for(itr = this->countries->begin(); itr != this->countries->end(); itr++){

        cout << "Key ID: " << itr->first << "   Node ID: " << itr->second->toString() << endl;
    }
}