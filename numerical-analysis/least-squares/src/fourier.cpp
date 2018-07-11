#include "fourier.h"

/**
 * @param func Função que desejamos aproximar
 * @param a    Início do intervalo
 * @param b    Fim do intervalo
 * @param n    Grau do polinomio
 */
void discrete_approximation( double(*func)(double ), double a, double b, double n){
    double m = 2* n - 1;
    std::cout << "n: " << n << "\n";
    std::string s = "";
    for (int k = 0; k <= n; k++){

        //calcula a k
        double a = 0.0;
        double b = 0.0;
        for( int i = 0; i < 2*m-1; i++){
            double x = -pi + i/m * pi;
            double y = func(x);

            // a_k com k de 0 a n
            // ak =1/m sum_0^2*m-1 (yi cos(k xi))
            a += 1.0/m * y * std::cos(k * x);

            // b_k com k de 1 a n-1
            // bk =1/m sum_0^2*m-1 (yi sin(k xi))
            if( k > 0 && k < n){
                b += 1.0/m * y * std::sin(k * x);
            }
            
        }
        std::cout << "a" << k << ": " << a << std::endl;

        // b_k com k de 1 a n-1
        if( k > 0 && k < n){
            std::cout << "b" << k << ": " << b << std::endl;
            s += "+ (" + std::to_string(a) + ")* cos(" + std::to_string(k) + "*x)";
            s += "+ (" + std::to_string(b) + ")* sin(" + std::to_string(k) + "*x)";
        }  else if (k == 0){
            s += std::to_string(a)+ "/2 ";
        } else{
            s += "+ (" + std::to_string(a) + ")* cos(" + std::to_string(k) + "*x)";
        } 
    }

    std::cout << s << std::endl;
}