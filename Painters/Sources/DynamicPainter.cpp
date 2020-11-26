//
// Created by gunther on 18/11/20.
//

#include "../Headers/DynamicPainter.h"


//Constructor
DynamicPainter::DynamicPainter() {

    this->id = "WDynamic.svg";
}

//Analyse Input Data
void DynamicPainter::setInputData(std::map<char *, MapNode *> *inputData) {

    std::map<char *, MapNode *>::iterator itr;

    for(itr = inputData->begin(); itr != inputData->end(); itr++){

        this->inputData.push_back((Country*) itr->second);
    }

}

//Painting System
void DynamicPainter::start() {

    this->dynamic(0,this->colorSet);

}

std::vector<Color> DynamicPainter::optimizarColores(std::vector<MapNode *> *limitCountries, int cantidadColores) {

    std::vector<Color> coloresOptimos;

    for(int color = 0; color <= cantidadColores;color++){
        coloresOptimos.push_back(ColorType::getPosition(color));     //tiene todos los colores posibles
    }

    for (int pais = 0; pais < limitCountries->size(); pais++) {

        Country *tempCountry = (Country*) limitCountries->at(pais);

        char *tempID = tempCountry->getId();
        Color tempColor = tempCountry->getColor();

        if (tempColor != Color::DEFAULT) {

            std::vector<Color>::iterator itr;

            for(int count =0; count< coloresOptimos.size(); count++){

                if(coloresOptimos.at(count) == tempColor){

                    coloresOptimos.erase(coloresOptimos.begin()+count-1);
                }
            }
        }
    }
    return coloresOptimos;

}

int DynamicPainter::dynamic(int paisActual, int cantidadColores) {

    if (paisActual>=this->inputData.size()) {

        return 0;                                             //ya se recorrieron todos los paises
    }
    else {

        vector<Color> coloresOptimos;

        Country *tempCountry = this->inputData.at(paisActual);  //saca la info del pais actual
        vector<MapNode *> *limitCountries = tempCountry->getLimitCountries();            // los paises que son limites al pais actual

        if (limitCountries->size() != 0) {
            //cout<<"Pez limites: "<<limitCountries->size()<<endl;

            coloresOptimos = optimizarColores(limitCountries, cantidadColores);      //Optimiza seleccion de colores

            if (coloresOptimos.size() == 0) {
                //SetColor
                tempCountry->setColor(Color::DEFAULT);                               //le asigna un color blanco al pais
                return dynamic(paisActual + 1,
                               cantidadColores);              // hace dynamic con el siguiente pais para asignarle color
            } else {

                Color tempColor = ColorType::getPosition(0);
                tempCountry->setColor(tempColor);
                return dynamic(paisActual + 1, cantidadColores);
            }
        } else {
            Color tempColor = ColorType::getPosition(0);
            tempCountry->setColor(tempColor);
            return dynamic(paisActual + 1, cantidadColores);
        }
    }
}