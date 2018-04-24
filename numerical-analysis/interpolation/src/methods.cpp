#include "methods.h"

/**
 * Função a diferença dividida de Newton.
 * @param points  Vetor que contém pares ordenados que representam os pontos.
 * @return Vetor com as diferenças divididas.
 */
 std::vector<double> divided_difference( std::vector< std::vector<double> > points){

    int n = points.size();

    std::vector<double> result( n*( 1+ n)/2 );

    for(auto i = 0; i < n; i++ ){
        
        result[i] = points[i][1]; 
    }

    auto index = 1;
    for(auto i = 1; i < n; i++ ){

        for(auto j=i; j < n ; j++){
            result[ n + index - i] = (double) (result[index] - result[index - 1]);
            result[ n + index - i ] /= (points[j][0] - points[j-i][0]);

            index++;
        }

        index++;
        
    }

    return result;


 }

 /**
 * Avalia a função interpoladora em x. A função é obtida pelo método de Newton.
 * @param points  Vetor que contém pares ordenados que representam os pontos.
 * @param x       Abcissa do ponto que desejamos estimar.
 * @return Valor da função em c.
 */
double newton( std::vector< std::vector<double> > points, double x){

    auto coeff = divided_difference(points);

    int n = points.size();
    auto index = 0;

    auto m = 1;

    auto result = coeff[index];

    for( int i = 1; i < points.size() ; i++){

        index += n--;

        m *= (x - points[i-1][0]);
        
        result += m * coeff[index];
        
    }

    return result;
}