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
    this->calculateCountriesBounds();
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

bool SvgManager::validateIntersection(vector<pair<float, float>>* countryPoints, vector<pair<float, float>>* tempCountryPoints) {

    for(int point = 0; point< countryPoints->size(); point++){

        if((countryPoints->at(point).first >= tempCountryPoints->at(0).first && countryPoints->at(point).first <= tempCountryPoints->at(1).first) && (countryPoints->at(point).second <= tempCountryPoints->at(2).second && countryPoints->at(point).second >= tempCountryPoints->at(3).second)){

            return true;
        }
    }

    return false;
}

void SvgManager::calculateCountriesBounds() {

    //Iterators
    map<char*, Country*>::iterator country;
    map<char*, Country*>::iterator tempCountry;

    for(country = this->countries->begin(); country != this->countries->end(); country++){

        //Get Country Data Points
        vector<pair<float, float>> *points = country->second->getBoundsPoints();


        for(tempCountry = this->countries->begin(); tempCountry != this->countries->end(); tempCountry++){

            if(tempCountry->second->getId() != country->second->getId()) {
                //Get Temp Country Data Points
                vector<pair<float, float>> *tempPoints = tempCountry->second->getBoundsPoints();

                if (validateIntersection(points, tempPoints) || validateIntersection(tempPoints, points)) {

                    country->second->setBoundCountry(tempCountry->second->getId());
                }
            }
        }
    }
}

void SvgManager::printCountries() {

    //Define Iterator
    map<char*, Country*>::iterator itr;

    //
    cout << "*** Hash Map Countries ***" << endl;
    for(itr = this->countries->begin(); itr != this->countries->end(); itr++){

        cout << "Key ID: " << itr->first << "   Node: " << itr->second->toString() << endl;
    }
}