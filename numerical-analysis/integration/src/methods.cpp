#include "methods.h"

/**
 * Método que divide um intervalo em n pontos.
 * @param a Início do intervalo.
 * @param b Final do intervalo.
 * @param n Número de pontos.
 * @return Vetor com n pontos equidistantes.
 */
std::vector<double> divide(double a, double b, int n){
    std::vector<double> points(n);

    double h = std::abs(b - a) /(n-1);
    for(int i =0; i <n; i++){
        points[i] = a;
        std::cout << points[i] << " \n";
        a += h;
        
    }

    return points;
}

/**
 * Calcula a aproximação da integral de uma função com 2 pontos usando a regra 
 * do trapezio.
 * @param func Função que será integrada.
 * @param x0   Início do intervalo de integração.
 * @param x1   Final do intervalo de integração.
 */
double trapezoidal_rule(double(*func)(double ),  double x0, double x1){
    double h = std::abs(x1 - x0);

    return (h/2 * func(x0) + func(x1));
}

/**
 * Calcula a aproximação da integral de uma função com 3 pontos usando a regra 
 * de 1/3 de Simpson.
 * @param func Função que será integrada.
 * @param x0   Início do intervalo de integração.
 * @param x1   Segundo ponto.
 * @param x2   Terceiro ponto.
 */
double simpson_rule(double(*func)(double ),  double x0, double x1, double x2){
    double h = std::abs(x1 - x0);

    return (h/3 * func(x0) + 4*func(x1) + func(x2));
}

/**
 * Calcula a aproximação da integral de uma função com 4 pontos usando a regra 
 * de 3/8 de Simpson.
 * @param func Função que será integrada.
 * @param x0   Início do intervalo de integração.
 * @param x1   Segundo ponto.
 * @param x2   Terceiro ponto.
 * @param x3   Final do intervalo de integração.
 */
double three_eights_rule(double(*func)(double ),  double x0, double x1, double x2, double x3){
    double h = std::abs(x1 - x0);

    return (3 * h/8 * func(x0) + 3 * func(x1) + 3 * func(x2) + func(x3));
}
