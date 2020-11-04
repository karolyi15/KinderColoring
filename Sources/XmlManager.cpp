//
// Created by gunther on 3/11/20.
//

#include "../Headers/XmlManager.h"

xml_document<>* XmlManager::parseXML(char* xmlPath) {

    this->xmlData.clear();
    this->xmlFile = new file<>(xmlPath);
    this->xmlData.parse<0>(xmlFile->data());
    return this->xmlData.document();
}

void XmlManager::writeXML(char* xmlPath) {

    string xml_as_string;
    print(std::back_inserter(xml_as_string), this->xmlData);

    ofstream xmlFile(xmlPath);
    xmlFile << this->xmlData;
    xmlFile.close();
    this->xmlData.clear();
}

