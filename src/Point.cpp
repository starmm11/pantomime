//
// Created by home on 09.01.2017.
//

#include "Point.h"

void Point::print(std::ostream& os /* = std::cout*/) const {
    os << "(" << x << ", " << y << ")";
}

Point operator+(const Point& left, const Point& right) {
    return Point(left.x + right.x, left.y + right.y);
}
Point operator-(const Point& left, const Point& right) {
    return Point(left.x - right.x, left.y - right.y);
}

