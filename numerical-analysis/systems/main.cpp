#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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