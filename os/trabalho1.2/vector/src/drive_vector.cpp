#include "../include/vector.hpp"
#include <chrono>
#include <thread>

int main(){

	ls::Vector<int> v(1);

	int i = 536870912;
	while( i-- > 0 ){
	   v.push_back(3);
	   if( i > 536800000 && i% 100 == 0) {
	       std::this_thread::sleep_for(std::chrono::milliseconds(2));
	   }

	}

	std::this_thread::sleep_for(std::chrono::milliseconds(180000));

	
	std::cout << "\n>>>Saindo..." <<std::endl;
	return 0;
}
