#define _USE_MATH_DEFINES
#include<iostream>
// #include "stdafx.h"
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
struct GVector
{
    double data[3] = { 0.0,0.0,0.0 };
};
typedef vector<GVector> Curve;
typedef vector<Curve > Surface;

std::string base_name(std::string const& path)
{
    return path.substr(path.find_last_of("/\\") + 1);
}

bool generateEllipse(GVector centrePoint, double radius, int numU, Curve& curve)
{
     double r, x, y, z=50;
    const double pi = 3.14159265358979323846;
    double angle = M_PI * 2 / numU;

    
    for (double i = 0; i <= 2*M_PI ; i+=angle) 
    {
        struct GVector vec;
        x = r * cos(i);             
        y = r * sin(i);   
        vec.data[0] = x;
        vec.data[1] = y;
        vec.data[2] = z; 
        curve.push_back(vec);     
        // cout<< x << " " << y << " " << z << endl;
    }
    
    return true;
}

bool generateCircle(GVector centrePoint, double radius, int numU, Curve& curve)
{
    double r, x, y, z=10;
    const double pi = 3.14159265358979323846;
    double angle = M_PI * 2 / numU;

    
    for (double i = 0; i <= 2*M_PI ; i+=angle) 
    {
        struct GVector vec;
        x = r * cos(i);             
        y = r * sin(i);   
        vec.data[0] = x;
        vec.data[1] = y;
        vec.data[2] = z; 
        curve.push_back(vec);     
        // cout<< x << " " << y << " " << z << endl;
    }
    
    return true;

}


// bool writeGNU(Surface loftSurface, string filename)
// {
//     ofstream outFileHandle;
//     outFileHandle.open(filename, ios::out | ios::trunc);
//     outFileHandle << fixed << setprecision(4);
//     for (int i = 0; i < loftSurface.size(); i++)
//     {
//         for (int j = 0; j < loftSurface[i].size(); j++) {
//             for (int k = 0; k < 3; k++) {
//                 outFileHandle << loftSurface[i][j].data[k] << " ";
//             }
//             outFileHandle << endl;
//         }
//     outFileHandle << endl;
//     }
//     outFileHandle.close();
//     return true;
// }

// bool displayGNU(string programName, vector <string> dataFiles) 
// {
//     ofstream outFileHandle;
//     outFileHandle.open("gnuScript.plt", ios::out | ios::trunc);
//     outFileHandle << "set title '" << programName <<"'"<< endl;
//     outFileHandle << "set view equal xyz"<<endl;
//     outFileHandle << "set view ,,.3" << endl;
//     //outFileHandle << "set nokey" << endl; 
//     outFileHandle << "set hidden3d" << endl;
//     outFileHandle << "splot ";
//     for (int i=0; i < dataFiles.size(); i++)
//     {
//         outFileHandle << "'"<<dataFiles[i]<<"' w l";
//         if (i < (dataFiles.size()-1))
//             outFileHandle << ",";
//     }
//     outFileHandle <<endl<< "pause -9 \"Hit Enter\" " << endl;
//     outFileHandle.close();
//     system("wgnuplot.exe gnuScript.plt");
//     return true;
// }

bool generateSurfaceLoft(Curve c1, Curve c2, int numV, Surface& loftSurface)
{  
    ofstream MyFile("C:/gnuplot/circeSquare.dat");
    cout<<"check"<<endl;
    cout<<c1.size()<<endl;
    cout<<c2.size()<<endl;
    // if (c1.size() != c2.size())
    //     return false;
    double deltaV = 1.0 / (numV - 1);
    Curve c;
    c.resize(c1.size());
    for (double v = 0; v <= 1.0; v += deltaV)
    {
        for (int i = 0; i < c1.size(); i++) {
            for (int j = 0; j < 3; j++) {
                c[i].data[j] = c1[i].data[j] * (1 - v) + c2[i].data[j] * v;
                // cout<<c[i].data[j]<<" ";
                MyFile<<c[i].data[j]<<" ";
            }
            // cout<<endl;
            MyFile<<endl;
        }
        loftSurface.push_back(c);
    }

    MyFile.close();
    return true;
}

int main(int argc, char** argv)
{
    string programName;
    vector <string> dataFiles;
    programName = argv[0];
    int index = 0; 
    double r, r1, r2;

    vector <Curve> sections;
    vector <Surface> surfacesPatch;
    Curve circle;
    Curve ellipse;
    Surface loftSurface;
    

    cout << "Enter the radius: ";
    cin >> r;

    cout << "Enter the Major & Minor: ";
    cin >> r1;

    generateCircle(GVector{ 0.0,0.0,0.0 }, r, 100, circle);
    generateEllipse(GVector{ 0.0,0.0,0.0 }, r1, 4, ellipse );

    // sections.resize(10);
    // surfacesPatch.resize(9);     //bottum surface  index = 0

    // generateConics(GVector{ 0.0,0.0,0.0 }, 0, 0, 72, sections[index]);
    // generateConics(GVector{ 0.0,0.0,0.0 }, 30, 30, 72, sections[index+1]);

    generateSurfaceLoft(circle, ellipse, 100, loftSurface);

    // dataFiles.push_back("baseSurface.gnu");

    // writeGNU(surfacesPatch[index], dataFiles.back());

    // index++;     //chamfer surface index = 1   
    
    // generateConics(GVector{ 0.0,0.0,12.0 }, 40, 40, 72, sections[index+1]);

    // generateSurfaceLoft(sections[index ], sections[index+1], 10, surfacesPatch[index]);

    // dataFiles.push_back("chamferSurface.gnu");

    // writeGNU(surfacesPatch[index ], dataFiles.back());

    // index++;     //main surface index = 2    

    // generateConics(GVector{ 0.0,0.0,170.0 }, 40, 40, 72, sections[index+1]);

    // generateSurfaceLoft(sections[index], sections[index+1], 10, surfacesPatch[index]);

    // dataFiles.push_back("mainSurface.gnu");

    // writeGNU(surfacesPatch[index], dataFiles.back());

    // index++;     //conic surface index = 3    

    // generateConics(GVector{ 0.0,0.0,230.0 }, 20, 20, 72, sections[index + 1]);

    // generateSurfaceLoft(sections[index], sections[index + 1], 10, surfacesPatch[index]);

    // dataFiles.push_back("conicSurface.gnu");

    // writeGNU(surfacesPatch[index], dataFiles.back());

    // index++;     //extend surface index = 4    

    // generateConics(GVector{ 0.0,0.0,290.0 }, 20, 20, 72, sections[index + 1]);

    // generateSurfaceLoft(sections[index], sections[index + 1], 10, surfacesPatch[index]);

    // dataFiles.push_back("extendSurface.gnu");

    // writeGNU(surfacesPatch[index], dataFiles.back());

    // index++;

    // displayGNU(base_name(programName), dataFiles);

    return 1;
}