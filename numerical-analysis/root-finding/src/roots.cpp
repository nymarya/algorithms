#include "methods.h"

//Questao 1
double f (double x){
    //f (x) = x 3 + 4.6x 2 + 1.6x − 7.2
    return ( std::pow(x, 3.0) + 4.6*std::pow(x, 2.0) + 1.6*x - 7.2);
}

//Questao 2
double g( double x){
    // f (x) =x 3 − 1.7x 2 − 12.78x − 10.08
    return (std::pow(x, 3.0) - 1.7*std::pow(x,2.0) -  12.78*x - 10.08);
}

double gPrime(double x){
    //Checa se o limite é determinado
    return (3.0 * std::pow(x, 2.0) - 3.4*x - 12.78);
}

//Questao 3
double s( double t ){
    //s(t) = s0 − (mg/k) t + ((m^2*g) / (k^2))*(1-e^(-kt/m))
    //g = 32.17, s0 = 300, m = 0.25, k = 0.1
    double a = (std::pow(0.25, 2.0)*32.17)/0.01;
    double b = 1.0 - std::pow(std::exp(1.0) , -0.4*t);

    return (300.0 -  80.425*t + a*b);
}

double sPrime( double t) {

   return  (-80.425 + 80.425 * std::pow(std::exp(1.0), (-0.4*t)));
}

//Questao 4
double h( double x ){

    double a = std::sqrt ( 400.0 - std::pow(x, 2.0) );
    double b = std::sqrt ( 900.0 - std::pow(x, 2.0) );

    return ( 1/a + 1/b - 1.0/8.0);
}

double hPrime( double x ){

    double a = std::pow (400.0 - std::pow(x, 2.0), 3/2 );
    double b = std::pow (900.0 - std::pow(x, 2.0), 3/2 );

    return x * ( 1/a + 1/b );
}

int main(  ) {
    
    //questao 1
    std::cout << ">>> Questão 1\n";
    std::cout << ">>> Método da bisseção\n";
    double raiz = bissecao(f, -3.333333, 0.7);
    std::cout << "Raiz: " << raiz << std::endl;
    raiz = bissecao(f, -10.01, -2.8);
    std::cout << "Raiz: " << raiz << std::endl;
    raiz = bissecao(f, -1.293029, 6.89);
    std::cout << "Raiz: " << raiz << std::endl;

    //questao 2
    std::cout << std::fixed;
    std::cout <<  std::setprecision(10);
    std::cout << ">>> Questão 2\n";
    std::cout << ">>> Método de Newton-Raphson\n";
    raiz = newton(g,gPrime, -4.0);
    std::cout << "Raiz: " << raiz << std::endl;
    raiz = newton(g,gPrime, 1.0);
    std::cout << "Raiz: " << raiz << std::endl;
    raiz = newton(g,gPrime, 3.0);
    std::cout << "Raiz: " << raiz << std::endl;

    //questao 3
    std::cout << ">>> Questão 3\n";
    std::cout << ">>> Método de Newton-Raphson\n";
    raiz = newton(s, sPrime, 7.06);
    std::cout << "Raiz: " << raiz << std::endl;

    //questao 4
    std::cout << ">>> Questão 4\n";
    std::cout << ">>> Método de Newton-Raphson\n";
    raiz = newton(h, hPrime, 1.05);
    std::cout << "Raiz: " << raiz << std::endl;

    return EXIT_SUCCESS;
}