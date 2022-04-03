//
//  MyPoint.cpp
//  SFML_tut
//
//  Created by David Dulac on 03/04/2022.
//

#include "MyPoint.hpp"

MyPoint::MyPoint(){
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}
MyPoint::MyPoint(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}
MyPoint::MyPoint(vector<double> mypt){
    unsigned long myptLength = mypt.size();
    switch(myptLength) {
        case 0:
            this->x = 0.0;
            this->y = 0.0;
            this->z = 0.0;
            break;
        case 1:
            this->x = mypt.at(0);
            this->y = 0.0;
            this->z = 0.0;
            break;
        case 2:
            this->x = mypt.at(0);
            this->y = mypt.at(1);
            this->z = 0.0;
            break;
        default:
            this->x = mypt.at(0);
            this->y = mypt.at(1);
            this->z = mypt.at(2);
    }
}

void MyPoint::setX(double x){ this->x = x;}
void MyPoint::setY(double y){ this->y = y;}
void MyPoint::setZ(double z){ this->z = z;}

double MyPoint::getX(){ return this->x;}
double MyPoint::getY(){ return this->y;}
double MyPoint::getZ(){ return this->z;}

