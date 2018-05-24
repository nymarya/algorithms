#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

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

std::vector<double>  minimos( std::vector<std::vector<double>> points, int order){

    std::vector<std::vector<double>> matrix ( order );
    std::cout << points.size() << "\n";

    std::vector<double> sums ( 2 * (order-1) + 1);

    for(auto i=0u; i< sums.size(); i++){
        sums[i] = 0;
        for( auto k=0u; k < points.size(); k++){
            sums[i] += std::pow(points[i][0], i);
            
        }
    }

    for( auto i=0u; i < order; i++){
        matrix[i].resize(order+1);
        matrix[i].assign(order+1, 0);

        for( auto j=0u; j<order; j++){

            matrix[i][j] = sums[i+j];
        }
    }

    for(auto i=0u; i < order; i++){
        for( auto j=0u; j < points.size(); j++){
            matrix[i][order] += points[j][1] * std::pow(points[j][0], i); 
        }
           
    }

    for( auto i=0u; i< 3u; i++){
        for (auto j=0u; j < 3u; j++){
            std::cout << matrix[i][j] << " ";
        }

        std::cout <<" " << matrix[i][3] << " \n";
    }

    std::cout << "\n\n a\n\n"; 

    return solve(matrix);


}

int main(){

    std::size_t order = 1000;
    auto m = read("pesos.txt", order);

    std::vector< std::vector<double>> matrix = {
        {1000, 0},
        {0, 0}
    };

    std::vector<double> b = { 0, 0};

    for (auto i=0u; i < 1000u; i++){
        matrix[0][1] += m[i][0];
        matrix[1][0] = matrix[0][1];
        matrix[1][1] +=m[i][0] *m[i][0];
       

        b[0] +=m[i][1];
        b[1] +=m[i][0] *m[i][1];
        
    }

    for( auto i=0u; i< 2u; i++){
        for (auto j=0u; j < 2u; j++){
            std::cout << matrix[i][j] << " ";
        }

        std::cout <<" " << b[i] << " \n\na\n";
    }

    //f(x) = -60.2277 + x* 70.426

    order = 40u;
    auto barco = read("barco.txt", order);

    matrix = {
        {40, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    b = { 0, 0, 0};

    for (auto i=0u; i < order; i++){
        matrix[0][1] += barco[i][0];
        matrix[0][2] +=barco[i][0] *barco[i][0];

        matrix[1][0] = matrix[0][1];
        matrix[1][1] = matrix[0][2];
        matrix[1][2] = matrix[0][2] *barco[i][0];

        matrix[2][0] = matrix[0][2];
        matrix[2][1] = matrix[1][2];
        matrix[2][2] = matrix[1][2] *barco[i][0];
       

        b[0] +=barco[i][1];
        b[1] +=barco[i][0] *barco[i][1];
        b[2] +=barco[i][0] *barco[i][1] *barco[i][0];
        
    }

    for( auto i=0u; i< 3u; i++){
        for (auto j=0u; j < 3u; j++){
            std::cout << matrix[i][j] << " ";
        }

        std::cout <<" " << b[i] << " \n";
    }

    std::cout << "\n\n a\n\n";  

    //f(x) = -60.2277 + x* 70.426

    auto a = minimos(barco, 3);

    for ( auto i : a){
        std::cout << "i: " << i << " ";
    }
    std::cout << "\n\n a\n\n"; 


}
