#include <iostream>
#include "methods.h"
#include <cassert>

double f(double x){
    return (1 + 881*x/210 - 849*std::pow(x,2)/420 + 89*std::pow(x,3)/420);
}

double fPrime(double x){
    return(1.0/420 * (1762 - 1698*x + 267*std::pow(x,2)));
}

int main(){

    std::vector<std::vector<double>> points = {
        {0,1},
        {2, 3},
        {4, -1},
        {7,4}
    };

    // Testa algoritmo para calcular diferença dividida 
    auto r = divided_difference(points);

    assert(r[0] == 1);
    assert(r[4] == 1);
    assert(r[7] == -3.0/4);
    assert(r[9] == 89.0/420);


    // Questão 2
    double y = newton(points, 4);
    assert( y == -1);
    y = newton(points, 28);
    assert( y == 15927.0/5);
    y = newton(points, 9);
    assert( y == 29.5);

    std::cout << std::left << std::setw(12)<< "#"<< std::setw(13)<< "Y\n";     
    for(auto i(-10); i<=10; ++i){        
        std::cout << std::left << std::setw(12) << newton(points, i)  << std::fixed;        
        std::cout << "\n";     
    }


    std::vector<std::vector<double>> points2 = {
        {3,1},
        {5, 3},
        {-1, 6},
        {9,7},
    };

    y = newton(points2, 3);
    assert( y == 1);
    y = newton(points2, 10);
    assert( y == 107.0/16);

    std::vector<std::vector<double>> points3 = {
        {1,1},
        {2, 2},
        {3, 3},
        {4,4},
        {5, 5}
    };

    y = newton(points3, 3);
    assert( y == 3);
    y = newton(points3, 10);
    assert( y == 10);

    std::vector<std::vector<double>> points4 = {
        {1,10},
        {2, -2},
        {3, 13},
        {4, -4},
        {5, 15}
    };

    y = newton(points4, 3);
    assert( y == 13);
    y = newton(points4, 45);
    assert( y == 16484005);


}