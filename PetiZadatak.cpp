#include <iostream>
#include <cmath>
using namespace std;

// STRUKTURA
struct Point {
    double x;
    double y;
};


// SA POINTERIMA

void move_by(Point* p, double dx, double dy) {
    p->x += dx;
    p->y += dy;
}

double dist(const Point* a, const Point* b) {
    double dx{a->x - b->x};
    double dy{a->y - b->y};

    return sqrt(dx * dx + dy * dy);
}


// SA REFERENCAMA

void move_by(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b) {
    double dx{a.x - b.x};
    double dy{a.y - b.y};

    return sqrt(dx * dx + dy * dy);
}




int main() {

    // TOCKA POINTER
    Point p1{2.0, 3.0};

    move_by(&p1, 1.0, 2.0);

    cout << "Pointer:" << endl;
    cout << "p1 = (" << p1.x << ", " << p1.y << ")" << endl;


    // TOCKA REFERENCA
    Point p2{5.0, 6.0};

    move_by(p2, -1.0, -2.0);

    cout << endl;

    cout << "Referenca:" << endl;
    cout << "p2 = (" << p2.x << ", " << p2.y << ")" << endl;


    
    cout << endl;

    cout << "Udaljenost pomocu pointera: "
         << dist(&p1, &p2) << endl;


    
    cout << "Udaljenost pomocu reference: "
         << dist(p1, p2) << endl;


   
    Point points[5]{
        {3.0, 4.0},
        {1.0, 1.0},
        {-2.0, 3.0},
        {0.5, 0.5},
        {5.0, 2.0}
    };

   
    Point origin{0.0, 0.0};

    int najbliza{0};

    double najmanjaUdaljenost{
        dist(points[0], origin)
    };

    for (int i{1}; i < 5; i++) {

        double udaljenost{
            dist(points[i], origin)
        };

        if (udaljenost < najmanjaUdaljenost) {
            najmanjaUdaljenost = udaljenost;
            najbliza = i;
        }
    }

    cout << endl;

    cout << "Tocka najbliza ishodistu: ("
         << points[najbliza].x << ", "
         << points[najbliza].y << ")" << endl;

    cout << "Udaljenost od ishodista: "
         << najmanjaUdaljenost << endl;


    return 0;
}