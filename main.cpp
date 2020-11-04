#include <iostream>
#include <fstream>
#include <rapidxml_utils.hpp>
#include "rapidxml.hpp"
#include "Headers/XmlManager.h"

using namespace rapidxml;
using namespace std;

int main() {

    /*string xml;
    // Create and open a text file
    ofstream MyFile("test.txt");

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";

    // Close the file
    MyFile.close();
    // Create a text string, which is used to output the text file
    string myText;

// Read from the text file
    ifstream MyReadFile("/home/gunther/CLionProjects/KinderColoring/MapFiles/world.svg");
    //cout << "opened file" << endl;

// Use a while loop together with the getline() function to read the file line by line

    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        //cout << "in loop" << endl;
        //cout << myText;
        xml += myText;
    }

    //cout << "out loop" << endl;
// Close the file
    MyReadFile.close();
    //cout << xml << endl;


    //XML Parsing
    file<> fileTest ("/home/gunther/CLionProjects/KinderColoring/MapFiles/world.svg");
    xml_document<> doc;
    //char * xmlChar = &xml[0];
    doc.parse<0>(fileTest.data());

    cout<< "Node name: " << doc.first_node()->first_node("path")->first_attribute("data-id")->value() << endl;*/



    XmlManager * xmlManager = new XmlManager();
    xmlManager->parseXML("/home/gunther/CLionProjects/KinderColoring/MapFiles/world.svg");
    cout << xmlManager->getNode("svg")->name();
    //cout << xmlManager->getAttribute("data-id")->name();
    return 0;


}
