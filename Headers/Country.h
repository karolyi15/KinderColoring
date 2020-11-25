//
// Created by gunther on 7/11/20.
//

#include <iostream>
#include <vector>
#include <cstring>
#ifndef KINDERCOLORING_COUNTRY_H
#define KINDERCOLORING_COUNTRY_H

using namespace std;

class Country {

private:

    //Fields
    std::string id;
    char* color;
    std::vector< std::pair<float,float> > boundsPoints;
    std:: vector<std::string> boundsCountries;

    //Parsing System
    std::vector<std::string> splitString(const std::string& str, const std::string& delim);

    void calculateBoundsPoints(char* stringPoints);

public:

    //Constructor
    Country(string id, char* stringPoints);
    Country(string id, char* color ,char* stringPoints);

    //Setters & Getters
    basic_string<string , char_traits<char>, allocator<char>> getId();

    void setColor(char* color);
    char* getColor();

    std::vector<std::pair<float,float>>* getBoundsPoints();

    void setBoundCountry(string countryId);
    std::vector<std::string>* getBoundsCountries();

    //To String
    std::string toString();
};


#endif //KINDERCOLORING_COUNTRY_H
