#include <iostream>
#include <cmath>
#include "Constants.h"
#include "Vector.h"

#include "FractalTree.h"


/*
Creates a tree without any successor and
with the origin and destination in 0,0.
*/
FractalTree::FractalTree()
{
    std::cout << "Fractal Tree: Default constructor" << std::endl;
    origin = Vector(0,0);
    destination = Vector(0,0);
    left = NULL;
    right = NULL;
}

/*
Creates a tree without any successor and
with the origin and destination at the given parameters.
*/
FractalTree::FractalTree(Vector origin_, Vector destination_)
{
    std::cout << "Fractal Tree: constructor with origin and destination" << std::endl;
    this->origin = origin_;
    this->destination = destination_;
    this->left = NULL;
    this->right = NULL;
}

/*
Deletes the tree recursively.
*/
void destroyTree(FractalTree* node)
{
    if(node)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

/*
Calls the destroyTree method which recursively deletes the tree.
*/
FractalTree::~FractalTree()
{
    destroyTree(this);
    std::cout << "Fractal Tree: Destructor" << std::endl;
}

/*
Prints the origin and destination of every node in the tree.
Uses preoder traversal.
*/
void FractalTree::print()
{
    std::cout << "origin: " << this->origin.x <<","<< this->origin.y
              << ", destination: " << this->destination.x <<","<< this->destination.y  << std::endl;

    if(this->left != NULL)
    {
        this->left->print();
    }
    if(this->right != NULL)
    {
        this->right->print();
    }
}

/*
Inserts a level to the tree.
If the level is not balanced (the left or the right node is already set),
the tree will be balanced.
If the level is balanced a whole level will be inserted.
(The amount of leaves will be doubled,
 e.g. the tree has N leaves at the moment,
 after a call of insertLevel() the amount is 2N leaves.)
*/
void FractalTree::insertLevel()
{
    Vector newVec = destination-origin;

    newVec.scale(RATIO);

    Vector newRight = newVec.rotate(DEGREE);
    Vector newLeft = newVec.rotate(-DEGREE);

    if(this->left == NULL && this->right == NULL) //insert left and right node
    {
        this->left = new FractalTree(this->destination, this->destination+newLeft);
        this->right = new FractalTree(this->destination, this->destination+newRight);

    }
    else if(this->left == NULL) // Balance degenerated tree, right node is already set
    {
        this->left = new FractalTree(this->destination, this->destination+newLeft);
    }
    else if(this->right == NULL) // Balance degenerated tree, left node is already set
    {
        this->right = new FractalTree(this->destination, this->destination+newRight);
    }
    else // left and right is already set, recursively call method on both branches.
    {
        this->left->insertLevel();
        this->right->insertLevel();
    }
}

