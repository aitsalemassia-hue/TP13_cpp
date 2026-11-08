#include "Matrice.h"

int main() {
    Matrice<int,2,3> A = {1,2,3,4,5,6};
    Matrice<int,3,2> B = {1,2,3,4,5,6};
    std::cout<<"A * B = {"<<std::endl;
    std::cout << A * B;
    std::cout<<"}"<<std::endl;
    Matrice<double,2,2> C = {1.5, 2, 3, 4};
    Matrice<double,2,2> D = {0.5, 1, 1, 1};
    std::cout<<"C + D = {"<<std::endl;
    std::cout << C + D;
    std::cout<<"}"<<std::endl;
    return 0;
}
