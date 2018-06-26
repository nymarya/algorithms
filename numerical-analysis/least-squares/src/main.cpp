#include <iostream>
#include "reader.h"
#include "least-squares.h"

int main(){

    std::size_t order = 1000;
    auto m = read("data/pesos.txt", order);

    std::cout << "PESOS\n";

    auto pesos = minimos(m, 2);

    std::cout << "plot \"data/pesos.txt\", " <<  pesos[0]<<"+ " <<pesos[1] << "*x\n";
    //f(x) = -60.2277 + x* 70.426


    std::cout << "BARCO\n";

    order = 40u;
    auto barco = read("data/barco.txt", order);


    //f(x) = -60.2277 + x* 70.426

    auto barcos = minimos(barco, 3);

    std::cout << "plot \"data/barco.txt\", " << barcos[0] << "+ " << barcos[1] << "*x + " << barcos[2] << "*x*x";

    std::cout << "\n\nDONE\n";

    return EXIT_SUCCESS; 
}
