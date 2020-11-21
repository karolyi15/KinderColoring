#include "../Headers/BacktrackingPainter.h"
#include <cstring>

//Constructor
BacktrackingPainter::BacktrackingPainter(SvgManager* svgManager) {

    //Init Country List
    this->svgManager = svgManager;
    map<char*, Country*> * countriesHashmap = this->svgManager->getCountries();
    this->initCountries(countriesHashmap);

    //Paint System
    this->initColors();

}

//Setters & Getters
void BacktrackingPainter::setSvgManager(SvgManager *svgManager) {

    this->svgManager = svgManager;
}

void BacktrackingPainter::initCountries(map<char *, Country *> *countriesHashMap) {

    //Define Iterator
    map<char*, Country*>::iterator itr;

    //
    for(itr = countriesHashMap->begin(); itr != countriesHashMap->end(); itr++){

        this->countriesID.push_back(itr->second->getId());
    }
}

//Paint System
                    //Tienen que ser 11 colores
void BacktrackingPainter::initColors() {

    this->colors = new vector<char*>;


    this->colors->push_back("#cd2121"); //RED
    this->colors->push_back("#f4d02d"); //YELLOW
    this->colors->push_back("#124a68"); //BLUE
    this->colors->push_back("#fcbabc"); //PINK
    this->colors->push_back("#008000"); //Green
    this->colors->push_back("#ff4800"); //Orange
    this->colors->push_back("#55c0fa"); //light blue
    this->colors->push_back("#8f008f"); //Purple
    this->colors->push_back("#00fc00"); //light green
    this->colors->push_back("#008000"); //light blue
    this->colors->push_back("#008000"); //light blue

}

void BacktrackingPainter::paint() {

    divideConquer(this->countriesID);
    cout << "Painted" << endl;
    this->svgManager->writeSvg("../_MapFiles/BacktrackingWorld.svg");
    cout << "Saved" << endl;
}

// como mando el mismo pais o el pais siguiente osea el itr siguiente o el actual
void BacktrackingPainter::backtracking(vector<char*> countriesList,int paisActual,int cantidadColores,int colorActual) {
    if (paisActual>countriesList.size()) {
        return;                                             //ya se recorrieron todos los paises
    }
    else {
        Country *tempCountry = this->svgManager->getCountries()->at(countriesList.at(paisActual));  //saca la info del pais actual
        vector <string> *limitCountries = tempCountry->getBoundsCountries();            // los paises que son limites al pais actual

        if (colorActual > cantidadColores) {
            //Paint
            tempCountry->setColor("#ffffff");                               //le asigna un color blanco al pais
            cout << "color: " << tempCountry->getColor() << endl;
            backtracking(countriesList,paisActual+1,cantidadColores,0);              // hace backtracking con el siguiente pais para asignarle color
        } else {
            if (limitCountries->size() != 0) {
                                                                                     // verifica que el color no este en ninguno de los paises frontera
                for (int count = 0; count < limitCountries->size(); count++) {
                    char *tempID = const_cast<char *>(limitCountries->at(count).c_str());           // pais frontera verificando
                    char* tempColor = this->svgManager->getCountries()->at(tempID)->getColor();     // color del pais frontera
                    //char *tempColor = "";
                    if (tempColor == this->colors->at(colorActual)) {                                 // color del pais frontera = color a validar
                        backtracking(countriesList,paisActual,cantidadColores, colorActual + 1);    // hace backtracking con el mismo pais pero con color diferente
                    }
                }
            }
            //Paint
            tempCountry->setColor(this->colors->at(colorActual) );                     //le asigna un color al pais
            cout << "color: " << tempCountry->getColor() << endl;

            backtracking(countriesList,paisActual+1,cantidadColores,0);          // hace backtracking con el siguiente pais para asignarle color
        }
    }
}

