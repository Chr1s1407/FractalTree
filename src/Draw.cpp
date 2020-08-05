#include <cairomm/context.h>
#include "Draw.h"
#include "FractalTree.h"
#include "Constants.h"

MyDrawingArea::MyDrawingArea()
{
}

MyDrawingArea::~MyDrawingArea()
{
}

/*
Prints the tree recursively.
After reaching a leaf, the method returns.
*/
void printTree(class FractalTree* tree, const Cairo::RefPtr<Cairo::Context>& cr)
{
    // when the current node equals NULL, the previous node was a leaf
    if(tree==NULL)
    {
        return;
    }
    else
    {
        // first move to the origin of the node (which is the destination of the root),
        // then draw a line to the current destination
        cr->move_to(tree->origin.x, tree->origin.y);
        cr->line_to(tree->destination.x, tree->destination.y);

        // recursively call the method for left and right subtrees
        printTree(tree->left, cr);
        printTree(tree->right, cr);
    }
}

/*
Sets the parameters for the cursor, then prints the tree and strokes it.
*/
bool MyDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    cr->set_line_width(LINE_WIDTH);
    cr->set_source_rgb(BACKGROUND_R,BACKGROUND_G,BACKGROUND_B);
    cr->paint();
    cr->set_source_rgb(COLOR_R, COLOR_G, COLOR_B);


    // print the tree recursively
    printTree(MyDrawingArea::tree, cr);

    // stroke line, so the result will be shown
    cr->stroke();

    return true;
}
