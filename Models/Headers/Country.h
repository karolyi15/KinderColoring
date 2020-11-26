//
// Created by gunther on 24/11/20.
//

#include "MapNode.h"
#include "ColorType.h"
#include "iostream"
#include "vector"
#include "../../FileManagers/Headers/StringSplitter.h"

#ifndef KINDERCOLORING_COUNTRY_H
#define KINDERCOLORING_COUNTRY_H


class Country: public MapNode {

private:

    //Fields
    Color color;
    std::vector<std::pair<float, float>> limitPoints;
    std::vector<MapNode*> limitCountries;

    //Limit Calculation System
    void calculateLimitPoints(char* stringPoints);

public:

    //Constructor
    Country();

    //Setters & Getter
    void setColor(Color color);
    Color getColor();

    void setLimitPoints(char* stringPoints);
    std::vector<std::pair<float, float>>* getLimitPoints();

    void addLimitCountry(MapNode* mapNode);
    std::vector<MapNode*>* getLimitCountries();

    std::string toString();
};


#endif //KINDERCOLORING_COUNTRY_H
