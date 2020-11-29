//
// Created by gunther on 3/11/20.
//

#ifndef KINDERCOLORING_XMLMANAGER_H
#define KINDERCOLORING_XMLMANAGER_H

#include <iostream>
#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <rapidxml_print.hpp>
#include <string>
#include "FileManager.h"

using namespace std;
using namespace rapidxml;

class XmlManager: public FileManager {

private:

    //Xml Parse System
    xml_document<> xmlData;

public:

    //File Management System
    void readFile(char* filePath);
    void writeFile(char* filePath);

    //Setters & Getters
    xml_document<>* getXmlData();

};

#endif //KINDERCOLORING_XMLMANAGER_H
