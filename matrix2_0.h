//
// Created by п on 24.01.2022.
//

#ifndef NEW_MATRIX_MATRIX2_0_H
#define NEW_MATRIX_MATRIX2_0_H
#include<iostream>

class matrix {
public:
    matrix(unsigned int row, unsigned int column);
    matrix(const matrix& matrix);

    matrix(unsigned int row, unsigned int column,const double *mass);

    matrix& operator= (const matrix& matrix);
    matrix& operator*= (const matrix &matrix2);
    matrix& operator+= (const matrix& matrix2);
    matrix& operator-= (const matrix& matrix2);
    matrix operator* (const matrix &matrix2);
    matrix operator+ (const matrix &matrix2);
    //matrix operator- (const matrix &matrix2);
    friend matrix operator- (matrix const &, matrix const &);
    void show_matrix();
    ~matrix(){
        delete [] data;
    };
private:
    unsigned int row;
    unsigned int column;
    double *data = nullptr;
    unsigned int rank = 0;
    double det = 0;

};


#endif //NEW_MATRIX_MATRIX2_0_H
