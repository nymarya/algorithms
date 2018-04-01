#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>   // std::max_element

std::vector<std::vector<float> > read(std::string filename, size_t &order){

	std::vector<std::vector<float> > matrix;

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
    std::vector<double> pivos(matrix[0].size(), -1);
	for (int c=0; c < matrix[0].size(); c++){
		double pivo = 0.0;
		double l = 0.0;

		//procura pivo
		for(int i=0; i < matrix.size(); i++){
			if(std::abs(matrix[i][c]) > std::abs(pivo) ){
				pivo = matrix[i][c];
				l = i;
			}
		}
		pivos[l] = c;

		//calcula matriz 
		std::vector<std::vector<double>> transformada(matrix);
		for(int i=0; i < matrix.size(); i++){
			//se a linha não for a do pivo
			if(pivos[i] == -1){
				//calcula multiplicador
			    double m = matrix[i][c] / pivo;

				for (int j = 0; j < matrix[i].size(); j++){
					transformada[i][j] = matrix[i][j] - matrix[l][i]*m;
				}
			}
			
		}
	}
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

	return EXIT_SUCCESS;

}