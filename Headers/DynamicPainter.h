#ifndef KINDERCOLORING_DYNAMICPAINTER_H
#define KINDERCOLORING_DYNAMICPAINTER_H


#include "Painter.h"

class DynamicPainter:Painter {
private:

    //Fields
    vector<string> countriesID;
    SvgManager *svgManager;
    vector<char*> *colors;


public:

    //Constructor
    DynamicPainter(SvgManager *svgManager);
    void initCountries(map<string, Country*>* countriesHashMap);

    //Setters & Getter
    void setSvgManager(SvgManager * svgManager);
    //Paint System
    void initColors();
    void paint();
    vector<char *> optimizarColores(vector <string>* limitCountries, int cantidadColores)
    int dynamic(int paisActual,int cantidadColores);
    
};


#endif //KINDERCOLORING_DYNAMICPAINTER_H
