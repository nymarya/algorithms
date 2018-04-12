#ifndef _METHODS_H_
#define _METHODS_H_

#include <iostream>
#include <cmath>
#include <iomanip> 

/**
 * Função que implementa o método da bisseção.
 * @param func Função da qual serão extraídas as raízes
 * @param a Início do intervalo inicial.
 * @param b Fim do intervalo inicial.
 */
double bissecao( double(*func)(double ), double a, double b);

/**
 * Função que implementa o método de Newton-Raphson.
 * @param func Função da qual serão extraídas as raízes
 * @param funcPrime Derivada da função 'func'.
 * @param x Ponto inicial.
 */
double newton(double(*func)(double ), double(*funcPrime)(double), double x);

#endif