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
        std::cout << ",x>=" << points[i-1] << " && x<=" <<points[i] << "?" << "g"<< i << "(x):0 with filledcurve y1=0 title 'g"<<i<<"(x)'";
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
        std::cout << ",x>=" << points[i-2] << " && x<=" <<points[i] << "?" << "h"<< i << "(x):0 with filledcurve y1=0 title 'h" << i/2 << "(x)'";
    }

    std::cout << "\n\nh2(x) = 1.219*x**2 + 12.654*x + 28.0002;";
    std::cout << "h4(x) = -1.41739*x**2 - 5.71039*x - 3.92112;";
    std::cout << "h6(x) = 0.306271*x**2 - 0.484951*x + 0;";
    std::cout << "h8(x) = 0.306271*x**2 + 0.484951*x - 2.22045*10**(-16);";
    std::cout << "h10(x) = -1.41739*x**2 + 5.71039*x - 3.92112;";
    std::cout << "h12(x) = 1.219*x**2 - 12.654*x + 28.0002\n\n";

    std::cout << approx << std::endl;

    approx = 0.0;
    //Composição para regra 3/8 de simpson
    for( int i = 3; i < 13; i+=3){
        approx += three_eights_rule(f, points[i-3], points[i-2], points[i-1], points[i]);
        std::cout << ",x>=" << points[i-3] << " && x<=" <<points[i] << "?" << "i"<< i << "(x):0 with filledcurve y1=0 title 'i" << i/3 << "(x)'";

    }

    std::cout << "\n\ni3(x) = -0.716505*x**3 - 7.73731*x**2 - 24.1664*x - 21.757;";
    std::cout << "i6(x) = 0.469555*x**3 + 1.48016*x**2 + 0.167209*x + 0;";
    std::cout << "i9(x) = -0.469555*x**3 + 1.48016*x**2 - 0.167209*x + 0;";
    std::cout << "i12(x) = 0.716505*x**3 - 7.73731*x**2 + 24.1664*x - 21.757;\n\n";

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