//
// Created by gunther on 3/11/20.
//

#include "../Headers/XmlManager.h"


//File Management System
void XmlManager::readFile(char *filePath) {

    this->xmlData.clear();
    file<> * xmlFile = new file<>(filePath);
    this->xmlData.parse<0>(xmlFile->data());

}

void XmlManager::writeFile(char *filePath) {

    string xml_as_string;
    print(std::back_inserter(xml_as_string), this->xmlData);

    ofstream xmlFile(filePath);
    xmlFile << this->xmlData;

    xmlFile.close();
    this->xmlData.clear();
}

//Setters & Getters

xml_document<> * XmlManager::getXmlData() {

    return &this->xmlData;
}