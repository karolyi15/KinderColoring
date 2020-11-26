//
// Created by gunther on 18/11/20.
//

#include <cstring>
#include "../Headers/DivideConquerPainter.h"

//Constructor
DivideConquerPainter::DivideConquerPainter() {

    this->id = "WDivideConquer.svg";
}


//Analyse Input Data
void DivideConquerPainter::setInputData(std::map<char *, MapNode *> *inputData) {

    std::map<char *, MapNode *>::iterator itr;

    for(itr = inputData->begin(); itr != inputData->end(); itr++){

        this->inputData.push_back((Country*) itr->second);
    }

}


//Painting System
void DivideConquerPainter::start() {

    this->divideConquer(this->inputData);
}


Color DivideConquerPainter::verifyColor(std::vector<Color> *openSet) {

    bool used = false;

    if(openSet->size() != 0){

        for(int color =0; color<this->colorSet; color++){

            for(int set = 0; set < openSet->size(); set++){

                if(ColorType::getPosition(color) == openSet->at(set)){
                    used = true;
                }
            }

            if(used == false){

                return ColorType::getPosition(color);

            }else{
                used = false;
            }

        }

        return Color::DEFAULT;

    }else{

        int randomColor = random()%this->colorSet-1;
        return ColorType::getPosition(randomColor);
    }
}


void DivideConquerPainter::divideConquer(std::vector<Country*> countriesList) {

    if(countriesList.size() == 1){
        //*** Conquer ***
        //cout << "caso base"<< endl;
        Country *tempCountry = countriesList.at(0);
        //cout <<"id: " << tempCountry->getId()<<" color "<< tempCountry->getColor()<< endl;


        if(tempCountry->getColor() == Color::DEFAULT) {
            //cout << "entro"<< endl;

            std::vector<MapNode*> *limitCountries = tempCountry->getLimitCountries();
            std::vector<Color> * openSetColors = new std::vector<Color>;

            if(limitCountries->size() != 0) {

                for (int count = 0; count < limitCountries->size(); count++) {

                    Country* tempCountry = (Country*) limitCountries->at(count);
                    char *tempID = tempCountry->getId();
                    Color tempColor = tempCountry->getColor();

                    if (tempColor != Color::DEFAULT) {

                        openSetColors->push_back(tempColor);
                    }
                }


                //Paint
                tempCountry->setColor(this->verifyColor(openSetColors));
            }
            //cout<< "color: " << tempCountry->getColor() << endl;
        }

        //cout<<"salio"<<endl;

    }else{

        //*** Divide ***
        int splitSize = countriesList.size()/2;
        std::vector<Country*> lower(countriesList.begin(), countriesList.begin()+splitSize);
        std::vector<Country*> higher(countriesList.begin()+splitSize, countriesList.end());

        divideConquer(lower);
        divideConquer(higher);

        //** Merge ***

    }
}
