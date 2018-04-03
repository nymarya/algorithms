#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>   // std::max_element
#include <cassert>
#include <cmath>

std::vector<std::vector<double> > read(std::string filename, size_t &order){

	std::vector<std::vector<double> > matrix;

	//<! abre o arquivo contendo a a matriz
	std::fstream file;
    file.open(filename);

    if(file.is_open()){

        std::string line;
        getline(file, line);
        std::stringstream stream(line);
        
        //<! Guarda a ordem da matriz
        stream >> order;

		matrix.resize(order);
		for ( int i = 0 ; i < order ; i++ )
   			matrix[i].resize(order+1);


		for (int i=0; i < order; i++){
			getline(file, line);
        	std::stringstream stream(line);  

			for(int j =0; j <order +1;j++){
				float number = 0.0;
				stream >> number;
				matrix[i][j] = number;
			} 
		}
    }
    file.close();

    return matrix;
}

double norm(std::vector<double> x, std::vector<double> y){
	double max= 0.0;
	for( auto i = 0u; i< x.size(); i++ ){
		double diff = std::abs(x[i]-y[i]);
		if(diff > max){
			max = diff;
		}
	}
}

std::vector<double> gaussian_elimination(std::vector<std::vector<double>> matrix){
	//guarda a coluna em que o pivo de cada linha está
	std::vector<int> pivots(matrix[0].size()-1, -1);
	//matriz escalonada
	std::vector<std::vector<double>> echelon_form(matrix);
	//guarda a coluna em que o pivo de cada linha está
	std::vector<double> solutions(matrix[0].size()-1, 0);

	//coluna que contem as solucoes
	int columns = matrix[0].size()-1;

	for (int c=0; c < columns-1; c++){
		double pivot = 0.0;
		int l = 0;

		//procura pivo
		for(int i=0; i < matrix.size(); i++){
			if(std::abs(echelon_form[i][c]) > std::abs(pivot) && pivots[i]== -1){
				pivot = echelon_form[i][c];
				l = i;
			}
		}
		pivots[l] = c;

		//calcula matriz escalonada
		for(int i=0; i < matrix.size(); i++){
			//se a linha não for a do pivo
			if(pivots[i] == -1){
				//calcula multiplicador
				double m = echelon_form[i][c] / pivot;

				//atualiza valores
				for (int j = 0; j < matrix[i].size(); j++){
					echelon_form[i][j] = echelon_form[i][j] - echelon_form[l][j]*m;
				}
			}
			
		}		
	}

	// atualiza vetor de soluções
	for (auto i=0u; i< matrix.size(); i++) {
		solutions[i] = echelon_form[i][ matrix[i].size()-1 ];
	}

	//coluna q contem o pivot
	int column = solutions.size()-1;
	for(int i=0; i< columns; i++){
		//encontra a linha referente ao pivo
		int l = -1;
		for (int x = 0; x< pivots.size(); x++){
			if( pivots[x] == column){
				l = x;
				break;
			} else if(pivots[x] == -1){
				l = x;
			}
		}

		//calcula solução
		double sum = 0.0;
		for(int j = column+1; j < columns; j++){
			sum += echelon_form[l][j] * solutions[j];
		} 
		solutions[column] = (echelon_form[l][columns] - sum)/echelon_form[l][column];

		column--;
	}
	
	return solutions;
}


std::vector<double> mult(std::vector<std::vector<double>> matrix,std::vector<double> vector ){

	std::vector<double> result( matrix[0].size()-1 ); 

	for( auto i=0u; i< matrix.size(); i++){
		auto sum = 0.0;
		for(auto j=0u; j < matrix[i].size()-1 ; j++){
			sum += matrix[i][j] * vector[j];
		}
		result[i] = sum;
	}

	return result;
}

std::vector<double> solve(std::vector<std::vector<double>> matrix ){
	
	//resolve o sistema
	auto solution = gaussian_elimination(matrix);

	
	std::vector<double> b(matrix[0].size());
	for (auto i=0u; i< matrix.size(); i++) {
		b[i] = matrix[i][ matrix[i].size()-1 ];
	}

	auto result = solution;
	do{

		//calcula Ax̄
		auto ax = mult(matrix, result);
		
		//cria a matriz aumentada A|r
		std::vector<std::vector<double>> ar (matrix);
		for( auto i=0u; i< matrix.size(); i++){
			auto rest = b[i] - ax[i];
			ar[i][ar[0].size()-1] = rest;
		}

		//resolve Ay = r
		auto y = gaussian_elimination(ar);

		//soma x̄ + y
		for( auto i = 0u; i< y.size(); i++){
			result[i] = result[i]  + y[i];
		}
	} while( norm(solution, result) > std::pow(10, -20));
	
	return result;
}



int main(){

	size_t order = 0;
	auto m = read("data/m1.in", order);

	auto s = solve(m);
	std::cout << "AAAA\n";
	for(auto j = 0u; j< order; j++){
		std::cout << s[j] << " ";
	}
	std::cout << std::endl;

	auto teste = mult(m, s);
	for (auto i=0u; i< order; i++) {
		assert( teste[i] == m[i][order]);
	}
	
	m = read("data/m2.in", order);
	s = solve(m);
	std::cout << "AAAbA\n";
	for(auto j = 0u; j< order; j++){
		std::cout << s[j] << " ";
	}
	std::cout << std::endl;

	m = read("data/m3.in", order);
	s = solve(m);
	for(auto j = 0u; j< order; j++){
		std::cout << s[j] << " ";
	}
	std::cout << std::endl;

	
	

	return EXIT_SUCCESS;

}