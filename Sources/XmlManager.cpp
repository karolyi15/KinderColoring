//
// Created by gunther on 3/11/20.
//

#include "../Headers/XmlManager.h"

void XmlManager::parseXML(string xmlPath) {

    this->xmlFile = new file<>(xmlPath);
    this->xmlData.parse<0>(xmlFile->data());

}

void XmlManager::writeXML(string xmlPath) {

    string xml_as_string;
    print(back_inserter(xml_as_string), this->xmlData);

    ofstream xmlFile(xmlPath);
    xmlFile << this->xmlData;
    xmlFile.close();
    this->xmlData.clear();
}

xml_node<> * XmlManager::getNode(char *nodeName) {

    return this->xmlData.first_node(nodeName);
}

xml_attribute<> * XmlManager::getAttribute(char *attributeName) {

    return this->xmlData.first_attribute(attributeName);
}
