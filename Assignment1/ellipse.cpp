#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double r1, r2, x, y, z=10;
    const double pi = 3.14159265358979323846;
    double angle = M_PI * 2 / 40.0;


    cout << "Enter the major: ";
    cin >> r1;
    cout << "Enter the major: ";
    cin >> r2;

    
    for (double i = 0; i <= 2*M_PI ; i+=angle) 
    {
        x = r1 * cos(i);             
        y = r2 * sin(i);          
        cout<< x << " " << y << " " << z << endl;
    }

    return 0;
}