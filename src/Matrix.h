//
// Created by home on 23.02.2017.
//

#ifndef PANTOMIME_DLIST_H
#define PANTOMIME_DLIST_H

#include <vector>
#include <string>
#include "Figure.h"
#include "Field.h"

struct Col;
struct Row;

struct Node {
    Node* left;
    Node* right;
    Node* up;
    Node* down;
    Col* col;
    Row* row;
};

struct Col {
    Col() : left(0), right(0), head(0), name(name), size(0) {}
    Col(int name) : left(0), right(0), head(0), name(name), size(0) {}
    Col* left;
    Col* right;
    Node* head;
    int name;
    int size;
};

struct Row {
    Row() : up(0), down(0), head(0), name(A), size(0) {}
    Row(Type type) : up(0), down(0), head(0), name(type), size(0) {}
    Row* up;
    Row* down;
    Node* head;
    Type name;
    int size;
};

class Matrix {
public:
    Matrix(int n, int m);
    Matrix(const std::vector<std::vector<int> >& vec);
    ~Matrix();

private:
    Col** cols;
    Row** rows;
    Col* fstcol;
    Row* fstrow;
    int cols_num;
    int rows_num;

private:
    void CreateCols(int num);
    void CreateRows(int num);
    void AddNodeLeft(Node* ref, Node* target);
    void AddNodeUp(Node* ref, Node* target);
    void AddNode(Col* col, Node* node);
    void AddNode(Col* col, Row* row);
};

#endif //PANTOMIME_DLLIST_H
