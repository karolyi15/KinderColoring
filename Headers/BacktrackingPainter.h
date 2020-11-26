#ifndef KINDERCOLORING_BACKTRACKINGPAINTER_H
#define KINDERCOLORING_BACKTRACKINGPAINTER_H


#include "Painter.h"

class BacktrackingPainter:Painter {
private:

    //Fields
    vector<string> countriesID;
    SvgManager *svgManager;
    vector<char*> *colors;

public:

    //Constructor
    BacktrackingPainter(SvgManager *svgManager);
    void initCountries(map<string, Country*>* countriesHashMap);

    //Setters & Getter
    void setSvgManager(SvgManager * svgManager);
    //Paint System
    void initColors();
    void paint();
    bool paintLimits(vector <string>* limitCountries, int cantidadColores);
    int backtracking(int paisActual,int cantidadColores,int colorActual);

};


#endif //KINDERCOLORING_BACKTRACKINGPAINTER_H
