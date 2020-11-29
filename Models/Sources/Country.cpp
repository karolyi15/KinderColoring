//
// Created by gunther on 24/11/20.
//

#include <string>
#include "../Headers/Country.h"

//Constructor
Country::Country() {

    this->id = "";
    this->color =Color::DEFAULT;
}

//Limit Calculation System
void Country::calculateLimitPoints(char* stringPoints) {

    std::vector<std::string> pointList = StringSplitter::splitString(stringPoints, " ");

    //** Temp Values **
    float tempX = 0;
    float tempY = 0;

    //** Limit Points **
    //Most Left
    std::pair<float, float> mostLeft (2000,0);
    //Most Left
    std::pair<float, float> mostRight (0,0);
    //Most Left
    std::pair<float, float> mostUp (0,0);
    //Most Left
    std::pair<float, float> mostDown (0,1001);

    //** Calculate Limit Points **
    for(int pointCounter = 0; pointCounter < pointList.size(); pointCounter++){

        if(pointList.at(pointCounter) != "m" && pointList.at(pointCounter) != "l" && pointList.at(pointCounter) != "z" && pointList.at(pointCounter) != "M"){

            std::vector<std::string> point = StringSplitter::splitString(pointList.at(pointCounter), ",");

            //Update Temp Values
            tempX += std::stof(point.at(0));
            tempY += std::stof(point.at(1));

            if(tempX < mostLeft.first){

                mostLeft = std::make_pair(tempX,tempY);
            }

            if( tempX > mostRight.first){

                mostRight = std::make_pair(tempX,tempY);
            }

            if( tempY > mostUp.second){

                mostUp = std::make_pair(tempX,tempY);
            }

            if(tempY < mostDown.second){

                mostDown = std::make_pair(tempX,tempY);
            }

        }else if(pointList.at(pointCounter) == "M"){

            //Reset Temp Values
            tempX = 0;
            tempY = 0;
        }
    }

    //** Set Limit Points **
    //Most Left
    this->limitPoints.push_back(mostLeft);
    //Most Right
    this->limitPoints.push_back(mostRight);
    //Most Up
    this->limitPoints.push_back(mostUp);
    //Most Down
    this->limitPoints.push_back(mostDown);
}


//Setters & Getters
void Country::setColor(Color color) {

    this->color = color;
}
Color Country::getColor() {

    return this->color;
}


void Country::setLimitPoints(char *stringPoints) {

    this->calculateLimitPoints(stringPoints);
}
std::vector<std::pair<float, float>> * Country::getLimitPoints() {

    return &this->limitPoints;
}

void Country::addLimitCountry(MapNode *mapNode) {

    this->limitCountries.push_back(mapNode);
}
std::vector<MapNode *> * Country::getLimitCountries() {

    return &this->limitCountries;
}


std::string Country::toString() {

    //Append Country Information
    std::string countryData = "{";

    //ID
    countryData+= "id:";
    countryData+= this->id;
    countryData+= ", ";

    //Color
    countryData+= "color:";
    countryData+= ColorType::getHexColor(this->color);
    countryData+= ", ";

    //Points
    countryData+= "points:[";
    for(int point = 0; point< this->limitPoints.size(); point++){

        countryData+= "[";
        countryData+= std::to_string(this->limitPoints.at(point).first);
        countryData+= ",";
        countryData+= std::to_string(this->limitPoints.at(point).second);
        countryData+= "]";

        if(point != this->limitPoints.size()-1) {
            countryData += ", ";
        }

    }
    countryData+= "]";
    countryData+= ", ";

    //Limit Countries
    countryData+= "limitCountries:[";
    for(int country = 0; country< this->limitCountries.size(); country++){

        countryData+= this->limitCountries.at(country)->getId();

        if(country != this->limitCountries.size()-1) {
            countryData += ", ";
        }
    }
    countryData+= "]";

    countryData += "}";

    return countryData;
}
