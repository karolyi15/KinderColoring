#include "../Headers/BacktrackingPainter.h"
#include <cstring>
#include <string.h>

//Constructor
BacktrackingPainter::BacktrackingPainter(SvgManager* svgManager) {

    //Init Country List
    this->svgManager = svgManager;
    map<string, Country*> * countriesHashmap = this->svgManager->getCountries();
    this->initCountries(countriesHashmap);

    //Paint System
    this->initColors();

}

//Setters & Getters
void BacktrackingPainter::setSvgManager(SvgManager *svgManager) {

    this->svgManager = svgManager;
}

void BacktrackingPainter::initCountries(map<string , Country *> *countriesHashMap) {

    //Define Iterator
    map<string, Country*>::iterator itr;

    //
    for(itr = countriesHashMap->begin(); itr != countriesHashMap->end(); itr++){

        this->countriesID.push_back(itr->second->getId());
    }
}

//Paint System
//Tienen que ser 11 colores
void BacktrackingPainter::initColors() {

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

void BacktrackingPainter::paint() {

    cout << "Painted" << endl;
    this->svgManager->writeSvg("../_MapFiles/BacktrackingWorld.svg");
    cout << "Saved" << endl;
}

bool BacktrackingPainter::paintLimits(vector <string>* limitCountries, int cantidadColores) {
    int count = 0;
    int countColores = 0;

    if(limitCountries->size()<cantidadColores){
        return false;
    }
    else{
        vector<char *> Colores;
        for (int pais = 0; pais < limitCountries->size(); pais++) {
            char *tempID = const_cast<char *>( limitCountries->at(pais).c_str());
            char *tempColor = this->svgManager->getCountries()->at(tempID)->getColor();
            if (tempColor != "#f2f2f2") {
                if(std::find(Colores.begin(), Colores.end(),tempColor)!=Colores.end()){
                    count++;
                }
                else{
                    count++;
                    Colores.push_back(tempColor);
                    countColores++;
                }
            }
        }
        if (count=limitCountries->size() && countColores == cantidadColores) {       // que todos los paises limites estan pintados y que todos los colores posibles se usaron
            return true;
        }else{return false;}
    }
}

// como mando el mismo pais o el pais siguiente osea el itr siguiente o el actual
int BacktrackingPainter::backtracking(int paisActual,int cantidadColores,int colorActual) {
    //cout<<"pez : "<<countriesID.size()<<endl;
    //cout<<"pez por el que voy: "<<paisActual<<endl;
    if (paisActual>=countriesID.size()) {
        //cout<<endl<<endl<<endl;
        //cout<<"Pez Feliz"<<endl;
        return 0;                                             //ya se recorrieron todos los paises
    }
    else {

        Country *tempCountry = this->svgManager->getCountries()->at(countriesID.at(paisActual));  //saca la info del pais actual

        //cout<<"Pais Actual: " <<this->svgManager->getCountries()->at(countriesID.at(paisActual))->getId()<<endl;
        //cout<< tempCountry->toString()<<endl;
        //cout<<"Limites : "<<endl;
        vector <string> *limitCountries = tempCountry->getBoundsCountries();            // los paises que son limites al pais actual

        if (colorActual > cantidadColores) {
            //SetColor
            tempCountry->setColor("#ffffff");                               //le asigna un color blanco al pais
           // cout << "color: " << tempCountry->getColor() << endl<<endl;

            return backtracking(paisActual+1,cantidadColores,0);              // hace backtracking con el siguiente pais para asignarle color
        }
        else {

            if (limitCountries->size() != 0) {
                //cout<<"Pez limites: "<<limitCountries->size()<<endl;
                                                                                        //Poda
                if(paintLimits(limitCountries,cantidadColores)){

                    //cout<<endl<<"ENTRE EN PODA"<<endl;

                    tempCountry->setColor("#ffffff");                               //le asigna un color blanco al pais
                    //cout << "color: " << tempCountry->getColor() << endl;
                    return backtracking(paisActual+1, cantidadColores, 0);
                }
                else {
                    // verifica que el color no este en ninguno de los paises frontera
                    for (int count = 0; count <= limitCountries->size() - 1; count++) {
                        char *tempID = const_cast<char *>( limitCountries->at(count).c_str());
                        // string te = limitCountries->at(count);
                        // cout<<te<<endl;
                        //cout << tempID << endl;
                        //cout << "La GAM " << endl;

                        // Country *temp = this->svgManager->getCountries()->at(countriesID.at(tempID));
                        //cout<<temp<<endl;


                        char *tempColor = this->svgManager->getCountries()->at(tempID)->getColor();     // color del pais frontera
                        //cout << "Color pais limite: " << tempColor << "       ";

                        //cout << "Color a compara: " << this->colors->at(colorActual) << endl;

                        if (tempColor == this->colors->at(colorActual)) {                                 // color del pais frontera = color a validar
                            //cout << "pez volador" << endl;
                           return backtracking(paisActual, cantidadColores, colorActual + 1);    // hace backtracking con el mismo pais pero con color diferente
                        }
                    }
                }
            }
            //SetColor
            tempCountry->setColor(this->colors->at(colorActual) );                     //le asigna un color al pais
            //cout << "Color pais actual: " << tempCountry->getColor() << endl;

            //cout<< endl<<endl;

            return backtracking(paisActual+1,cantidadColores,0);          // hace backtracking con el siguiente pais para asignarle color
        }
    }
}