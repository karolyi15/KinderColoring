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

    return this->boundsPoints;
}

std::vector<std::string>* Country::getBoundsCountries() {

    return this->boundsCountries;
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

    float pointX = 0;
    float pointY = 0;

    for(int point = 0; point < stringVector.size(); point++){

        if(stringVector.at(point) != "m" && stringVector.at(point) != "z" && stringVector.at(point) != "M" && stringVector.at(point) != "l"){

            std::vector<std::string> tempStringPoint = splitString(stringVector.at(point),",");

            pointX += std::stof(tempStringPoint.at(0));
            pointY += std::stof(tempStringPoint.at(1));

            this->boundsPoints->push_back(std::make_pair(pointX,pointY));
        }
    }
}


//To String
std::string Country::toString() {

    //Define char*
    char* charCountry;

    //Append Country Information
    std::string stringCountry = "{";

    //ID
    stringCountry+= "id:";
    stringCountry+= this->id;
    stringCountry+= ", ";

    //Color
    stringCountry+= "color:";
    stringCountry+= this->color;
    //stringCountry+= ", ";

    //Points
    /*stringCountry+= "points:[";
    for(int point = 0; point< this->boundsPoints->size(); point++){

        stringCountry+= "[";
        stringCountry+= this->boundsPoints->at(point).first;
        stringCountry+= ",";
        stringCountry+= this->boundsPoints->at(point).second;
        stringCountry+= "]";
        stringCountry+= ",";
    }
    stringCountry+= "]";*/

    stringCountry += "}";

    return stringCountry;
}