#include <iostream>
#include <cmath>
using namespace std;

/*
Write a program that enters the coefficients a, b and c of a
quadratic equation a*x2 + b*x + c = 0 and calculates and
prints its real roots. Note that quadratic equations may have 0, 1
or 2 real roots.
*/
int main() {
    double a, b, c;
    cin >> a >> b >> c;

    double determinant = pow(b, 2) - 4*a*c;
    if (determinant == 0)
        cout << "The root is " << (-b)/(2*a) << endl;
    else if (determinant > 0) {
        double root_1 = ((-b) + sqrt(determinant)) / (2*a);
        double root_2 = ((-b) - sqrt(determinant)) / (2*a);
        cout << "Root 1 is " << root_1 << " and Root 2 is " << root_2 << endl;
    } else {
        double firstPart = -b / (2*a);
        double secondPart = sqrt(-determinant) / (2*a);
        double root_1 = firstPart + secondPart;
        double root_2 = firstPart - secondPart;
        cout << "Root 1 is " << root_1 << " and Root 2 is " << root_2 << endl;
    }
    return 0;
}