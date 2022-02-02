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
    //matrix operator- (const matrix &matrix2);  // Оставить
    friend matrix operator- (matrix const &, matrix const &);  // Убрать
    void show_matrix();  // Заменить на оператор вывода в поток << (нужен friend)
    ~matrix(){
        delete [] data;
    };
private:
    unsigned int row;
    unsigned int column;
    double *data = nullptr;
    unsigned int rank = 0;  // Зачем ??
    double det = 0;  // Зачем?

};


#endif //NEW_MATRIX_MATRIX2_0_H
