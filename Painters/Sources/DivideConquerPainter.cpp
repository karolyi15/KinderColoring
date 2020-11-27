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
    std::cout<<"Entro"<<std::endl;
    bool used = false;

    if(openSet->size() != 0){

        for(int color =0; color<this->colorSet; color++){

            for(int set = 0; set < openSet->size(); set++){

                if(ColorType::getPosition(color) == openSet->at(set)){
                    used = true;
                }
            }

            if(used == false){

                std::cout<<"Salio"<<std::endl;
                return ColorType::getPosition(color);

            }else{
                used = false;
            }

        }
        std::cout<<"Salio"<<std::endl;
        return Color::DEFAULT;

    }else{

        int randomColor = random()%this->colorSet-1;
        std::cout<<"Salio"<<std::endl;
        return ColorType::getPosition(randomColor);
    }

}


void DivideConquerPainter::divideConquer(std::vector<Country*> countriesList) {

    if(countriesList.size() == 1){
        //*** Conquer ***

        Country *tempCountry = countriesList.at(0);

        if(tempCountry->getColor() == Color::DEFAULT) {
            //std::cout << "entro"<< std::endl;

            std::vector<MapNode *> *limitCountries = tempCountry->getLimitCountries();
            std::vector<Color> *openSetColors = new std::vector<Color>;

            if (limitCountries->size() != 0) {

                for (int count = 0; count < limitCountries->size(); count++) {

                    Country *tempCountry = (Country *) limitCountries->at(count);

                    Color tempColor = tempCountry->getColor();

                    if (tempColor != Color::DEFAULT) {

                        openSetColors->push_back(tempColor);
                    }
                }


                //Paint
                int randomColor = random()%this->colorSet+1;
                tempCountry->setColor(ColorType::getPosition(randomColor));
                //tempCountry->setColor(Color::RED);
                //tempCountry->setColor(this->verifyColor(openSetColors));

            } else {
                int randomColor = random()%this->colorSet+1;
                tempCountry->setColor(ColorType::getPosition(randomColor));
                //Solos Countries
                //tempCountry->setColor(Color::RED);
            }

            //cout<<"salio"<<endl;
        }

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
