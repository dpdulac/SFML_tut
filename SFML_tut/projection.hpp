//
//  projection.hpp
//  SFML_tut
//
//  Created by David Dulac on 02/04/2022.
//

#ifndef projection_hpp
#define projection_hpp

#include <math.h>
#include<iostream>
#include<vector>

using namespace std;

#pragma once
class Projection
{
private:

    float angle{ 10.0f };

    const float PI{ 3.14159265358979323846 };

    vector<vector<float>> input_PMatrice {};

    vector<vector<float>> projected_points{
        {1,0,0},
        {0,1,0},
        {0,0,0}
    };

    //matrice for rotation z

    vector<vector<float>> rotation_z{
        {cosf(this->angle_r()),-sinf(this->angle_r()),0.00},
        {sinf(this->angle_r()),cosf(this->angle_r()),0.00},
        {0.00,0.00,1.00}
    };

    //matrice for rotation y
    vector<vector<float>> rotation_y{
        {cosf(this->angle_r()),0.00,sinf(this->angle_r())},
        {0.00,1.00,0.00},
        {-sinf(this->angle_r()),0.00,cosf(this->angle_r())}
    };

    //matrice for rotation x
    vector<vector<float>> rotation_x{
        {1.00,0.00,0.00},
        {0.00,cosf(this->angle_r()),-sinf(this->angle_r())},
        {0.00,sinf(this->angle_r()),cosf(this->angle_r())}
    };



public:

    Projection(vector<vector<float>>);

    void projected2D();

    void rotationZ();

    void rotationY();

    void rotationX();

    vector<vector<float>> modified_matrice();

    void angle_aug();

    float angle_r();

    void rotation_update();

};
#include <stdio.h>

#endif /* projection_hpp */
