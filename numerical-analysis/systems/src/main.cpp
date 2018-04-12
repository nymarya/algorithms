#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip> 

#include "reader.h"
#include "gauss.h"

int main(){

	size_t order = 0;
	auto m = read("data/m1.in", order);

	auto s = gaussian_elimination(m);
	std::cout << std::fixed;
	std::cout <<  std::setprecision(20);


	std::cout << "Matriz 1\n Sem refinamento  = [";
	for(auto j = 0u; j< order; j++){
		std::cout << s[j] << " ";
	}
	std::cout <<"]\n";

	std::cout << "Matriz 1\n Com refinamento  = [";
	s = solve(m);
	for(auto j = 0u; j< order; j++){
		std::cout << s[j] << " ";
	}
	std::cout <<"]\n";
	
	//Matriz 5x5
	m = read("data/m2.in", order);
	s = gaussian_elimination(m);
	std::cout << "Matriz 2\n Sem refinamento  = [";
	for(auto j = 0u; j< order; j++){
		std::cout << s[j] << " ";
	}
	std::cout <<"]\n";

	std::cout << "Matriz 2\n Com refinamento  = [";
	s = solve(m);
	for(auto j = 0u; j< order; j++){
		std::cout << s[j] << " ";
	}
	std::cout <<"]\n";

	//Matriz 80x80
	m = read("data/m3.in", order);
	s = gaussian_elimination(m);
	std::cout << "Matriz 3\n Sem refinamento  = [";
	for(auto j = 0u; j< order; j++){
		std::cout << s[j] << " ";
	}
	std::cout <<"]\n";

	std::cout << "Matriz 3\n Com refinamento  = [";
	s = solve(m);
	for(auto j = 0u; j< order; j++){
		std::cout << s[j] << " ";
	}
	std::cout <<"]\n";

	

	
	

	return EXIT_SUCCESS;

}