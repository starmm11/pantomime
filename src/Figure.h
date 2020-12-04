//
// Created by home on 09.01.2017.
//

#ifndef PANTOMIME_FIGURE_H
#define PANTOMIME_FIGURE_H

#include <iostream>
#include <vector>
#include <map>
//abstract class for pantomime figures
#include "Point.h"

/*
 A ##### E ###  I  #
           # #    ###
                   #

 B ####  F ###  J ###
      #      ##     #
                    #

 C ####  G #    K ###
     #     ###     #
             #     #

 D ###   H #    L ##
    ##     ###     ##
            #       #
*/
enum Type {A, B, C, D, E, F, G, H, I, J, K, L};
enum Rotation {RIGHT, DOWN, LEFT, UP};
enum Orientation {NORMAL, MIRROR};

std::ostream& operator<<(std::ostream& out, const Type& value);

static const std::vector<int> pantomime_figures_rotations = {2, 4, 4, 4, 4, 4, 4, 4, 1, 4, 4, 4};
static const std::vector<int> pantomime_figures_orients = {1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 1, 2};

class Figure {
public:
    Figure(); // create line
    Figure(const std::vector<Point>& points, int n_rotations, int n_orients);
    Figure(Type type, int n_rotations, int n_orients);
    ~Figure() = default;
    void Print(std::ostream& os = std::cout) const;
    int Rotations() const;
    int Orientations() const;
    void RotateClockWise();
    Type GetType() const;
    void Transpose();
    void Place(const Point& p); // Place to point p
    Point points[5];

private:
    int n_rotations;
    int n_orients;
    Rotation rotation;
    Orientation orient;
    Type type;

    void CreateFigure(Type type);
    void create_A(); void create_B(); void create_C(); void create_D(); void create_E(); void create_F();
    void create_G(); void create_H(); void create_I(); void create_J(); void create_K(); void create_L();

    void Rotate(Rotation rot);
    void RotateUp(); // right -> up
    void RotateDown(); // right -> down
    void RotateLeft(); // right -> left
    void Transpose(Orientation orient);
    void Mirror(); // normal -> Mirror
    void CheckRotationSymmetry(int rot) const;
    void CheckTransposeSymmetry(int trans) const;
};



#endif //PANTOMIME_FIGURE_H
