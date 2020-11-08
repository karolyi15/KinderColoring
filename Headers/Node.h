//
// Created by gunther on 7/11/20.
//

#ifndef KINDERCOLORING_NODE_H
#define KINDERCOLORING_NODE_H

template<typename Type>

class Node {

private:

    Type value;
    Node *previous;
    Node *next;

public:

    //Constructor
    Node(Type value){

        this->value = value;
        this->previous = nullptr;
        this->next = nullptr;
    };

    //Setters & Getters

    void setValue(Type value){

        this->value = value;
    };

    Type getValue(){

        return this->value;
    };

    void setPrevious(Node* previous){

        this->previous = previous;
    };

    Node* getPrevious(){

        return this->previous;
    };

    void setNext(Node* next){

        this->next = next;
    };

    Node* getNext(){

        return this->next;
    };

};


#endif //KINDERCOLORING_NODE_H
