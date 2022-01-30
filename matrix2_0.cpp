#include "matrix2_0.h"
#include<iostream>
#include<cassert>
using namespace std;
matrix:: matrix(unsigned int row, unsigned int column): row(row), column(column){
    assert(column !=0 && row !=0);
    data = new double[row*column];
}
matrix:: matrix(unsigned int row, unsigned int column,const double *mass): matrix::matrix(row, column){
    for(unsigned int i=0; i<row; i++){
        for(unsigned int j=0; j<column; j++){
            data[j+i*column] = mass[j+i*column];
        }
    }
}
matrix::matrix(const matrix &matrix): matrix::matrix(matrix.row, matrix.column){
    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < column; j++) {
            data[j+i*column] =matrix.data[j+i*column];
        }
    }
}
matrix& matrix::operator= (const matrix& matrix){
    if (this == &matrix) {
        return *this;
    }
    delete[] data;
    data = nullptr;
    column = matrix.column;
    row = matrix.row;
    data = new double [column*row];
    for (unsigned int i = 0; i <matrix.row; i++) {
        for (unsigned int j = 0; j < matrix.column; j++) {
            this->data[j+i*column] = matrix.data[j+i*column];
        }
    }
    this->det = matrix.det;
    this->rank = matrix.rank;
    return *this;
}
matrix& matrix::operator*= (const matrix &matrix2) {
    assert(column==matrix2.row && row==matrix2.column);
    double *new_data = new double [row*matrix2.column];
    for(unsigned int i=0; i<row; i++){
        for(unsigned int j=0; j<matrix2.column; j++){
            new_data[j+i*matrix2.column]=0;
            for(unsigned int k=0; k<column; k++){
                new_data[j+i*matrix2.column] +=data[k+i*column]*matrix2.data[j+k*column];
            }
        }
    }
    delete [] data;
    data = new_data;
    return *this;
}
matrix& matrix::operator+= (const matrix &matrix2) {
    assert(column==matrix2.column && row==matrix2.row);
    for(unsigned int i=0; i<row; i++){
        for(unsigned int j=0; j<column; j++){
            data[j+i*column]+=matrix2.data[j+i*column];
        }
    }
    return *this;
}
matrix& matrix::operator-= (const matrix &matrix2) {
    assert(column==matrix2.column && row==matrix2.row);
    for(unsigned int i=0; i<row; i++){
        for(unsigned int j=0; j<column; j++){
            data[j+i*column]-=matrix2.data[j+i*column];
        }
    }
    return *this;
}
matrix matrix::operator+ (matrix const &matrix2){
    assert(column==matrix2.column && row==matrix2.row);
    matrix new_matrix(row, column);
    for(unsigned int i=0; i<row; i++){
        for(unsigned int j=0; j<column; j++){
            new_matrix.data[j+i*column] = data[j+i*column]+matrix2.data[j+i*column];
        }
    }
    return new_matrix;
}

/*
matrix matrix::operator- (matrix const &matrix2){
    assert(column==matrix2.column && row==matrix2.row);
    matrix new_matrix(row, column);
    for(unsigned int i=0; i<row; i++){
        for(unsigned int j=0; j<column; j++){
            new_matrix.data[j+i*column] = data[j+i*column]+matrix2.data[j+i*column];
        }
    }
    return new_matrix;
}
*/


matrix operator- (const matrix &matrix1, const matrix &matrix2){
    double new_data[matrix1.row*matrix1.column];
    for(unsigned int i=0; i<matrix1.row; i++){
        for(unsigned int j=0; j<matrix1.column; j++){
            new_data[j+i*matrix1.column] = matrix1.data[j+i*matrix1.column] - matrix2.data[j+i*matrix1.column];
        }
    }
    return matrix(matrix1.row, matrix1.column, new_data);
}

matrix matrix::operator* (const matrix &matrix2){
    assert(column==matrix2.row && row==matrix2.column);
    matrix new_matrix(row, matrix2.column);
    for(unsigned int i=0; i<row; i++){
        for(unsigned int j=0; j<matrix2.column; j++){
            new_matrix.data[j+i*matrix2.column]=0;
            for(unsigned int k=0; k<column; k++){
                new_matrix.data[j+i*matrix2.column]+=data[k+i*column]*matrix2.data[j+k*column];
            }
        }
    }
    return new_matrix;
}
void matrix::show_matrix() {
    cout<<fixed;
    cout.precision(3);
    cout<<" Your matrix : \n";
    for(unsigned int i=0; i<row; i++){
        for(unsigned int j=0; j<column; j++){
            cout<<data[i*column + j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Matrix determinant = "<< det<<"\n";
    cout<<"Matrix rank = "<< rank<<"\n";
    cout<< "Matrix rows = "<< row<<"\n";
    cout<<"Matrix columns = "<< column<<"\n";
}
