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

    bool usedColor = false;

    for(int color =0; color<this->colorSet; color++) {

        for (int set = 0; set < openSet->size(); set++) {

            if(ColorType::getPosition(color) == openSet->at(set)){

                usedColor =true;
            }
        }

        if (usedColor) {

            usedColor = false;

        }else{

            this->paintedNodes++;
            return ColorType::getPosition(color);
        }

    }

    this->blankNodes++;
    return Color::DEFAULT;
}


void DivideConquerPainter::divideConquer(std::vector<Country*> countriesList) {

    if(countriesList.size() == 1){
        //*** Conquer ***

        Country *tempCountry = countriesList.at(0);

        if(tempCountry->getColor() == Color::DEFAULT) {
            //std::cout << "entro"<< std::endl;

            std::vector<MapNode *> *limitCountries = tempCountry->getLimitCountries();


            if (limitCountries->size() != 0) {

                std::vector<Color> *openSetColors = new std::vector<Color>;

                for (int count = 0; count < limitCountries->size(); count++) {

                    Country *tempCountry = (Country *) limitCountries->at(count);

                    Color tempColor = tempCountry->getColor();

                    if (tempColor != Color::DEFAULT) {

                        openSetColors->push_back(tempColor);
                    }
                }


                //Paint

                //int randomColor = random()%this->colorSet+1;
                //tempCountry->setColor(ColorType::getPosition(randomColor));
                //tempCountry->setColor(Color::RED);
                tempCountry->setColor(this->verifyColor(openSetColors));

            } else {

                //Solos Countries
                this->paintedNodes++;
                tempCountry->setColor(ColorType::getPosition(0));

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


    }
}
