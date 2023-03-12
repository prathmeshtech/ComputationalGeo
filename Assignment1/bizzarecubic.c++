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


void createCurvePoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4){
    for (int i = 0; i < 10; i++) {
        double u = (double)i/10;
        double x = p1.x * (pow((1 - u), 3)) + p2.x * (3 * pow((1 - u),2)*(u)) + p3.x * (3 * (1 - u) * pow((u),2)) + p4.x * (pow((u),3));
        double y = p1.y * (pow((1 - u), 3)) + p2.y * (3 * pow((1 - u),2)*(u)) + p3.y * (3 * (1 - u) * pow((u),2)) + p4.y * (pow((u),3));
        
        cout<<x<<" "<<y<<endl;
    }
}

void ThreeLineSegments(){
    Point p1(2, 3);
    Point p2(5, 8);
    Point p3(7, 9);
    Point p4(10, 3);
    
    createCurvePoints(p1, p2, p3, p4);
}

int main(){
    ThreeLineSegments();
}