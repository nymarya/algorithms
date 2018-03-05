#include <iostream>
#include <cmath>
#include <cassert>

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

    while( std::abs( 0.0 - func(m)) > std::pow(10, -5) ){

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
    return ((float) std::pow(x, (float)3.0) - (float) 1.7*std::pow(x, (float) 2.0) - (float) 12.78*x - (float) 10.08);
}

float gPrime(float x){
    //Checa se o limite é determinado
    return ((float) 3.0 * std::pow(x, (float)2) - (float) 3.4*x - (float) 12.78);
}

float newton(float(*func)(float ), float(*funcPrime)(float), float x){
    
    //xk+1 = xk - (fun(xk)/func1(xk))
    auto xk = x - (func(x)/funcPrime(x));
    while( std::abs(func(xk) - func(x)) > std::pow(10.0, -5.0) ){
        x = xk;
        xk = x - (func(x)/funcPrime(x));
    }

    return xk;
}

//Questao 3
float s( float t ){
    //s(t) = s0 − (mg/k) t + ((m^2*g) / (k^2))*(1-e^(-kt/m))
    //g = 32.17, s0 = 300, m = 0.25, k = 0.1
    float a = (float) (std::pow(0.25, 2.0)*32.17)/0.01;
    float b = 1.0 - std::pow( (float) std::exp(1.0) , -0.4*t);

    return (float)300.0 - (float) 80.425*t + (float) a*b;
}

float sPrime( float t) {

   return  (-80.425 + 80.425 * std::pow(std::exp(1.0), (-0.4*t)));
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

    raiz = newton(s, sPrime, 7.06);
    std::cout << raiz<< std::endl;
    std::cout << s(raiz) <<std::endl;
    assert( std::abs( 0.0 - s(raiz)) < std::pow(10, -5) );

    raiz = bissecao(s, 5.05, 7.06);
    std::cout << raiz<< std::endl;
    assert( std::abs( 0.0 - s(raiz)) < std::pow(10, -5) );
    std::cout << std::pow((float) 10.0, (float) -5.0) ;

    return EXIT_SUCCESS;
}