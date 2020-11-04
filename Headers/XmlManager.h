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

using namespace std;
using namespace rapidxml;

class XmlManager {

private:

    file<> * xmlFile;
    xml_document<> xmlData;

public:

    xml_document<>* parseXML(char* xmlPath);
    void writeXML(char* xmlPath);

};


#endif //KINDERCOLORING_XMLMANAGER_H
