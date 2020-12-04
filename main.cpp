#include <iostream>
#include <vector>
#include "src/Figure.h"
#include "src/Field.h"

int main() {
    std::cout << "Hello\n";
    std::cout << int('A') << ' ' << int('B') << '\n';
    Field field;
    field.CreateBox(2, 5);
    std::vector<Point> p_field = field.getFieldPoints();
    std::vector<Figure> figures(1);
    for (int i = 0; i < 1; ++i) {
        figures[i] = Figure(static_cast<Type>(i), pantomime_figures_rotations[i], pantomime_figures_orients[i]);
    }
    Figure fig = Figure(A, 2, 1);
    for (int j = 0; j < fig.Orientations(); ++j) {
        for (int i = 0; i < fig.Rotations(); ++i) {
            for (Point p: fig.points) {
                p.print(std::cout);
            }
            std::cout << '\n';
            fig.RotateClockWise();
        }
        fig.Transpose();
    }
    auto m = field.BuildIntersectionMatrix(figures);
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].second.size(); ++j) {
            std::cout << m[i].second[j] << ' ';
        }
        std::cout << m[i].first << '\n';
    }

    return 0;
}