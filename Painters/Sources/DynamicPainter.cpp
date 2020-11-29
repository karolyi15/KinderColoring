//
// Created by gunther on 18/11/20.
//

#include "../Headers/DynamicPainter.h"
#include <vector>
#include "time.h"


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
    //cout <<endl <<endl  <<"Pez esta Optimizando Colores: "<<endl;

    std::vector<Color> coloresOptimos;

    for(int color = 0; color < cantidadColores;color++){
        coloresOptimos.push_back(ColorType::getPosition(color));     //tiene todos los colores posibles
        //cout <<"Ingresando: "<< ColorType::getHexColor(ColorType::getPosition(color))<<"  vector de coloresOptimos"<<endl;
    }

   // cout<<endl;

    for (int pais = 0; pais < limitCountries->size(); pais++) {

        Country *tempCountry = (Country*) limitCountries->at(pais);

        char *tempID = tempCountry->getId();
       // cout<<"Pais limite: " <<tempID<<endl;

        Color tempColor = tempCountry->getColor();
        //cout<<"Color del Pais limite: " << ColorType::getHexColor(tempColor)<<endl;

        if (tempColor != Color::DEFAULT) {

            std::vector<Color>::iterator itr;

            for(int count =0; count< coloresOptimos.size(); count++){
                //cout<<"Tamano de coloresOptimos: "<<coloresOptimos.size()<<endl;
               // cout<<"-------- Estoy en el for que elimina color ---------"<<endl;

                if(coloresOptimos.at(count) == tempColor){
                    //cout<<"          Color a borrar:  "<< ColorType::getHexColor(coloresOptimos.at(count))<< endl ;
                    //cout<<"          Color del pais limite:  "<<ColorType::getHexColor(tempColor)<<endl;

                    //cout<<"Doy problema";
                    //cout<<ColorType::getHexColor(coloresOptimos.at(count))<<endl;
                    coloresOptimos.erase(coloresOptimos.begin()+count);
                   // cout<<"Borrado con exito"<<endl;
                    //cout<<"Tamano de coloresOptimos despues de borrar: "<<coloresOptimos.size()<<endl;
                }

            }
        }
    }
/*
    for(int i = 0; i < coloresOptimos.size();i++){
        cout <<"Color que queda: "<< ColorType::getHexColor(coloresOptimos.at(i))<<endl;
    }*/

    return coloresOptimos;

}

int DynamicPainter::dynamic(int paisActual, int cantidadColores) {
   // cout <<endl <<"Pez: "<< paisActual <<endl;

    if (paisActual>=this->inputData.size()) {
       // cout<<endl<<endl<<endl;
        //cout<<"Pez Feliz"<<endl;

        return 0;                                         //ya se recorrieron todos los paises
    }
    else {
        //cout<< " ---------------- Entre al else -------------"<<endl;

        vector<Color> coloresOptimos;
        Country *tempCountry = this->inputData.at(paisActual);  //saca la info del ais actual

        //cout<<"Pais Actual: " << this->inputData.at(paisActual)->getId()<< endl;
       // cout<< tempCountry->toString()<<endl;

        vector<MapNode *> *limitCountries = tempCountry->getLimitCountries();            // los paises que son limites al pais actual

        if (limitCountries->size() != 0) {

            //cout<<"Cantidad de limites: "<<limitCountries->size()<<endl;

            coloresOptimos = optimizarColores(limitCountries, cantidadColores);      //Optimiza seleccion de colores

            /*cout<<endl;
            for(int i = 0; i < coloresOptimos.size();i++){
                cout <<"Color que queda: "<< ColorType::getHexColor(coloresOptimos.at(i))<<endl;
            }*/


           // cout <<"Cantidad de colores optimos: " <<coloresOptimos.size() << endl;

            if (coloresOptimos.size() == 0) {
                //SetColor
                tempCountry->setColor(Color::DEFAULT);                               //le asigna un color blanco al pais

               // cout << "Color default: " << ColorType::getHexColor(tempCountry->getColor()) << endl;

                return dynamic(paisActual + 1, cantidadColores);              // hace dynamic con el siguiente pais para asignarle color
            } else {
               // cout<< " ^^^ Entre a pais que todavia tiene colores posible  ^^^ "<<endl;
                //cout <<"Cantidad de colores optimos: " <<coloresOptimos.size() << endl;
                srand (time(NULL));

                /* generate secret number between 1 and 10: */
                int position = rand() % coloresOptimos.size();

                Color tempColor = coloresOptimos.at(position);
                tempCountry->setColor(tempColor);

                //cout << "Color del pais, que tiene limites: " << ColorType::getHexColor(tempCountry->getColor()) << endl;

                return dynamic(paisActual + 1, cantidadColores);
            }
        } else {
            //cout<< " **** Entre al segundo else **** "<<endl;

            Color tempColor = ColorType::getPosition(0);
            tempCountry->setColor(tempColor);

            //cout << "Color del pais, no tiene limites: " << ColorType::getHexColor(tempCountry->getColor()) << endl;

            return dynamic(paisActual + 1, cantidadColores);
        }
    }
}