#ifndef PARSETREE_H_INCLUDED
#define PARSETREE_H_INCLUDED

#include <iostream>
#include "projlex.h"

class Node
{
    //Properties of a Parent Node
    public:
        Node *leftChild = NULL;
        Node *rightChild = NULL;
        Token nodeContent;


};

#endif // PARSETREE_H_INCLUDED
