#include "least-squares.h"

std::vector<double>  minimos( std::vector<std::vector<double>> points, int order){

    std::vector<std::vector<double>> matrix ( order );
    std::cout << points.size() << "pontos \n";

    //cria matriz de somatorios sum(x^(i+j))

    //Guarda somatorios de 0 a 2(o-1)+1
    std::vector<double> sums ( 2 * (order-1) + 1);
    for(auto i=0u; i< sums.size(); i++){
        sums[i] = 0;
        // soma os x elevado a i ( m vezes)
        for( auto k=0u; k < points.size(); k++){
            sums[i] += std::pow(points[k][0], i);
            
        }
    }

    //Salva na matriz
    for( auto i=0u; i < order; i++){
        matrix[i].resize(order+1);
        matrix[i].assign(order+1, 0);

        for( auto j=0; j<order; j++){

            matrix[i][j] = sums[i+j];
        }
    }

    //Salva a coluna do somatorio dos Yi
    for(auto i=0; i < order; i++){
        for( auto j=0; j < points.size(); j++){
            matrix[i][order] += points[j][1] * std::pow(points[j][0], i); 
        }
           
    }

    
    for( auto i=0; i< order; i++){
        for (auto j=0; j < order; j++){
            std::cout << matrix[i][j] << " ";
        }

        std::cout <<" " << matrix[i][3] << " \n";
    }

    std::cout << "\n\n a\n\n"; 

    return solve(matrix);


}