//
// Created by gunther on 25/11/20.
//

#include "../Headers/Map.h"


//Constructor
Map::Map() {

    //Init Fields
    this->nodes = new map<char*, MapNode*>();
}

//File Management System
void Map::saveMapData() {

    string DEFAULT_MAP_PATH = "../_MapFiles/";
    DEFAULT_MAP_PATH.append(this->painter->getId());

    //Get XML Data
    xml_document<> *xmlData = this->xmlManager->getXmlData();

    //Access First Country Node
    xml_node<> *country = xmlData->first_node()->first_node("path");

    while( country != NULL) {

        //Create TempCountry
        char *tempCountryId = country->first_attribute("id")->value();

        //Get Hash Map Data
        Country *tempCountry = (Country *) this->nodes->at(tempCountryId);
        char *tempCountryColor = ColorType::getHexColor(tempCountry->getColor());
        //cout<<endl<< endl<< "ID: " << tempCountry->getId() << "Color: " << tempCountryColor <<"  ";


        //Save Color
        string *tempAttribute = new string();
        tempAttribute->append("fill:");
        tempAttribute->append(tempCountryColor);
        //cout<< "attribute: " << tempAttribute.c_str();
        //cout<< "oldColor: " <<  country->first_attribute("style")->value()<< endl;

        country->first_attribute("style")->value(tempAttribute->c_str());

        //cout<< "newColor: " <<  country->first_attribute("style")->value()<<endl<< endl;

        //Update Country Node
        country = country->next_sibling();

    }
    /*string xml_as_string;
    print(std::back_inserter(xml_as_string), this->xmlManager->getXmlData());
    cout<xml_as_string<<endl;*/
    this->xmlManager->writeFile(&DEFAULT_MAP_PATH.at(0));
}

//Nodes Management System
void Map::loadNodes() {

    //Get XML Data
    xml_document<> *xmlData = this->xmlManager->getXmlData();

    //Access First Country Node
    xml_node<> *country = xmlData->first_node()->first_node("path");

    while( country != NULL){

        //Create TempCountry
        char* tempCountryId = country->first_attribute("id")->value();
        char* tempCountryStringPoints = country->first_attribute("d")->value();

        Country* tempCountry = (Country*) this->nodeFactory->createNode();
        tempCountry->setId(tempCountryId);
        tempCountry->setLimitPoints(tempCountryStringPoints);

        //Add Country to Hash Map
        this->nodes->insert(std::make_pair(tempCountryId,tempCountry));

        //Update Country Node
        country = country->next_sibling();

    }

}

void Map::calculateLimitNodes() {

    //Iterators
    map<char*, MapNode*>::iterator currentNode;
    map<char*, MapNode*>::iterator tempNode;

    for(currentNode = this->nodes->begin(); currentNode != this->nodes->end(); currentNode++){

        //Get Country Limit Points
        Country* currentCountry = (Country*) currentNode->second;
        vector<pair<float, float>> *currentLimitPoints = currentCountry->getLimitPoints();


        for(tempNode = this->nodes->begin(); tempNode != this->nodes->end(); tempNode++){

            Country* tempCountry = (Country*) tempNode->second;

            if(currentCountry->getId() != tempCountry->getId()) {
                //Get Temp Country Data Points
                vector<pair<float, float>> *tempLimitPoints = tempCountry->getLimitPoints();

                if (isLimit(currentLimitPoints, tempLimitPoints) || isLimit(tempLimitPoints, currentLimitPoints)) {

                    currentCountry->addLimitCountry(tempNode->second);
                }
            }
        }
    }
}

bool Map::isLimit(vector<pair<float, float>> *countryPoints, vector<pair<float, float>> *tempCountryPoints) {

    for(int point = 0; point< countryPoints->size(); point++){

        if((countryPoints->at(point).first >= tempCountryPoints->at(0).first && countryPoints->at(point).first <= tempCountryPoints->at(1).first) && (countryPoints->at(point).second <= tempCountryPoints->at(2).second && countryPoints->at(point).second >= tempCountryPoints->at(3).second)){

            return true;
        }
    }

    return false;
}

//Paint System
void Map::paint() {

    this->painter->setInputData(this->nodes);
    this->painter->start();
    //Save Map Data
    //this->saveMapData();
}

//Setters & Getters
void Map::setDataPath(char *dataPath) {

    this->xmlManager->readFile(dataPath);
    this->loadNodes();
    this->calculateLimitNodes();
}

void Map::setNodeFactory(MapNodeFactory *factory) {

    this-> nodeFactory = factory;
}
MapNodeFactory * Map::getNodeFactory() {

    return this->nodeFactory;
}

void Map::setXmlManager(XmlManager *xmlManager) {

    this->xmlManager = xmlManager;
}
XmlManager * Map::getXmlManager() {

    return this->xmlManager;
}

void Map::setPainter(Painter *painter) {

    this->painter = painter;
}

void Map::setNodes(map<char *, MapNode *> *nodes) {

    this->nodes = nodes;
}
map<char *, MapNode *> * Map::getNodes() {

    return this->nodes;
}

void Map::printNodes() {

    cout << "===============================" << endl;
    cout << "           Map Nodes           " << endl;
    cout << "===============================\n" << endl;
    map<char*, MapNode*>::iterator itr;

    for(itr = this->nodes->begin(); itr != this->nodes->end(); itr++){

        cout << itr->second->toString() << endl;
    }
}