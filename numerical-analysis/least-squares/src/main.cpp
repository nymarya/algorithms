#include <iostream>
#include "reader.h"
#include "least-squares.h"
#include "fourier.h"

// x^2 + 3x - 4
double f(double x){
    return x*x + 3 * x - 4;
}

//x 4 − 3x 3 + 2x 2 − tan x(x − 2)
double g(double x){
    return 2*x*x - 9;
}

double h(double x){
    return 75.455098/2 + (-57.745047)* std::cos(1*x)+ (-22.610281)* std::sin(1*x)+ (41.286397)* std::cos(2*x)+ (20.582639)* std::sin(2*x)+ (-32.207393)* std::cos(3*x);
}

int main(){

    std::size_t order = 1000;
    auto m = read("data/pesos.txt", order);
    
    // QUESTAO 2
    std::cout << " QUESTAO 2 \n";
    std::cout << "PESOS\n";

    auto pesos = minimos(m, 2);
    std::cout << "a_0 = " <<pesos[0] << ", a_1 = " <<pesos[1] <<std::endl;

    std::cout << "plot \"data/pesos.txt\", " <<  pesos[0]<<"+ " <<pesos[1] << "*x\n";
    //f(x) = -60.2277 + x* 70.426

    // QUESTAO 3
    std::cout << " QUESTAO 3 \n";
    std::cout << "BARCO\n";

    order = 40u;
    auto barco = read("data/barco.txt", order);


    //f(x) = -60.2277 + x* 70.426

    auto barcos = minimos(barco, 3);

    std::cout << "a_0 = " <<barcos[0] << ", a_1 = " <<barcos[1] << ", a_2 = " << barcos[2] <<std::endl;

    std::cout << "plot \"data/barco.txt\", " << barcos[0] << "+ " << barcos[1] << "*x + " << barcos[2] << "*x*x";

    /// QUESTAO 6
    std::cout << " QUESTAO 7 \n";
    discrete_approximation(f, -pi, pi, 3.0);
    discrete_approximation(f, -pi, pi, 5.0);
    discrete_approximation(f, -pi, pi, 8.0);
    discrete_approximation(f, -pi, pi, 20.0);
    

    std::cout << "\n\nDONE\n";

    return EXIT_SUCCESS; 
}
