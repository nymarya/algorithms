#include "least-squares.h"

std::vector<double>  minimos( std::vector<std::vector<double>> points, int order){

    std::vector<std::vector<double>> matrix ( order );
    std::cout << points.size() << "\n";

    std::vector<double> sums ( 2 * (order-1) + 1);

    for(auto i=0u; i< sums.size(); i++){
        sums[i] = 0;
        for( auto k=0u; k < points.size(); k++){
            sums[i] += std::pow(points[i][0], i);
            
        }
    }

    for( auto i=0u; i < order; i++){
        matrix[i].resize(order+1);
        matrix[i].assign(order+1, 0);

        for( auto j=0u; j<order; j++){

            matrix[i][j] = sums[i+j];
        }
    }

    for(auto i=0u; i < order; i++){
        for( auto j=0u; j < points.size(); j++){
            matrix[i][order] += points[j][1] * std::pow(points[j][0], i); 
        }
           
    }

    for( auto i=0u; i< 3u; i++){
        for (auto j=0u; j < 3u; j++){
            std::cout << matrix[i][j] << " ";
        }

        std::cout <<" " << matrix[i][3] << " \n";
    }

    std::cout << "\n\n a\n\n"; 

    return solve(matrix);


}