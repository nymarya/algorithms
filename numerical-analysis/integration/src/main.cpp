#include "methods.h"

double f(double x){
    return x * sin(x);
}

int main(){

    auto points = divide(-5, 5, 13);

    auto approx = 0.0;
    //Composição para regra do trapezio
    for( int i = 1; i < 13; i++){
        approx += trapezoidal_rule(f, points[i-1], points[i]);
    }

    std::cout << approx << std::endl;

    approx = 0.0;
    //Composição para regra 1/3 de simpson
    for( int i = 2; i < 13; i+=2){
        approx += simpson_rule(f, points[i-2], points[i-1], points[i]);
    }

    std::cout << approx << std::endl;

    approx = 0.0;
    //Composição para regra 3/8 de simpson
    for( int i = 3; i < 13; i+=3){
        approx += three_eights_rule(f, points[i-3], points[i-2], points[i-1], points[i]);
    }

    std::cout << approx << std::endl;

    std::cout << "Para 25 pontos\n";
    points = divide(-5, 5, 25);

    approx = 0.0;
    //Composição para regra do trapezio
    for( int i = 1; i < 25; i++){
        approx += trapezoidal_rule(f, points[i-1], points[i]);
    }

    std::cout << approx << std::endl;

    approx = 0.0;
    //Composição para regra 1/3 de simpson
    for( int i = 2; i < 25; i+=2){
        approx += simpson_rule(f, points[i-2], points[i-1], points[i]);
    }

    std::cout << approx << std::endl;

    approx = 0.0;
    //Composição para regra 3/8 de simpson
    for( int i = 3; i < 25; i+=3){
        approx += three_eights_rule(f, points[i-3], points[i-2], points[i-1], points[i]);
    }

    std::cout << approx << std::endl;

    std::cout << "Para 37 pontos\n";
    points = divide(-5, 5, 37);

    approx = 0.0;
    //Composição para regra do trapezio
    for( int i = 1; i < 37; i++){
        approx += trapezoidal_rule(f, points[i-1], points[i]);
    }

    std::cout << approx << std::endl;

    approx = 0.0;
    //Composição para regra 1/3 de simpson
    for( int i = 2; i < 37; i+=2){
        approx += simpson_rule(f, points[i-2], points[i-1], points[i]);
    }

    std::cout << approx << std::endl;

    approx = 0.0;
    //Composição para regra 3/8 de simpson
    for( int i = 3; i < 37; i+=3){
        approx += three_eights_rule(f, points[i-3], points[i-2], points[i-1], points[i]);
    }

    std::cout << approx << std::endl;


    std::cout << "Para 49 pontos\n";
    points = divide(-5, 5, 49);

    approx = 0.0;
    //Composição para regra do trapezio
    for( int i = 1; i < 49; i++){
        approx += trapezoidal_rule(f, points[i-1], points[i]);
    }

    std::cout << approx << std::endl;

    approx = 0.0;
    //Composição para regra 1/3 de simpson
    for( int i = 2; i < 49; i+=2){
        approx += simpson_rule(f, points[i-2], points[i-1], points[i]);
    }

    std::cout << approx << std::endl;

    approx = 0.0;
    //Composição para regra 3/8 de simpson
    for( int i = 3; i < 49; i+=3){
        approx += three_eights_rule(f, points[i-3], points[i-2], points[i-1], points[i]);
    }

    std::cout << approx << std::endl;


    return 0;
}