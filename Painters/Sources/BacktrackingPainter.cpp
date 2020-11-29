//
// Created by gunther on 18/11/20.
//

#include "../Headers/BacktrackingPainter.h"

//Constructor
BacktrackingPainter::BacktrackingPainter() {

    this->id = "WBacktracking.svg";
}

//Analyse Input Data
void BacktrackingPainter::setInputData(std::map<char *, MapNode *> *inputData) {

    std::map<char *, MapNode *>::iterator itr;

    for(itr = inputData->begin(); itr != inputData->end(); itr++){

        this->inputData.push_back((Country*) itr->second);
    }

}

//Painting System
void BacktrackingPainter::start() {

    this->backtracking(0,this->colorSet,0);
}

bool BacktrackingPainter::paintLimits(std::vector <MapNode*> *limitCountries, int cantidadColores) {

    int count = 0;
    int countColores = 0;

    if(limitCountries->size()<cantidadColores){

        return false;
    }
    else{

        std::vector<Color> openSet;

        for (int pais = 0; pais < limitCountries->size(); pais++) {

            Country* tempCountry = (Country*) limitCountries->at(pais);
            char *tempID = tempCountry->getId();
            Color tempColor = tempCountry->getColor();

            if (tempColor != Color::DEFAULT) {

                if(ColorType::getPosition(10) != tempColor){
                    count++;
                }
                else{
                    count++;
                    openSet.push_back(tempColor);
                    countColores++;
                }
            }
        }
        if (count=limitCountries->size() && countColores == cantidadColores) {       // que todos los paises limites estan pintados y que todos los colores posibles se usaron
            return true;
        }else{return false;}
    }
}

int BacktrackingPainter::backtracking(int paisActual, int cantidadColores, int colorActual) {

    if (paisActual>=this->inputData.size()) {
        //cout<<endl<<endl<<endl;
        //cout<<"Pez Feliz"<<endl;
        return 0;                                             //ya se recorrieron todos los paises
    }
    else {

        Country *tempCountry = this->inputData.at(paisActual);  //saca la info del pais actual

        //cout<<"Pais Actual: " <<this->svgManager->getCountries()->at(countriesID.at(paisActual))->getId()<<endl;
        //cout<< tempCountry->toString()<<endl;
        //cout<<"Limites : "<<endl;
        std::vector <MapNode*> *limitCountries = tempCountry->getLimitCountries();  // los paises que son limites al pais actual

        if (colorActual > cantidadColores-1) {
            //SetColor
            tempCountry->setColor(Color::DEFAULT);                               //le asigna un color blanco al pais
            // cout << "color: " << tempCountry->getColor() << endl<<endl;

            return backtracking(paisActual+1,cantidadColores,0);              // hace backtracking con el siguiente pais para asignarle color
        }
        else {

            if (limitCountries->size() != 0) {
                //cout<<"Pez limites: "<<limitCountries->size()<<endl;
                //Poda
                if(paintLimits(limitCountries,cantidadColores)){

                    //cout<<endl<<"ENTRE EN PODA"<<endl;

                    tempCountry->setColor(Color::DEFAULT);                               //le asigna un color blanco al pais
                    //cout << "color: " << tempCountry->getColor() << endl;
                    return backtracking(paisActual+1, cantidadColores, 0);
                }
                else {
                    // verifica que el color no este en ninguno de los paises frontera
                    for (int count = 0; count <= limitCountries->size() - 1; count++) {

                        Country* tempCountry = (Country*) limitCountries->at(count);
                        char *tempID = tempCountry->getId();
                        // string te = limitCountries->at(count);
                        // cout<<te<<endl;
                        //cout << tempID << endl;
                        //cout << "La GAM " << endl;

                        // Country *temp = this->svgManager->getCountries()->at(countriesID.at(tempID));
                        //cout<<temp<<endl;


                        Color tempColor = tempCountry->getColor();     // color del pais frontera
                        //cout << "Color pais limite: " << tempColor << "       ";

                        //cout << "Color a compara: " << this->colors->at(colorActual) << endl;

                        if (tempColor == ColorType::getPosition(colorActual)) {                                 // color del pais frontera = color a validar
                            //cout << "pez volador" << endl;
                            return backtracking(paisActual, cantidadColores, colorActual + 1);    // hace backtracking con el mismo pais pero con color diferente
                        }
                    }
                }
            }
            //SetColor
            tempCountry->setColor(ColorType::getPosition(colorActual) );                     //le asigna un color al pais
            //cout << "Color pais actual: " << tempCountry->getColor() << endl;

            //cout<< endl<<endl;

            return backtracking(paisActual+1,cantidadColores,0);          // hace backtracking con el siguiente pais para asignarle color
        }
    }
}