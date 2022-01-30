#include <iostream>
#include "matrix2_0.h"
int main() {
    double a[9];
    double a1[9];
    int k=2;
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            a[j+i*3] =k;
            k++;
            a1[j+i*3]=k++;
        }
    }
    matrix b(3,3, a);
    matrix c(3,3,a1);
    matrix d(3,3);
    c*=b;
    c.show_matrix();
    b.show_matrix();
    //d.show_matrix();
    return 0;
}
