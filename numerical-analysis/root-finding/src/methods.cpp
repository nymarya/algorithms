#include "methods.h"

/**
 * Função que implementa o método da bisseção.
 * @param func Função da qual serão extraídas as raízes
 * @param a Início do intervalo inicial.
 * @param b Fim do intervalo inicial.
 */
 double bissecao( double(*func)(double ), double a, double b){
    double m = (a+b)/2.0;

    while( std::abs( func(m)) > std::pow(10, -5) ){

        if( func(a)*func(m) < 0){
            b = m;
        } else if( func(a)*func(m) > 0){
            a = m;
        }

        m = (a+b)/2.0;
    }

    return m;
}

/**
 * Função que implementa o método de Newton-Raphson.
 * @param func Função da qual serão extraídas as raízes
 * @param funcPrime Derivada da função 'func'.
 * @param x Ponto inicial.
 */
double newton(double(*func)(double ), double(*funcPrime)(double), double x){
    
    //xk+1 = xk - (fun(xk)/func1(xk))
    auto xk = x - (func(x)/funcPrime(x));
    while( std::abs(xk - x) > std::pow(10.0, -5.0) ){
        x = xk;
        xk = x - (func(x)/funcPrime(x));
    }

    double erro = std::abs(xk - x);
    std::cout << "Erro = "<< erro << std::endl;

    return xk;
}