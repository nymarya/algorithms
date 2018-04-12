#include "reader.h"

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
		for ( auto i = 0u ; i < order ; i++ )
   			matrix[i].resize(order+1);


		for (auto i=0u; i < order; i++){
			getline(file, line);
        	std::stringstream stream(line);  

			for(auto j =0u; j <order +1;j++){
				float number = 0.0;
				stream >> number;
				matrix[i][j] = number;
			} 
		}
    }
    file.close();

    return matrix;
}