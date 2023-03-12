#include <iostream>
#include <math.h>
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

void createQuadCurvePoints(const Point &p1, const Point &p2, const Point &p3){
    for (int i = 0; i < 10; i++) 
    {
        double u = (double)i/10;
        double x = p1.x*pow((1 - u), 2) + p2.x * 2 * (1 - u)*(u) + p3.x * pow((u),2); 
        double y = p1.y*pow((1 - u), 2) + p2.y * 2 * (1 - u)*(u) + p3.y * pow((u),2);
        
        cout<<x<<" "<<y<<endl;
    }
}

void curveFromTwoLineSegments(){
    Point p1(2, 3);
    Point p2(5, 4);
    Point p3(8, 3);

    createQuadCurvePoints(p1, p2, p3);
}

int main() {
    curveFromTwoLineSegments();
    return 0;
}