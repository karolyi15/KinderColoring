#include <iostream>
#include <rapidxml_utils.hpp>
#include "rapidxml.hpp"
#include "Headers/XmlManager.h"
#include "Headers/LinkedList.h"
#include <vector>
#include <cmath>


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

bool compararPuntos (string puntoActual, string puntoVerificar, int dimension){
    //cout<<puntoActual<<endl;
    if ((pow((puntoActual.at(0)-puntoVerificar.at(0)),2)+pow((puntoActual.at(1)-puntoVerificar.at(1)),2))== dimension){
        return true;
    }
    else{
        return false;
    }
}

bool verificarFrontera(vector<string> paisActual, vector<string> paisVerificar){

    for (int puntoActual = 1; puntoActual < paisActual.size() ; puntoActual++) {
        for (int puntoVerificar = 1; puntoVerificar < paisVerificar.size() ; puntoVerificar++){
            if(compararPuntos(paisActual.at(puntoActual),paisVerificar.at(puntoVerificar),4)){
                return true;
            }
        }
    }
    return  false;
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

        //Point tiene todas lo que este en d -> Es decir m y los puntos hasta z
        //A contry se le va metiendo el primer valor -> Es decir el id ejemplo    AF
        contry.push_back(path->first_attribute()->next_attribute()->value());
        float X=0;
        float Y=0;
        contry=changePoints(path->first_attribute()->next_attribute()->next_attribute()->next_attribute()->next_attribute()->value(),contry);
        matriz.push_back(contry);
    }

    //Verificar Matriz
    /*for (int i = 0; i < matriz.size(); i++) {
        cout << matriz.at(i).at(0) << endl;
        cout<< matriz.at(i).at(1)<<endl;
    }*/

    //Crear fronteras
    vector<vector<string>> fronteras;

    for (int pais = 0; pais < matriz.size(); pais++) {
        vector<string> limites = {};
        limites.push_back(matriz.at(pais).at(0));
        for (int paisComparar = 0; paisComparar < matriz.size(); paisComparar++){
            /*if (paisComparar ==  pais){
                break;
            }*/
            if (verificarFrontera(matriz.at(pais),matriz.at(paisComparar))){
                limites.push_back(matriz.at(paisComparar).at(0));
                break;
            }
        }
        fronteras.push_back(limites);
    }

    //Verificar fronteras
    cout<<fronteras.size();
    for (int i = 0; i < fronteras.size(); i++) {
        cout<<fronteras.at(i).at(0) <<"-";
        cout<<fronteras.at(i).at(1);
        cout<<endl;
       /* for (int j = 0; j < fronteras.at(i).size()-1; i++) {
            cout<<fronteras.at(i).at(j)<<"/";
        }*/

    }

    return 0;
}