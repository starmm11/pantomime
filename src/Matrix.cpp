//
// Created by home on 23.02.2017.
//

#include "Matrix.h"

Matrix::Matrix(int n, int m) {
    CreateCols(n);
    CreateRows(m);
}

Matrix::Matrix(const std::vector<std::vector<int> >& vec){
    if (vec.empty()) {
        std::cout << "Empty matrix";
        return;
    }
    int m = vec.size();
    int n = vec[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vec[i][j] == 1) {
                AddNode(cols[i], rows[j]);
            }
        }
    }
}

void Matrix::CreateCols(int num) {
    cols_num = num;
    cols = new Col*[num];
    if (num < 1) {
        std::cout << "no columns created\n";
        return;
    }
    for (int i = 0; i < num; ++i) {
        cols[i] = new Col();
    }
    if (num == 1) {
        cols[0]->left = cols[0];
        cols[0]->right = cols[0];
        return;
    }
    if (num > 2) {
        for (int i = 1; i < num - 1; ++i) {
            cols[i]->left = cols[i + 1];
            cols[i]->right = cols[i - 1];
        }
    }
    cols[0]->right = cols[1];
    cols[0]->left = cols[num-1];
    cols[num-1]->right = cols[0];
    cols[num-1]->left = cols[num-2];
}

void Matrix::CreateRows(int num) {
    rows_num = num;
    if (num < 1) {
        std::cout << "no rows created\n";
        return;
    }
    rows = new Row*[num];
    for (int i = 0; i < num; ++i) {
        rows[i] = new Row();
    }
    if (num == 1) {
        rows[0]->up = rows[0];
        rows[0]->down = rows[0];
        return;
    }
    if (num > 2) {
        for (int i = 1; i < num - 1; ++i) {
            rows[i]->down = rows[i + 1];
            rows[i]->up = rows[i - 1];
        }
    }
    rows[0]->down = rows[1];
    rows[0]->up = rows[num-1];
    rows[num-1]->down = rows[0];
    rows[num-1]->up = rows[num-2];
}

void Matrix::AddNode(Col* col, Row* row) {
    Node* node = new Node();
    node->col = col;
    node->row = row;
    col->size++; row->size++;
    Node* row_node = row->head;
    Node* col_node = col->head;
}
