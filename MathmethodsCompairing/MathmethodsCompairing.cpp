#include <iostream>
#include <cmath>

using namespace std;

double givenFunction(double x) {
    return pow(x, 4) - pow(x, 3) - 4 * pow(x, 2) + x + 6;
}

double simpsonsMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0;

    for (int i = 0; i < n; ++i) {
        double x = a + h * i;
        double y = a + h * (i + 1);

        result += (y - x) / 6 * (givenFunction(x) + 4 * givenFunction((x + y) / 2) + givenFunction(y));
    }
    return result;
}

double trapezoidalMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double result = 0;

    for (int i = 0; i < n; ++i) {
        double x = a + h * i;
        double y = a + h * (i + 1);

        result += (y - x) / 2 * (givenFunction(y) + givenFunction(x));
    }
    return result;
}

int main() {
    double a = 0;
    double b = 1;

    cout << "The real result: " << (double)307 / 60 << endl;

    for (int i = 10; i <= 1000; i *= 10) {
        cout << "i = " << i << "   ";
        cout << "\tSimpson " << simpsonsMethod(a, b, i) << "\t\tTrapez " << trapezoidalMethod(a, b, i) << endl;
    }


    for (int i = 10; i <= 1000; i *= 10) {
        cout << "i = " << i << "   ";
        cout << "\tFault(S): " << fabs(simpsonsMethod(a, b, i) -
            -(double)307 / 60) << "\tFault(T): " << fabs(trapezoidalMethod(a, b, i) - (double)307 / 60) << endl;
    }
    return 0;
}
