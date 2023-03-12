#include <iostream>

using namespace std;

class Point {
    public:
    double x = 0, 
          y = 0,
          z = 0;

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

void createLinePoints(const Point &p1, const Point &p2) {
    for (int i = 0; i < 10; i++) {
        double u = (double)i/10;
        double x = p1.x * (1 - u) + p2.x * u;
        double y = p1.y * (1 - u) + p2.y * u;

        cout<<x<<" "<<y<<endl;
    }
}

void lineSegment(){
    Point p1(2, 3);
    Point p2(5, 6);

    createLinePoints(p1, p2);
}

int main() {
    lineSegment();

    return 0;
}