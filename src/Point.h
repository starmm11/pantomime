//
// Created by home on 09.01.2017.
//

#ifndef PANTOMIME_POINT_H
#define PANTOMIME_POINT_H

#include <iostream>

class Point {
public:
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
    Point(const Point& p) : x(p.x), y(p.y) {}
//    void operator=(int a, int b) { x = a; y = b; }
    Point & operator+=(const Point& p) { x += p.x; y += p.y; return *this; }
    bool operator==(const Point& p) { return ((x == p.x) && (y == p.y)) ? true : false;}
    friend Point operator+(const Point& left, const Point& right);
    friend Point operator-(const Point& left, const Point& right);
    void print(std::ostream& os = std::cout) const;
    int x, y;
};



#endif //PANTOMIME_POINT_H
