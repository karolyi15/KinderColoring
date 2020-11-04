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

    void parseXML(string xmlPath);
    void writeXML(string xmlPath);
    xml_node<>* getNode(char * nodeName);
    xml_attribute<>* getAttribute(char * attributeName);
};


#endif //KINDERCOLORING_XMLMANAGER_H
