//
//  projection.cpp
//  SFML_tut
//
//  Created by David Dulac on 02/04/2022.
//

#include "projection.hpp"

Projection::Projection(vector<vector<float>> input_matrice) : input_PMatrice(input_matrice){

}

void Projection::projected2D() {
    
    int column{ 0 };

    for (auto& i : this->input_PMatrice) {
        for (auto& e : i) {

            if (column == 0) {
                e = e * projected_points[0][0];
                column += 1;
            }
            else if (column == 1) {
                e = e * projected_points[1][1];
                column += 1;
            }
            else {
                e = e * projected_points[2][2];
                column = 0;
            }

        }
    }
    
}

void Projection::rotationZ() {

    int row{ 0 };
    int column{ 0 };

    double sum_x{ 0.00 };
    double sum_y{ 0.00 };
    double sum_z{ 0.00 };

    for (auto& i : this->input_PMatrice) {
        for (auto& e : i) {
            if (column == 0){
                sum_x += e * rotation_z[0][column];
                sum_y += e * rotation_z[1][column];
                sum_z += e * rotation_z[2][column];
                column += 1;
            }
            else if (column == 1) {
                sum_x += e * rotation_z[0][column];
                sum_y += e * rotation_z[1][column];
                sum_z += e * rotation_z[2][column];
                column += 1;
            }
            else {
                sum_x += e * rotation_z[0][column];
                sum_y += e * rotation_z[1][column];
                sum_z += e * rotation_z[2][column];
                column = 0;
            }
        }
        column = 0;
        this->input_PMatrice[row][column] = sum_x ;
        this->input_PMatrice[row][column + 1] = sum_y;
        this->input_PMatrice[row][column + 2] = sum_z;
        sum_x = 0.00;
        sum_y = 0.00;
        sum_z = 0.00;
        row += 1;
    }

}

void Projection::rotationY() {

    int row{ 0 };
    int column{ 0 };

    double sum_x{ 0.00 };
    double sum_y{ 0.00 };
    double sum_z{ 0.00 };

    for (auto& i : this->input_PMatrice) {
        for (auto& e : i) {
            if (column == 0) {
                sum_x += e * rotation_y[0][column];
                sum_y += e * rotation_y[1][column];
                sum_z += e * rotation_y[2][column];
                column += 1;
            }
            else if (column == 1) {
                sum_x += e * rotation_y[0][column];
                sum_y += e * rotation_y[1][column];
                sum_z += e * rotation_y[2][column];
                column += 1;
            }
            else {
                sum_x += e * rotation_y[0][column];
                sum_y += e * rotation_y[1][column];
                sum_z += e * rotation_y[2][column];
                column = 0;
            }
        }
        column = 0;
        this->input_PMatrice[row][column] = sum_x;
        this->input_PMatrice[row][column + 1] = sum_y;
        this->input_PMatrice[row][column + 2] = sum_z;
        sum_x = 0.00;
        sum_y = 0.00;
        sum_z = 0.00;
        row += 1;
    }
}

void Projection::rotationX() {

    int row{ 0 };
    int column{ 0 };

    double sum_x{ 0.00 };
    double sum_y{ 0.00 };
    double sum_z{ 0.00 };

    for (auto& i : this->input_PMatrice) {
        for (auto& e : i) {
            if (column == 0) {
                sum_x += e * rotation_x[0][column];
                sum_y += e * rotation_x[1][column];
                sum_z += e * rotation_x[2][column];
                column += 1;
            }
            else if (column == 1) {
                sum_x += e * rotation_x[0][column];
                sum_y += e * rotation_x[1][column];
                sum_z += e * rotation_x[2][column];
                column += 1;
            }
            else {
                sum_x += e * rotation_x[0][column];
                sum_y += e * rotation_x[1][column];
                sum_z += e * rotation_x[2][column];
                column = 0;
            }
        }
        column = 0;
        this->input_PMatrice[row][column] = sum_x;
        this->input_PMatrice[row][column + 1] = sum_y;
        this->input_PMatrice[row][column + 2] = sum_z;
        sum_x = 0.00;
        sum_y = 0.00;
        sum_z = 0.00;
        row += 1;
    }
}

vector<vector<float>> Projection::modified_matrice() {
    return input_PMatrice;
}

void Projection::angle_aug() {
    angle += 0.1f;
}

float Projection::angle_r() {
    return (this->angle * M_PI) / 180.0f;
}

void Projection::rotation_update(){
    rotation_z = {
        {cosf(this->angle_r()),-sinf(this->angle_r()),0.00},
        {sinf(this->angle_r()),cosf(this->angle_r()),0.00},
        {0.00,0.00,1.00}
    };

    rotation_y = {
        {cosf(this->angle_r()),0.00,sinf(this->angle_r())},
        {0.00,1.00,0.00},
        {-sinf(this->angle_r()),0.00,cosf(this->angle_r())}
    };

    rotation_x = {
        {1.00,0.00,0.00},
        {0.00,cosf(this->angle_r()),-sinf(this->angle_r())},
        {0.00,sinf(this->angle_r()),cosf(this->angle_r())}
    };

}
