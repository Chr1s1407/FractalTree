#ifndef GTKMM_EXAMPLE_MYAREA_H
#define GTKMM_EXAMPLE_MYAREA_H

#include <gtkmm/drawingarea.h>
#include "FractalTree.h"

/*
Derives the Gtk::DrawingArea which is used to draw the tree.
*/
class MyDrawingArea : public Gtk::DrawingArea
{
public:
    MyDrawingArea();
    virtual ~MyDrawingArea();
    class FractalTree* tree;

protected:
    //Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

};

#endif // GTKMM_EXAMPLE_MYAREA_H
