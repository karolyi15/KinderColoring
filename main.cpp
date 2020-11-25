#include <iostream>
#include <fstream>
#include <rapidxml_utils.hpp>
#include "rapidxml.hpp"
#include "Headers/XmlManager.h"
#include "Headers/SvgManager.h"
#include "Headers/DivideConquerPainter.h"
#include "Headers/BacktrackingPainter.h"
#include <typeinfo>

using namespace rapidxml;
using namespace std;

int main() {
    //*****************************************************************************************************************//
    //***** XML MANAGER TEST *****//
    /*
    //Init Xml Manager
    XmlManager * manager = XmlManager::getInstance();

    //Parse Xml File
    xml_document<> *xmlData =manager->parseXML("/home/gunther/CLionProjects/KinderColoring/_MapFiles/world1.svg");

    //Access Xml Node
   // cout<<xmlData->fi
     rst_node()->name();

    //Save Xml to File
    //manager->writeXML("/home/gunther/CLionProjects/KinderColoring/_MapFiles/test.svg");
     */
    //*****************************************************************************************************************//
    SvgManager *svgManager = new SvgManager("../_MapFiles/world.svg");
   // svgManager->printCountries();
    //char * color= "#cd2120";
   // svgManager->getCountries()->begin()->second->setColor(color);

    //svgManager->printCountries();

   // svgManager->writeSvg("../_MapFiles/world1.svg");

    //DivideConquerPainter *painter = new DivideConquerPainter(svgManager);

    //painter->paint();


    BacktrackingPainter *painter = new BacktrackingPainter(svgManager);


    painter->backtracking(0,3,0);
    painter->paint();

    //*****************************************************************************************************************//
    return 0;


}
