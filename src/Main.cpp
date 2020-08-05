#include <cstdlib>
#include <iostream>
#include <gtkmm-3.0/gtkmm.h>
#include <gtkmm-3.0/gtkmm/application.h>
#include "FractalTree.h"
#include "Draw.h"
#include "Constants.h"
#include "Vector.h"

/*
Creates a fractal tree and a Gtk::Application.
Prints the tree to the window of the application.
*/
int main(int argc, char** argv)
{
    Vector origin = Vector(WIDTH/2, HEIGHT);
    Vector destination = Vector(WIDTH/2, HEIGHT-LENGTH_OF_FIRST);

    FractalTree* tree = new FractalTree(origin,destination);

    for (int i = 0; i < RECURSION_DEPTH; i++){
        tree->insertLevel();
    }

    tree->print();

    auto app = Gtk::Application::create(argc, argv);

    Gtk::Window window;
    window.set_default_size(WIDTH,HEIGHT);
    window.set_title("Fractal Trees - C++ homework - Chris Gabler");

    MyDrawingArea area;
    area.tree = tree;
    window.add(area);
    area.show();

    return app->run(window);
}
