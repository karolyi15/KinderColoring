//
// Created by mari on 3/11/2020.
//

#ifndef KINDERCOLORING_NODO_H
#define KINDERCOLORING_NODO_H

#include <cstdlib>
#include <stdexcept>    //biblioteca de errores
#include "Arco.h" 
using namespace std;
template <typename E>

class Nodo {
public:
    E element;
    Node<E>*next;
    Arco *adyacente;


};


#endif //KINDERCOLORING_NODO_H
