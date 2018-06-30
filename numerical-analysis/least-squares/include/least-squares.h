#ifndef _LEAST_SQUARES_H
#define _LEAST_SQUARES_H

#include "gauss.h"

/**
 * Função que aproxima um conjunto de pontos com polinômio.
 * @param points Pontos a serem aproximados
 * @param order Grau do polinômio utilizado para aproximar os pontos.
 */
std::vector<double>  minimos( std::vector<std::vector<double>> points, int order);

#endif