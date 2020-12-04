//
// Created by home on 10.01.2017.
//

#include <vector>
#include "Field.h"
#include "Figure.h"

void Field::CreateBox(int length, int height) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < height; ++j) {
            field.push_back(Point(i, j));
        }
    }
}

void Field::PrintField(std::ostream& out /*= std::cout*/) const {
    for (size_t i = 0; i < field.size(); ++i) {
        field[i].print(out);
    }
}

bool Field::FigureIntersection(std::vector<int>& points, const Figure& fig) {
    std::vector<int> tmp(5);
    int count = 0;
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < field.size(); ++i) {
            if (field[i] == fig.points[j]) {
                tmp[j] = i;
                count++;
            }
        }
    }
    if(count != 5) {
        return false;
    }

    points = tmp;
    return true;

}

std::vector<std::pair<Type, std::vector<int> > > Field::BuildIntersectionMatrix(const std::vector<Figure>& figures) {
    std::vector<std::pair<Type, std::vector<int> > > matrix;
    int n_cols = field.size();
    for (auto fig: figures) {
        for (auto p: field) {
            fig.Place(p);
            for (int j = 0; j < fig.Orientations(); ++j) {
                for (int i = 0; i < fig.Rotations(); ++i) {
                    std::vector<int> points;
                    if (FigureIntersection(points, fig)) {
                        std::vector<int> row(n_cols);
                        for (int k = 0; k < points.size(); ++k) {
                            row[points[k]] = 1;
                        }
                        matrix.push_back(std::make_pair(fig.GetType(), row));
                    }
                    fig.RotateClockWise();
                }
                fig.Transpose();
            }
        }
    }
    return matrix;
}

std::vector<Point> Field::getFieldPoints() const {
    return field;
}
