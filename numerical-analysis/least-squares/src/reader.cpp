#include "reader.h"

std::vector<std::vector<double> > read(std::string filename, size_t &order){

	std::vector<std::vector<double> > matrix;

	//<! abre o arquivo contendo a a matriz
	std::fstream file;
    file.open(filename);

    if(file.is_open()){

        std::string line;

		matrix.resize(order);
		for ( auto i = 0u ; i < order ; i++ )
   			matrix[i].resize(2);


		for (auto i=0u; i < order; i++){
			getline(file, line);
        	std::stringstream stream(line);  

			for(auto j =0u; j < 2;j++){
				float number = 0.0;
				stream >> number;
				matrix[i][j] = number;
			} 
		}
    }
    file.close();

    return matrix;
}