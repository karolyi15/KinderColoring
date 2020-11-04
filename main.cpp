#include <iostream>
#include <fstream>
#include <rapidxml_utils.hpp>
#include "rapidxml.hpp"
#include "Headers/XmlManager.h"

using namespace rapidxml;
using namespace std;

int main() {

    //Init Xml Manager
    XmlManager * xmlManager = new XmlManager();

    //Parse Xml File
    xmlManager->parseXML("/home/gunther/CLionProjects/KinderColoring/_MapFiles/world.svg");

    //Access Xml Node
    cout << xmlManager->getNode("svg")->name();

    //Save Xml to File
    xmlManager->writeXML("/home/gunther/CLionProjects/KinderColoring/_MapFiles/test.svg");

    return 0;


}
