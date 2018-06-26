#include <iostream>
#include "reader.h"
#include "least-squares.h"

int main(){

    std::size_t order = 1000;
    auto m = read("data/pesos.txt", order);

    std::vector< std::vector<double>> matrix = {
        {1000, 0},
        {0, 0}
    };

    std::vector<double> b = { 0, 0};

    for (auto i=0u; i < 1000u; i++){
        matrix[0][1] += m[i][0];
        matrix[1][0] = matrix[0][1];
        matrix[1][1] +=m[i][0] *m[i][0];
       

        b[0] +=m[i][1];
        b[1] +=m[i][0] *m[i][1];
        
    }

    std::cout << "PESOS\n";

    for( auto i=0u; i< 2u; i++){
        for (auto j=0u; j < 2u; j++){
            std::cout << matrix[i][j] << " ";
        }

        std::cout <<" " << b[i] << " \n";
    }

    std::vector< std::vector<double>> teste = {
        {matrix[0][0], matrix[0][1], b[0]},
        {matrix[1][0], matrix[1][1], b[1]}
    };

    auto pesos = minimos(m, 2);

    std::cout << "plot \"data/pesos.txt\", " <<  pesos[0]<<"+ " <<pesos[1] << "*x\n";
    //f(x) = -60.2277 + x* 70.426


    std::cout << "BARCO\n";

    order = 40u;
    auto barco = read("data/barco.txt", order);

    matrix = {
        {40, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    b = { 0, 0, 0};

    for (auto i=0u; i < order; i++){
        matrix[0][1] += barco[i][0];
        matrix[0][2] +=barco[i][0] *barco[i][0];

        matrix[1][0] = matrix[0][1];
        matrix[1][1] = matrix[0][2];
        matrix[1][2] = matrix[0][2] *barco[i][0];

        matrix[2][0] = matrix[0][2];
        matrix[2][1] = matrix[1][2];
        matrix[2][2] = matrix[1][2] *barco[i][0];
       

        b[0] +=barco[i][1];
        b[1] +=barco[i][0] *barco[i][1];
        b[2] +=barco[i][0] *barco[i][1] *barco[i][0];
        
    }

    for( auto i=0u; i< 3u; i++){
        for (auto j=0u; j < 3u; j++){
            std::cout << matrix[i][j] << " ";
        }

        std::cout <<" " << b[i] << " \n";
    }

    std::cout << "\n\n testes minimos()\n\n";  

    //f(x) = -60.2277 + x* 70.426

    auto barcos = minimos(barco, 3);

    std::cout << "plot \"barco.txt\", " << barcos[0] << "+ " << barcos[1] << "*x + " << barcos[2] << "*x*x";

    std::cout << "\n\nDONE\n";

    return EXIT_SUCCESS; 
}
