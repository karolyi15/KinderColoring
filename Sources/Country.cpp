//
// Created by gunther on 7/11/20.
//

#include "../Headers/Country.h"

//Constructor
Country::Country(char *id, char* stringPoints) {

    this->id = id;
    this->color = "#f2f2f2";

    this->calculateBoundsPoints(stringPoints);
}

Country::Country(char *id, char *color, char *stringPoints) {

    this->id = id;
    this->color = color;

    this->calculateBoundsPoints(stringPoints);
}

//Setters & Getters
char * Country::getId() {

    return this->id;
}


void Country::setColor(char *color) {

    this->color = color;
}

char * Country::getColor() {

    return this->color;
}

std::vector<std::pair<float,float>>* Country::getBoundsPoints() {

    return &this->boundsPoints;
}

void Country::setBoundCountry(char* countryId) {

    this->boundsCountries.push_back(countryId);
}

std::vector<std::string>* Country::getBoundsCountries() {

    return &this->boundsCountries;
}

//Parsing System
std::vector<std::string> Country::splitString(const std::string &str, const std::string &delim) {

    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

void Country::calculateBoundsPoints(char* stringPoints) {

    std::vector<std::string> stringVector = splitString(stringPoints," ");

    //** Points **
   //Most Left
   std::pair<float, float> mostLeft (0,0);
   //Most Left
   std::pair<float, float> mostRight (0,0);
   //Most Left
   std::pair<float, float> mostUp (0,0);
   //Most Left
   std::pair<float, float> mostDown (0,0);

    float tempX = 0;
    float tempY = 0;

    for(int point = 0; point < stringVector.size(); point++){

        if(stringVector.at(point) != "m" && stringVector.at(point) != "z" && stringVector.at(point) != "M" && stringVector.at(point) != "l") {

            std::vector<std::string> tempStringPoint = splitString(stringVector.at(point), ",");

            tempX += std::stof(tempStringPoint.at(0));
            tempY += std::stof(tempStringPoint.at(1));

            if (mostLeft.second != 0 && mostRight.second != 0 && mostUp.second != 0 && mostDown.second != 0) {
                //Verify if not initialize

                if(tempX < mostLeft.first){
                    //Verify Most Left
                    mostLeft = std::make_pair(tempX, tempY);

                }
                if(tempX > mostRight.first){
                    //Verify Most Right
                    mostRight = std::make_pair(tempX,tempY);

                }
                if(tempY > mostUp.second){
                    //Verify Most Up
                    mostUp = std::make_pair(tempX, tempY);

                }
                if(tempY < mostDown.second){
                    //Verify Most Down
                    mostDown = std::make_pair(tempX, tempY);

                }

            } else {

                mostLeft = std::make_pair(tempX,tempY);
                mostRight = std::make_pair(tempX,tempY);
                mostUp = std::make_pair(tempX,tempY);
                mostDown = std::make_pair(tempX,tempY);
            }
        }
    }

    //Push Data Into Vector
    //Most Left
    this->boundsPoints.push_back(mostLeft);
    //Most Right
    this->boundsPoints.push_back(mostRight);
    //Most Up
    this->boundsPoints.push_back(mostUp);
    //Most Down
    this->boundsPoints.push_back(mostDown);
}



//To String
std::string Country::toString() {

    //Append Country Information
    std::string stringCountry = "{";

    //ID
    stringCountry+= "id:";
    stringCountry+= this->id;
    stringCountry+= ", ";

    //Color
    stringCountry+= "color:";
    stringCountry+= this->color;
    stringCountry+= ", ";

    //Points
    stringCountry+= "points:[";
    for(int point = 0; point< this->boundsPoints.size(); point++){

        stringCountry+= "[";
        stringCountry+= std::to_string(this->boundsPoints.at(point).first);
        stringCountry+= ",";
        stringCountry+= std::to_string(this->boundsPoints.at(point).second);
        stringCountry+= "]";
            stringCountry+= ",";
    }
    stringCountry+= "]";

    //Limit Countries
    stringCountry+= "limitCountries:[";
    for(int country = 0; country< this->boundsCountries.size(); country++){

        stringCountry+= this->boundsCountries.at(country);
        stringCountry+= ", ";
    }
    stringCountry+= "]";

    stringCountry += "}";

    return stringCountry;
}