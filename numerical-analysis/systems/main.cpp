#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>   // std::max_element

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

std::vector<double> solve(std::vector<std::vector<double>> matrix){
	//guarda a coluna em que o pivo de cada linha está
	std::vector<int> pivots(matrix[0].size()-1, -1);
	//matriz escalonada
	std::vector<std::vector<double>> echelon_form(matrix);
	//guarda a coluna em que o pivo de cada linha está
	std::vector<double> solutions(matrix[0].size()-1, 0);

	for (int c=0; c < matrix[0].size()-2; c++){
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
		std::cout << "p: " << pivot;
		std::cout << "linha: " << l<< std::endl;

		//calcula matriz escalonada
		for(int i=0; i < matrix.size(); i++){
			//se a linha não for a do pivo
			if(pivots[i] == -1){
				//calcula multiplicador
				double m = echelon_form[i][c] / pivot;
				std::cout << "m: " << m ;;
				std::cout << "  linha: " << i <<std::endl;

				for (int j = 0; j < matrix[i].size(); j++){
					echelon_form[i][j] = echelon_form[i][j] - echelon_form[l][j]*m;
				}
			}
			
		}		
	}
	for (auto i=0u; i< matrix.size(); i++) {
		for(auto j = 0u; j< 4; j++){
			solutions[i] = echelon_form[i][ matrix[i].size()-1 ];
		}

	}

	//coluna q contem o pivot
	int column = solutions.size()-1;
	for(int i=0; i< matrix[0].size()-1; i++){
		//calcula vetor solução
		int l = -1;
		for (int x = 0; x< pivots.size(); x++){
			if( pivots[x] == column || pivots[x] == -1){
				l = x;
			} 
		}

		std::cout << "pivot da coluna " <<column << " eh da linha " << l <<std::endl;
		double sum = 0.0;
		for(int j = column; j < matrix[0].size()-1; j++){
			std::cout << "c:" << j <<std::endl;
			std::cout << "s: " << echelon_form[l][j] <<std::endl;
			sum += echelon_form[l][j] * solutions[j];
		} 
		
		solutions[column] = (echelon_form[l][matrix[0].size()-1] - sum)/echelon_form[l][column];

		column--;
	}

	
	
	return solutions;
}


int main(){

	size_t order = 0;
	auto m = read("data/m1.in", order);

	for (auto i=0u; i< order; i++) {
		for(auto j = 0u; j< order+1; j++){
			std::cout << m[i][j] << " ";
		}

		std::cout << std::endl;
	}

	auto s = solve(m);
	std::cout << "AAAA\n";
	for(auto j = 0u; j< order; j++){
		std::cout << s[j] << " ";
	}

	std::cout << std::endl;
	

	return EXIT_SUCCESS;

}