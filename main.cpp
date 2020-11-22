#include <iostream>
#include <fstream>
#include <rapidxml_utils.hpp>
#include "rapidxml.hpp"
#include "Headers/XmlManager.h"
#include "Headers/SvgManager.h"
#include "Headers/DivideConquerPainter.h"
#include "Headers/BacktrackingPainter.h"

using namespace rapidxml;
using namespace std;

int main() {
    //*****************************************************************************************************************//
    //***** XML MANAGER TEST *****//
    /*
    //Init Xml Manager
    XmlManager * manager = XmlManager::getInstance();

    //Parse Xml File
    xml_document<> *xmlData =manager->parseXML("/home/gunther/CLionProjects/KinderColoring/_MapFiles/world.svg");

    //Access Xml Node
    cout<<xmlData->fi
     rst_node()->name();

    //Save Xml to File
    //manager->writeXML("/home/gunther/CLionProjects/KinderColoring/_MapFiles/test.svg");
     */
    //*****************************************************************************************************************//
    SvgManager *svgManager = new SvgManager("../_MapFiles/world.svg");
    //svgManager->printCountries();

    
    typeid (svgManager->getCountries());
    svgManager->writeSvg("../_MapFiles/world.svg");

    //DivideConquerPainter *painter = new DivideConquerPainter(svgManager);

    //painter->paint();

    //*****************************************************************************************************************//
    return 0;


}
