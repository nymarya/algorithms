#ifndef _GAUSS_H_
#define _GAUSS_H_

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>   // std::max_element

double norm(std::vector<double> x, std::vector<double> y);
std::vector<double> gaussian_elimination(std::vector<std::vector<double>> matrix);
std::vector<double> mult(std::vector<std::vector<double>> matrix,std::vector<double> vector );
std::vector<double> solve(std::vector<std::vector<double>> matrix );

#endif