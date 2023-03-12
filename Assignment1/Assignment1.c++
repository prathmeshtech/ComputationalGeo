#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class Point {
    public:
    float x = 0, 
          y = 0,
          z = 0;

    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }
};

// ---------------------------------------------------------------Bezier Curve-------------------------------------------------------------------
void createBezeirCurve(const Point &p1, const Point &p2, const Point &p3, const Point &p4){
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
    
    createBezeirCurve(p1, p2, p3, p4);
}

// ---------------------------------------------------------------Curve from 2 lines-------------------------------------------------------------------

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

// ---------------------------------------------------------------Line-------------------------------------------------------------------

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
// ---------------------------------------------------------------Circle-------------------------------------------------------------------
void drawCircle() {
     double x, y, z=10;
    const double pi = 3.14159265358979323846;
    double angle = M_PI * 2 / 40.0;
    double r = 5;

    
    for (double i = 0; i <= 2*M_PI ; i+=angle) 
    {
        x = r * cos(i);             
        y = r * sin(i);          
        cout<< x << " " << y << " " << z << endl;
    }
}

int  main() {
    lineSegment();
    curveFromTwoLineSegments();
    ThreeLineSegments();
    drawCircle();
}