#ifndef _FOURIER_H_
#define _FOURIER_H_

#include <iostream>
#include <cmath>


const long double pi = M_PIl;

/**
 * @param func Função que desejamos aproximar
 * @param a    Início do intervalo
 * @param b    Fim do intervalo
 * @param n    Grau do polinomio
 */
void discrete_approximation( double(*func)(double ), double a, double b, double n);

#endif