//
// Created by home on 09.01.2017.
//

#include "Figure.h"

std::ostream& operator<<(std::ostream& out, const Type& value) {
    return out << static_cast<char>(value + 65);
}



Figure::Figure() {
    type = A; rotation = RIGHT; orient = NORMAL;
    create_A();
}

Figure::Figure(const std::vector<Point>& p, int n_rotations, int n_orients) : n_rotations(n_rotations), n_orients(n_orients) {
    CheckRotationSymmetry(n_rotations);
    CheckTransposeSymmetry(n_orients);

    for (int i = 0; i < 5; ++i) {
        points[i] = p[i];
    }
}

Figure::Figure(Type type, int n_rotations, int n_orients) : n_rotations(n_rotations), n_orients(n_orients), type(type)
{
    CheckRotationSymmetry(n_rotations);
    CheckTransposeSymmetry(n_orients);

    CreateFigure(type);
    rotation = RIGHT;
    orient = NORMAL;
}

void Figure::Print(std::ostream& os /* = std::cout*/) const {
    for (int i = 0; i < 5; ++i) {
        points[i].print(os);
        os << ' ';
    }
    os << '\n';
}

void Figure::create_A() {
    for (int i = 0; i < 5; ++i) {
        points[i] = {i, 0};
    }
}

void Figure::create_B() {
    for (int i = 0; i < 4; ++i) {
        points[i] = {i, 0};
    }
    points[4] = {3, -1};
}

void Figure::create_C() {
    for (int i = 0; i < 4; ++i) {
        points[i] = {i, 0};
    }
    points[4] = {2, -1};
}

void Figure::create_D() {
    for (int i = 0; i < 3; ++i) {
        points[i] = {i, 0};
    }
    points[3] = {1, -1};
    points[4] = {2, -1};
}

void Figure::create_E() {
    for (int i = 0; i < 3; ++i) {
        points[i] = {i, 0};
    }
    points[3] = {0, -1};
    points[4] = {2, -1};
}

void Figure::create_F() {
    for (int i = 0; i < 3; ++i) {
        points[i] = {i, 0};
    }
    points[3] = {2, -1};
    points[4] = {3, -1};
}

void Figure::create_G() {
    points[0] = {0, 0};
    for (int i = 1; i < 4; ++i) {
        points[i] = {i-1, -1};
    }
    points[4] = {2, -2};
}

void Figure::create_H() {
    points[0] = {0, 0};
    for (int i = 1; i < 4; ++i) {
        points[i] = {i-1, -1};
    }
    points[4] = {1, -2};
}

void Figure::create_I() {
    points[0] = {1, 0};
    for (int i = 1; i < 4; ++i) {
        points[i] = {i-1, -1};
    }
    points[4] = {1, -2};
}

void Figure::create_J() {
    for (int i = 0; i < 3; ++i) {
        points[i] = {i, 0};
    }
    points[3] = {2, -1};
    points[4] = {2, -2};
}

void Figure::create_K() {
    for (int i = 0; i < 3; ++i) {
        points[i] = {i, 0};
    }
    points[3] = {1, -1};
    points[4] = {1, -2};
}

void Figure::create_L() {
    for (int i = 0; i < 2; ++i) {
        points[i] = {i, 0};
    }
    points[2] = {1, -1};
    points[3] = {2, -1};
    points[4] = {2, -2};
}

void Figure::CreateFigure(Type type) {
    switch(type) {
        case A:
            create_A();
            break;
        case B:
            create_B();
            break;
        case C:
            create_C();
            break;
        case D:
            create_D();
            break;
        case E:
            create_E();
            break;
        case F:
            create_F();
            break;
        case G:
            create_G();
            break;
        case H:
            create_H();
            break;
        case I:
            create_I();
            break;
        case J:
            create_J();
            break;
        case K:
            create_K();
            break;
        case L:
            create_L();
            break;
        default:
            break;
    }
}

void Figure::RotateUp() {

    Point rotation_point = points[0];
    for (int i = 1; i < 5; ++i) {
        int points_x = points[i].x;
        points[i].x = -(points[i].y - rotation_point.y) + rotation_point.x;
        points[i].y = (points_x - rotation_point.x) + rotation_point.y;
    }
}

void Figure::RotateClockWise() {
    if (n_rotations == 4) {
        RotateDown();
        rotation = static_cast<Rotation>((static_cast<int>(rotation) + 1)%4);
    } else if (n_rotations == 2) {
        if (rotation == RIGHT) {
            RotateDown();
        } else {
            RotateUp();
        }

        rotation = static_cast<Rotation>((static_cast<int>(rotation) + 2)%4);
    }
}

void Figure::Transpose() {
    // Mirror symmetry against x-axis
    for (int i = 1; i < 5; ++i) {
        //points[i].x = points[i].x
        points[i].y = points[0].y-(points[i].y-points[0].y);
    }
    orient = static_cast<Orientation >((static_cast<int>(orient) + 1)%2);
}

void Figure::RotateDown() {
    Point rotation_point = points[0];
    for (int i = 1; i < 5; ++i) {
        int points_x = points[i].x;
        points[i].x = (points[i].y - rotation_point.y) + rotation_point.x;
        points[i].y = -(points_x - rotation_point.x) + rotation_point.y;
    }
}

void Figure::RotateLeft() {
    Point rotation_point = points[0];
    for (int i = 1; i < 5; ++i) {
        points[i].x = -(points[i].x - rotation_point.x) + rotation_point.x;
        points[i].y = -points[i].y;
    }
}

void Figure::Rotate(Rotation rot) {
    switch (rot) {
        case RIGHT:
            rotation = RIGHT;
            break;
        case LEFT:
            rotation = LEFT;
            RotateLeft();
            break;
        case UP:
            rotation = UP;
            RotateUp();
            break;
        case DOWN:
            rotation = DOWN;
            RotateDown();
            break;
    }
}

void Figure::Place(const Point& p) {
    Point displace_vector = p - points[0];
    points[0] = p;
    for(int i = 1; i < 5; ++i) {
        points[i] += displace_vector;
    }
}

void Figure::Mirror() {
    // Mirror symmetry against x-axis
    for (int i = 1; i < 5; ++i) {
        //points[i].x = points[i].x
        points[i].y = -points[i].y;
    }
}

void Figure::Transpose(Orientation orient) {
    switch (orient) {
        case NORMAL:
            orient = NORMAL;
            break;
        case MIRROR:
            orient = MIRROR;
            Mirror();
            break;
    }
}

void Figure::CheckRotationSymmetry(int rot) const {
    if (rot != 1 && rot != 2 && rot != 4) {
        std::cerr << "Figure can only have 1, 2 or 4 types or rotations in this code\n";
        exit(1);
    }
}

void Figure::CheckTransposeSymmetry(int trans) const {
    if (trans != 1 && trans != 2) {
        std::cerr << "Figure can only be transposable or not. Choose 1 or 2 \n";
        exit(1);
    }
}

int Figure::Rotations() const {
    return n_rotations;
}

int Figure::Orientations() const {
    return n_orients;
}

Type Figure::GetType() const {
    return type;
}



