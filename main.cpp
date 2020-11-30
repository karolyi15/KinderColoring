#include "Models/Headers/MapDirector.h"
#include "Models/Headers/CountryFactory.h"
#include "Painters/Headers/PainterFactory.h"
int main() {

    int colorSet = 5;
    srand (time(NULL));
    char * SVG_PATH = "../_MapFiles/world.svg";
    XmlManager *xmlManager = new XmlManager();

    CountryFactory *countryFactory = new CountryFactory();

    PainterFactory *painterFactory = new PainterFactory();

    Painter *painter = painterFactory->createPainter(PainterType::DIVIDEANDCONQUER);
    painter->setColorSet(colorSet);

    //
    MapBuilder *builder = new MapBuilder();
    MapDirector *director = new MapDirector(builder);


    //Create Backtracking Svg
    Map *map = director->buildWorldMap(SVG_PATH, xmlManager,countryFactory,painter);
    map->paint();
    //map->printNodes();

   return 0;
}
