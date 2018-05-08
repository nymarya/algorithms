#include "methods.h"

double f(double x){
    return x * sin(x);
}

int main(){

    auto points = divide(-5, 5, 13);

    auto approx = 0.0;
    //Composição para regra do trapezio
    std::cout << "Trapézio\n";
    for( int i = 1; i < 13; i++){
        approx += trapezoidal_rule(f, points[i-1], points[i]);
        std::cout << ",x>=" << points[i-1] << " && x<=" <<points[i] << "?" << "g"<< i << "(x):0 with filledcurve y1=0 notitle";
    }
    std::cout << "\n\ng1(x)=1.47979*x + 2.60431;";
    std::cout << "g2(x)=3.51146*x + 11.0696;";
    std::cout << "g3(x)=2.5577*x + 7.89043;";
    std::cout << "g4(x)=0.195397*x + 1.98467;";
    std::cout << "g5(x)=-1.25063*x - 0.425377;";
    std::cout << "g6(x)=1.11022*10**(-16) - 0.740177*x;";
    std::cout << "g7(x)=0.740177*x - 1.11022*10**(-16);";
    std::cout << "g8(x)=1.25063*x - 0.425377;";
    std::cout << "g9(x)=1.98467 - 0.195397*x;";
    std::cout << "g10(x)=7.89043 - 2.5577*x;";
    std::cout << "g11(x)=11.0696 - 3.51146*x;";
    std::cout << "g12(x)=2.60431 - 1.47979*x;\n\n";

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

    return 0;
}