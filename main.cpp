#include <iostream>
#include <fstream>
#include <rapidxml_utils.hpp>
#include "rapidxml.hpp"
#include "Headers/XmlManager.h"
#include "Headers/Node.h"
#include "Headers/LinkedList.h"

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

    //*****************************************************************************************************************//
    //***** NODE TEST *****//
    /*int value = 1;
    Node<int> *node = new Node<int>(3);
    Node<int> *node2 = new Node<int>(4);

    node->setNext(node2);

    cout << "Node value: " << node->getValue() << endl;
    cout << "Node previous: " << node->getPrevious() << endl;
    cout << "Node next: " << node->getNext()->getValue() << endl;
    */
    //*****************************************************************************************************************//

    //*****************************************************************************************************************//
    //***** LIST TEST *****/

    LinkedList<int> *list = new LinkedList<int>();
    list->add(3);
    list->add(4);
    list->add(5);
    list->add(6);
    list->add(7);
    list->print();

    cout << endl;
    cout<< "List Get value Test: " << list->getNode(1)->getValue();
    //*****************************************************************************************************************//
    return 0;


}
