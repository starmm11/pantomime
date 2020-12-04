//
// Created by home on 10.01.2017.
//

#ifndef PANTOMIME_FIELD_H
#define PANTOMIME_FIELD_H

#include <fstream>
#include <vector>
#include <utility>
#include "Figure.h"
#include "Point.h"

/*
 * Field is a matrix of 0 and 1.
 */

class Field {
public:
    Field() : field(0) {}
    Field(std::ostream& file);
    void CreateBox(int length, int height);
    bool FigureIntersection(std::vector<int>& points, const Figure& fig);
    std::vector<std::pair<Type, std::vector<int> > > BuildIntersectionMatrix(const std::vector<Figure>& figures);
    void PrintField(std::ostream& out = std::cout) const;
    std::vector<Point> getFieldPoints() const;
private:
    std::vector<Point> field;
};


#endif //PANTOMIME_FIELD_H
