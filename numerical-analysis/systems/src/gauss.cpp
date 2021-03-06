#include "gauss.h"

double norm(std::vector<double> x, std::vector<double> y){
	double max= 0.0;
	for( auto i = 0u; i< x.size(); i++ ){
		double diff = std::abs(x[i]-y[i]);
		if(diff > max){
			max = diff;
		}
	}

	return max;
}

std::vector<double> gaussian_elimination(std::vector<std::vector<double>> matrix){
	//guarda a coluna em que o pivo de cada linha está
	std::vector<std::size_t> pivots(matrix[0].size()-1, -1u);
	//matriz escalonada
	std::vector<std::vector<double>> echelon_form(matrix);
	//guarda a coluna em que o pivo de cada linha está
	std::vector<double> solutions(matrix[0].size()-1, 0);

	//coluna que contem as solucoes
	auto columns = matrix[0].size()-1;

	for (auto c=0u; c < columns-1; c++){
		double pivot = 0.0;
		int l = 0;

		//procura pivo
		for(auto i=0u; i < matrix.size(); i++){
			if(std::abs(echelon_form[i][c]) > std::abs(pivot) && pivots[i]== -1u){
				pivot = echelon_form[i][c];
				l = i;
			}
		}
		pivots[l] = c;

		//calcula matriz escalonada
		for(auto i=0u; i < matrix.size(); i++){
			//se a linha não for a do pivo
			if(pivots[i] == -1u){
				//calcula multiplicador
				double m = echelon_form[i][c] / pivot;

				//atualiza valores
				for (auto j = 0u; j < matrix[i].size(); j++){
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
	auto column = matrix.size()-1;
	for(auto i=0u; i< columns; i++){
		//encontra a linha referente ao pivo
		int l = -1;
		for (auto x = 0u; x< pivots.size(); x++){
			if( pivots[x] == column){
				l = x;
				break;
			} else if(pivots[x] == -1u){
				l = x;
			}
		}

		//calcula solução
		double sum = 0.0;
		for(auto j = column+1; j < columns; j++){
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

	//calcula b esperado
	std::vector<double> b(solution.size());
	for (auto i=0u; i< b.size(); i++) {
		b[i] = matrix[i][ matrix[i].size()-1 ];
	}

	//calcula Ax' -> x' sendo o vetor solucao encontrado
	auto ax = mult(matrix, solution);

    int n = 10000;
	while (n-- > 0) {

		//cria a matriz aumentada A|r
		auto ar = matrix;
		for( auto i=0u; i< ar.size(); i++){
			ar[i][ar[0].size()-1] = b[i] - ax[i];
		}

		//resolve Ay = r
		auto y = gaussian_elimination(ar);

		// soma x' + y
		for( auto i = 0u; i< y.size(); i++){
			solution[i] += y[i];
		}

		//calcula novo Ax'
		ax = mult(matrix, solution);

	}
	
	return solution;
}