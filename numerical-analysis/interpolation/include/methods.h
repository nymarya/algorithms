#ifndef _METHODS_H_
#define _METHODS_H_

#include <iostream>
#include <cmath>
#include <iomanip> 
#include <vector>

/**
 * Função a diferença dividida de Newton.
 * @param points  Vetor que contém pares ordenados que representam os pontos.
 * @return Vetor com as diferenças divididas.
 */
std::vector<double> divided_difference( std::vector< std::vector<double> > points);

/**
 * Avalia a função interpoladora em x. A função é obtida pelo método de Newton.
 * @param points  Vetor que contém pares ordenados que representam os pontos.
 * @param x       Abcissa do ponto que desejamos estimar.
 * @return Valor da função em c.
 */
double newton( std::vector< std::vector<double> > points, double x);

/**
 * Função que implementa o método de Newton-Raphson.
 * @param func Função da qual serão extraídas as raízes
 * @param funcPrime Derivada da função 'func'.
 * @param x Ponto inicial.
 *
double lagrange(double(*func)(double ), double(*funcPrime)(double), double x);
*/
#endif