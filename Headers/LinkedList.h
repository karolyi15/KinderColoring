//
// Created by gunther on 7/11/20.
//


#include "Node.h"
#include <iostream>

#ifndef KINDERCOLORING_LINKEDLIST_H
#define KINDERCOLORING_LINKEDLIST_H

template <typename Type>

class LinkedList {

private:

    Node<Type> * head;
    int length;

public:

    //Constructor
    LinkedList(){

        this->head = nullptr;
        this->length = 0;
    }

    //Setter & Getters
    int getLength(){

        return this->length;
    }

    Node<Type>* getNode(int index){

        if( index< 0 || index> this->length){

            return nullptr;
        }
        else if(this->head == nullptr){

            return nullptr;

        } else {

            Node<Type> *tempNode = this->head;
            for (int counter = 1; counter <= index; counter++) {
                tempNode = tempNode->getNext();
            }

            return tempNode;
        }
    }

    //Nodes Management
    void add(Type value){

        if(this->head != nullptr){

            Node<Type>* tempNode = head;
            while(tempNode->getNext() != nullptr){

                tempNode = tempNode->getNext();
            }

            tempNode->setNext(new Node<Type>(value));
            this->length ++;

        }else{

            this->head = new Node<Type> (value);
            this->length ++;
        }
    }

    void print(){

        Node<Type>* tempNode = this->head;

        for(int counter = 0; counter< this->length; counter++){

            std::cout << tempNode->getValue();
            tempNode = tempNode->getNext();
        }
    }

};


#endif //KINDERCOLORING_LINKEDLIST_H
