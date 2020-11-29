#include "Models/Headers/MapDirector.h"
#include "Models/Headers/CountryFactory.h"
#include "Painters/Headers/PainterFactory.h"
#include <ctime>

int main() {
    srand (time(NULL));
    char * SVG_PATH = "../_MapFiles/world.svg";
    XmlManager *xmlManager = new XmlManager();

    CountryFactory *countryFactory = new CountryFactory();

    int colorSet = 5;
    PainterFactory *painterFactory = new PainterFactory();
    Painter *painter = painterFactory->createPainter(PainterType::DYNAMIC);
    painter->setColorSet(colorSet);

    //
    MapBuilder *builder = new MapBuilder();
    MapDirector *director = new MapDirector(builder);


    //
    Map *map = director->buildWorldMap(SVG_PATH, xmlManager,countryFactory,painter);
    //map->printNodes();
    map->paint();

    map->saveMapData();
    //map->printNodes();

   return 0;
}
