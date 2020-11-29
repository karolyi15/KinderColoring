//
// Created by gunther on 25/11/20.
//

#include <map>
#include "iostream"
#include "MapNodeFactory.h"
#include "../../Painters/Headers/Painter.h"
#include "../Headers/Country.h"
#include "../../FileManagers/Headers/XmlManager.h"

#ifndef KINDERCOLORING_MAP_H
#define KINDERCOLORING_MAP_H

using namespace std;

class Map {

private :



    //Nodes Management System
    std::map<char*, MapNode*> *nodes;

    MapNodeFactory *nodeFactory;
    XmlManager *xmlManager;

    void loadNodes();
    void calculateLimitNodes();

    bool isLimit(vector<pair<float, float>>* countryPoints, vector<pair<float, float>>* tempCountryPoints);

    //Paint System
    Painter *painter;


public:

    //File Management System
    void saveMapData();

    //Constructor
    Map();

    //Paint System
    void paint();

    //Setters & Getters
    void setDataPath(char* dataPath);

    void setNodeFactory(MapNodeFactory* factory);
    MapNodeFactory* getNodeFactory();

    void setXmlManager(XmlManager* xmlManager);
    XmlManager* getXmlManager();

    void setPainter(Painter *painter);

    void setNodes(map<char*, MapNode*>* nodes);
    map<char*, MapNode*>* getNodes();

    void printNodes();
};


#endif //KINDERCOLORING_MAP_H
