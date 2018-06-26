#include <iostream>
#include <cmath>

const double pi = std::acos(-1);

// x^2 + 3x - 4
double f(double x){
    return x*x + 3 * x - 4;
}

/**
 * @param func Função que desejamos aproximar
 * @param a    Início do intervalo
 * @param b    Fim do intervalo
 * @param m    Subintervalos
 * @param n    Número de pontos que desejamos aproximar
 */
void approximate( double(*func)(double ), double a, double b, double m){
    int n = m;
    for (int k = 0; k < n; k++){

        //calcula a k
        double a = 0.0;
        double b = 0.0;
        for( int i = 0; i < 2*m; i++){
            // ak =1/m sum_0^2*m-1 (yi cos(k xi))
            double x = -pi * i/m * pi;
            double y = func(x);
            a += 1.0/m * y * std::cos(k * x);
            
            b += 1.0/m * y * std::sin(k * x);
        }
        std::cout << "a" << k << ": " << a << std::endl;
        std::cout << "b" << k << ": " << b << std::endl;
    }
}

int main(){

    approximate(f, -pi, pi, 8.0);

}