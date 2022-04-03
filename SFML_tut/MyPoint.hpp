//
//  MyPoint.hpp
//  SFML_tut
//
//  Created by David Dulac on 03/04/2022.
//

#ifndef MyPoint_hpp
#define MyPoint_hpp

#include <iostream>
#include <cmath>
#include<vector>
using namespace std;

class MyPoint {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    
public:
    MyPoint();
    MyPoint(double x, double y, double z);
    MyPoint(vector <double> mypt);
    
    // setter
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    
    // getter
    double getX();
    double getY();
    double getZ();
    
};

#endif /* MyPoint_hpp */
