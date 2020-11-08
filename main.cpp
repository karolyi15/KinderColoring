#include <iostream>
#include <fstream>
#include <rapidxml_utils.hpp>
#include "rapidxml.hpp"
#include "Headers/XmlManager.h"
#include "Headers/Node.h"
#include "Headers/LinkedList.h"
#include <vector>
using namespace rapidxml;
using namespace std;


// Se envia un string grande y
// Retorna un vector con todas las separaciones de el, donde este el delim

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}


vector<string> changePoints(string points,vector<string> contry){
    float X = 0;
    float Y = 0;
    vector<string> pointsLTS = split(points," ");
    for (int position = 1; position < pointsLTS.size()-2 ; position++) {

        if (pointsLTS.at(position) !="m" && pointsLTS.at(position) !="z" && pointsLTS.at(position) !="M" && pointsLTS.at(position) !="l"){

            vector<string> temp = split(pointsLTS.at(position), ",");

            X = X + stof(temp.at(1));
            Y = Y + stof(temp.at(0));

            string result = to_string(X) + "," + to_string(Y);
            contry.push_back(result);
        }
    }
    return  contry;
}



int main() {

    // se crea un vector de vectores de string matriz

    vector<vector<string>> matriz;
    //*****************************************************************************************************************//
    //***** XML MANAGER TEST *****//

    //Init Xml Manager
    XmlManager *manager = XmlManager::getInstance();

    //Parse Xml File
    xml_document<> *xmlData = manager->parseXML("../_MapFiles/world.svg");

    //Access Xml Node

    //Accede al primer path
    xml_node<> *path = xmlData->first_node()->first_node()->next_sibling()->next_sibling()->next_sibling();

    //recore todos los path
    for (; path != NULL; path = path->next_sibling()) {


        //crea un vector contry que vamos a meter a la matriz
        vector<string> contry = {};
        //Point tiene todas lo que este en d
        // Es decir m y los puntos hasta z
        //A contry se le va metiendoel primer valor
        //Es decir el id ejemplo    AF
        contry.push_back(path->first_attribute()->next_attribute()->value());
        float X=0;
        float Y=0;
        contry=changePoints(path->first_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->value(),contry);
        matriz.push_back(contry);
    }
        for (int i = 0; i < matriz.size(); i++) {
            cout << matriz.at(i).at(0) << endl;
            cout<< matriz.at(i).at(1)<<endl;
        }
        //
        //Save Xml to File
        //manager->writeXML("/home/gunther/CLionProjects/KinderColoring/_MapFiles/test.svg");

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
        /*
         LinkedList<string> *list = new LinkedList<int>();
         list->add(3);
         list->add(4);
         list->add(5);
         list->add(6);
         list->add(7);
         //list->print();
     */
        //cout << endl;
        //cout<< "List Get value Test: " << list->getNode(1)->getValue();
        //*****************************************************************************************************************//
        return 0;



}