#ifndef _METHODS_H_
#define _METHODS_H_

#include <iostream>
#include <vector> 
#include <cmath>

/**
 * Método que divide um intervalo em n pontos.
 * @param a Início do intervalo.
 * @param b Final do intervalo.
 * @param n Número de pontos.
 * @return Vetor com n pontos equidistantes.
 */
std::vector<double> divide(double a, double b, int n);

/**
 * Calcula a aproximação da integral de uma função com 2 pontos usando a regra 
 * do trapezio.
 * @param func Função que será integrada.
 * @param x0   Início do intervalo de integração.
 * @param x1   Final do intervalo de integração.
 */
double trapezoidal_rule(double(*func)(double ),  double x0, double x1);

/**
 * Calcula a aproximação da integral de uma função com 3 pontos usando a regra 
 * de 1/3 de Simpson.
 * @param func Função que será integrada.
 * @param x0   Início do intervalo de integração.
 * @param x1   Segundo ponto.
 * @param x2   Terceiro ponto.
 */
double simpson_rule(double(*func)(double ),  double x0, double x1, double x2);

/**
 * Calcula a aproximação da integral de uma função com 4 pontos usando a regra 
 * de 3/8 de Simpson.
 * @param func Função que será integrada.
 * @param x0   Início do intervalo de integração.
 * @param x1   Segundo ponto.
 * @param x2   Terceiro ponto.
 * @param x3   Final do intervalo de integração.
 */
double three_eights_rule(double(*func)(double ),  double x0, double x1, double x2, double x3);

#endif