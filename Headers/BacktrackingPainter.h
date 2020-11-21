#ifndef KINDERCOLORING_BACKTRACKINGPAINTER_H
#define KINDERCOLORING_BACKTRACKINGPAINTER_H


#include "Painter.h"

class BacktrackingPainter:Painter {
private:

    //Fields
    vector<char*> countriesID;
    SvgManager *svgManager;
    vector<char*> *colors;

public:

    //Constructor
    BacktrackingPainter(SvgManager *svgManager);
    void initCountries(map<char*, Country*>* countriesHashMap,int paisActual,int cantidadColores,int colorActual);

    //Setters & Getter
    void setSvgManager(SvgManager * svgManager);
    //Paint System
    void initColors();
    void paint();
    void backtracking(vector<char*> countriesList,);
    char* verifyColor(vector<string> *openSet);
};


#endif //KINDERCOLORING_BACKTRACKINGPAINTER_H
