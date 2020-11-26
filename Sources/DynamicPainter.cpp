#include "../Headers/DynamicPainter.h"
#include <cstring>
#include <string.h>

//Constructor
DynamicPainter::DynamicPainter(SvgManager* svgManager) {

    //Init Country List
    this->svgManager = svgManager;
    map<string, Country*> * countriesHashmap = this->svgManager->getCountries();
    this->initCountries(countriesHashmap);

    //Paint System
    this->initColors();

}

//Setters & Getters
void DynamicPainter::setSvgManager(SvgManager *svgManager) {

    this->svgManager = svgManager;
}

void DynamicPainter::initCountries(map<string , Country *> *countriesHashMap) {

    //Define Iterator
    map<string, Country*>::iterator itr;

    //
    for(itr = countriesHashMap->begin(); itr != countriesHashMap->end(); itr++){

        this->countriesID.push_back(itr->second->getId());
    }
}

//Paint System
//Tienen que ser 11 colores
void DynamicPainter::initColors() {

    this->colors = new vector<char*>;

    this->colors->push_back("#55faf5"); //light blue
    this->colors->push_back("#cd2121"); //RED
    this->colors->push_back("#f4d02d"); //YELLOW
    this->colors->push_back("#124a68"); //BLUE
    this->colors->push_back("#fcbabc"); //PINK
    this->colors->push_back("#008000"); //Green
    this->colors->push_back("#ff4800"); //Orange
    this->colors->push_back("#8f008f"); //Purple
    this->colors->push_back("#00fc00"); //light green
    this->colors->push_back("#91602d"); //brown
    this->colors->push_back("#5dc1b9"); //turquoise

}

void DynamicPainter::paint() {

    cout << "Painted" << endl;
    this->svgManager->writeSvg("../_MapFiles/BacktrackingWorld.svg");
    cout << "Saved" << endl;
}


vector<char *> DynamicPainter::optimizarColores(vector <string>* limitCountries, int cantidadColores){
    vector<char *> coloresOptimos;

    for(int color = 0; color <= cantidadColores;color++){
        coloresOptimos.push_back(this->colors->at(color));     //tiene todos los colores posibles
    }

    for (int pais = 0; pais < limitCountries->size(); pais++) {
        char *tempID = const_cast<char *>( limitCountries->at(pais).c_str());
        char *tempColor = this->svgManager->getCountries()->at(tempID)->getColor();     
        if (tempColor != "#f2f2f2") {
            coloresOptimos.erase(std::remove(coloresOptimos.begin(), coloresOptimos.end(), tempColor), coloresOptimos.end());
        }
    }
    return coloresOptimos;                           
}


// como mando el mismo pais o el pais siguiente osea el itr siguiente o el actual
int DynamicPainter::dynamic(int paisActual,int cantidadColores) {

    if (paisActual>=countriesID.size()) {
        return 0;                                             //ya se recorrieron todos los paises
    }
    else {
        vector<char *> coloresOptimos;
        Country *tempCountry = this->svgManager->getCountries()->at(countriesID.at(paisActual));  //saca la info del pais actual
        vector <string> *limitCountries = tempCountry->getBoundsCountries();            // los paises que son limites al pais actual

        if (limitCountries->size() != 0) {
            //cout<<"Pez limites: "<<limitCountries->size()<<endl;
            
            coloresOptimos = optimizarColores(limitCountries,cantidadColores);      //Optimiza seleccion de colores

            if (coloresOptimos.size() == 0) {
                //SetColor
                tempCountry->setColor("#ffffff");                               //le asigna un color blanco al pais
                return dynamic(paisActual+1,cantidadColores);              // hace dynamic con el siguiente pais para asignarle color
            }
            else{
                
                char *tempColor = coloresOptimos.at(0);
                tempCountry->setColor(tempColor);
                return dynamic(paisActual+1,cantidadColores);
            }
        }
        else{
            char *tempColor = this->colors->at(0);
            tempCountry->setColor(tempColor);
            return dynamic(paisActual+1,cantidadColores);
        }
    }
}