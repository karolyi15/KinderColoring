//
// Created by gunther on 7/11/20.
//

#include <iostream>
#include <vector>

#ifndef KINDERCOLORING_COUNTRY_H
#define KINDERCOLORING_COUNTRY_H


class Country {

private:

    //Fields
    char* id;
    char* color;
    std::vector< std::pair<float,float> > boundsPoints;
    std:: vector<std::string> boundsCountries;

    //Parsing System
    std::vector<std::string> splitString(const std::string& str, const std::string& delim);

    void calculateBoundsPoints(char* stringPoints);

public:

    //Constructor
    Country(char* id, char* stringPoints);
    Country(char* id, char* color ,char* stringPoints);

    //Setters & Getters
    char* getId();

    void setColor(char* color);
    char* getColor();

    std::vector<std::pair<float,float>>* getBoundsPoints();

    void setBoundCountry(char* countryId);
    std::vector<std::string>* getBoundsCountries();

    //To String
    std::string toString();
};


#endif //KINDERCOLORING_COUNTRY_H
