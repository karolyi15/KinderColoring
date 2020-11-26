//
// Created by gunther on 18/11/20.
//

#include <cstring>
#include "../Headers/DivideConquerPainter.h"
/*
//Constructor
DivideConquerPainter::DivideConquerPainter(SvgManager* svgManager) {

    //Init Country List
    this->svgManager = svgManager;
    map<char*, Country*> * countriesHashmap = this->svgManager->getCountries();
    this->initCountries(countriesHashmap);

    //Paint System
    this->initColors();

}

//Setters & Getters
void DivideConquerPainter::setSvgManager(SvgManager *svgManager) {

    this->svgManager = svgManager;
}

void DivideConquerPainter::initCountries(map<char *, Country *> *countriesHashMap) {

    //Define Iterator
    map<char*, Country*>::iterator itr;

    //
    for(itr = countriesHashMap->begin(); itr != countriesHashMap->end(); itr++){

       this->countriesID.push_back(itr->second->getId());
    }
}

//Paint System

void DivideConquerPainter::initColors() {

    this->colors = new vector<char*>;


    this->colors->push_back("#cd2121"); //RED
    this->colors->push_back("#f4b22d"); //YELLOW
    this->colors->push_back("#124a68"); //BLUE
    this->colors->push_back("#c126b3"); //PINK

}

char * DivideConquerPainter::verifyColor(vector<string> *openSet) {

    bool used = false;

    if(openSet->size() != 0){

        for(int color =0; color<this->colors->size(); color++){

            for(int set = 0; set < openSet->size(); set++){

                if(this->colors->at(color) == openSet->at(set)){
                    used = true;
                }
            }

            if(used == false){

                return this->colors->at(color);

            }else{
                used = false;
            }

        }

        return "#c126b3";

    }else{

        int randomColor = random()%this->colors->size()-1;
        return this->colors->at(randomColor);
    }
}

void DivideConquerPainter::paint() {

    divideConquer(this->countriesID);
    cout << "Painted" << endl;
    this->svgManager->writeSvg("../_MapFiles/DivideConquerWorld.svg");
    cout << "Saved" << endl;
}

void DivideConquerPainter::divideConquer(vector<char*> countriesList) {

    if(countriesList.size() == 1){
        //*** Conquer ***
        cout << "caso base"<< endl;
        Country *tempCountry = this->svgManager->getCountries()->at(countriesList.at(0));
        cout <<"id: " << tempCountry->getId()<<" color "<< tempCountry->getColor()<< endl;


        if(strcmp(tempCountry->getColor(),"#f2f2f2" ) == 0) {
            cout << "entro"<< endl;

            vector<string> *limitCountries = tempCountry->getBoundsCountries();
            vector<string> * openSetColors = new vector<string>;

            if(limitCountries->size() != 0) {
                for (int count = 0; count < limitCountries->size(); count++) {

                    char *tempID = const_cast<char *>(limitCountries->at(count).c_str());
                    //char* tempColor = this->svgManager->getCountries()->at( tempID)->getColor();
                    char *tempColor = "";
                    if (tempColor != "#f2f2f2") {

                        openSetColors->push_back(tempColor);
                    }
                }


                //Paint
                tempCountry->setColor(this->verifyColor(openSetColors));
            }
            cout<< "color: " << tempCountry->getColor() << endl;
        }

        cout<<"salio"<<endl;

    }else{

        //*** Divide ***
        int splitSize = countriesList.size()/2;
        std::vector<char*> lower(countriesList.begin(), countriesList.begin()+splitSize);
        std::vector<char*> higher(countriesList.begin()+splitSize, countriesList.end());

        divideConquer(lower);
        divideConquer(higher);

        //** Merge ***

    }
}
*/