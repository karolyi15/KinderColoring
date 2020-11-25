//
// Created by gunther on 7/11/20.
//

#include "../Headers/Country.h"
#include <string>

using namespace std;

//Constructor
Country::Country(string id, char* stringPoints) {

    this->id = id;
    this->color = "#f2f2f2";

    this->calculateBoundsPoints(stringPoints);
}

Country::Country(string id, char *color, char *stringPoints) {

    this->id = id;
    this->color = color;

    this->calculateBoundsPoints(stringPoints);
}

//Setters & Getters
basic_string<string, char_traits<char>, allocator<char>> Country::getId() {

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

void Country::setBoundCountry(string countryId) {

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

   //Most Left
   std::pair<float, float> mostLeft (2000,0);
   //Most Left
   std::pair<float, float> mostRight (0,0);
   //Most Left
   std::pair<float, float> mostUp (0,0);
   //Most Left
   std::pair<float, float> mostDown (0,1001);

    float tempX = 0;
    float tempY = 0;

    for(int point = 0; point < stringVector.size(); point++){

        if(stringVector.at(point) != "m" && stringVector.at(point) != "l" && stringVector.at(point) != "z" && stringVector.at(point) != "M"){

            //Get String Pair
            std::vector<std::string> tempPair = this->splitString(stringVector.at(point), ",");

            tempX += std::stof(tempPair.at(0));
            tempY += std::stof(tempPair.at(1));

            if(tempX < mostLeft.first){

                mostLeft = std::make_pair(tempX,tempY);

            }else if( tempX > mostRight.first){

                mostRight = std::make_pair(tempX,tempY);

            }else if( tempY > mostUp.second){

                mostUp = std::make_pair(tempX,tempY);

            }else if(tempY < mostDown.second){

                mostDown = std::make_pair(tempX,tempY);
            }

        }else if(stringVector.at(point) == "M"){

            tempX = 0;
            tempY = 0;
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