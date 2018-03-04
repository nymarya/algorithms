#include <iostream>
#include <cmath>

//Questao 1
float f (float x){
    //f (x) = x 3 + 4.6x 2 + 1.6x − 7.2
    return ((float) std::pow(x, (float)3) + (float) 4.6*std::pow(x, (float) 2) + (float) 1.6*x - (float) 7.2);
}

/**
 * Função que implementa o método da bisseção.
 * @param func Função da qual serão extraídas as raízes
 * @param a Início do intervalo inicial.
 * @param b Fim do intervalo inicial.
 */
float bissecao( float(*func)(float ), float a, float b){
    float m = (a+b)/2.0;

    for( int i =0; i < 10000; i++){

        if( func(a)*func(m) < 0){
            b = m;
        } else if( func(a)*func(m) > 0){
            a = m;
        }

        m = (a+b)/2.0;
    }

    return m;
}


//Questao 2
float g( float x){
    // f (x) =x 3 − 1.7x 2 − 12.78x − 10.08
    return ((float) std::pow(x, (float)3) - (float) 1.7*std::pow(x, (float) 2) - (float) 12.78*x - (float) 10.08);
}

float gPrime(float x){
    //Checa se o limite é determinado
    return ((float) 3.0 * std::pow(x, (float)2) - (float) 3.4*x - (float) 12.78);
}

float newton(float(*func)(float ), float(*func1)(float), float x){
    
    //xk+1 = xk - (fun(xk)/func1(xk))
    auto xk = x - (func(x)/func1(x));
    while( std::abs(xk - x)/std::abs(xk) > std::pow(10.0, -3.0) ){
        x = xk;
        xk = x - (func(x)/func1(x));
    }

    return xk;
}

int main(  ) {
    
    //questao 1
    float raiz = bissecao(f, -3.333333, 0.3);
    std::cout << "Raiz: " << raiz << std::endl;
    raiz = bissecao(f, -10.01, -2.8);
    std::cout << "Raiz: " << raiz << std::endl;
    raiz = bissecao(f, -1.293029, 6.89);
    std::cout << "Raiz: " << raiz << std::endl;

    //questao 2
    std::cout << ">>>Método de Newton\n";
    raiz = newton(g,gPrime, -4.0);
    std::cout << "Raiz: " << raiz << std::endl;
    raiz = newton(g,gPrime, 1.0);
    std::cout << "Raiz: " << raiz << std::endl;
    raiz = newton(g,gPrime, 3.0);
    std::cout << "Raiz: " << raiz << std::endl;


    return EXIT_SUCCESS;
}