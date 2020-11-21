//
// Created by gunther on 18/11/20.
//


#ifndef KINDERCOLORING_BACKTRACKINGPAINTER_H
#define KINDERCOLORING_BACKTRACKINGPAINTER_H


#include "Painter.h"

class BacktrackingPainter:Painter {
private:

    //
    vector<char*> countriesID;

public:
    //Constructor
    BacktrackingPainter();
    void initCountries(map<char*, Country*>* countriesHashMap);
};


#endif //KINDERCOLORING_BACKTRACKINGPAINTER_H

/*
 * 			//estructura, pais, cantidad de colores posibles
Backtracking(hasmap, contador, colores){
	if (contador = size hasmap){
		return (hasmap);				//Que retorne el hasmap o un bool
	}
	else{
		int color = rand() % colores + 1

		list paises_frontera = sacarpaises(hasmap, contador);			//map.second.getlimits

																			//Nose si tiene que ser un o o un y

		if (tienencolor(hasmap,paises_frontea) && size.fronteras<colores) {		// todos los paises frontera ya tienen color y
			hasmap[blancos].add(pais);											// se anade a los paises blancos
			Backtracking(hasmap, contador+1, colores);							// hace backtracking con el siguiente pais para asignarle color
		}

		else{
			For(paisfrontera=0,paisfrontera<=paises_frontera.size, paisfrontera++){
				if(color == hasmap[paisfrontera].color){					// pregunta que si el color seleccionado es el mismo que el de otro pais frontera
					Backtracking(hasmap, contador, colores); 				// Hace que vuelva a seleccionar otro color
				}																// se encicla si el pais tiene varias fronteras y estas ya estan pintadas
			}																	// ver si con el if de arriba funka

			hasmap[contador].color = color;										// le asigna el color al pais

			Backtracking(hasmap, contador+1, colores);							// hace backtracking con el siguiente pais para asignarle color
		}
	}
}
 */