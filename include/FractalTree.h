#ifndef FRACTAL_TREES_HPP
#define FRACTAL_TREES_HPP

#include "Vector.h"

/*
Implements the Fractal Tree.
The basic idea of the implementation is based on a simple binary tree.
The data of the fractal tree contains two vectors, the origin and the destination.
*/
class FractalTree
{
public:
    FractalTree();
    FractalTree(Vector<double> origin_, Vector<double> destination_);
    ~FractalTree();

    void insertLevel();
    void print();

    Vector<double> origin,destination;
    class FractalTree* left;
    class FractalTree* right;
};


#endif
