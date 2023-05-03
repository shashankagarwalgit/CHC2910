#include <iostream>
#include<math.h>

using namespace std;

double lagrange(double x[], double y[], int n, double xVal) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xVal - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() 
{   
    cout<<"Lagrange Interpolation\n";
    double T[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    double mu[] = {1.79, 1.308, 1.005, 0.801, 0.656, 0.549, 0.469, 0.406, 0.357, 0.317, 0.28};
    int n = sizeof(T) / sizeof(T[0]);

    cout << "Enter five temperatures between 0 and 100 C: ";
    double xVal[5];
    for (int i = 0; i < 5; i++) {
        cin >> xVal[i];
    }

    cout << "Temperature (C)\tViscosity (cP)" << endl;
    for (int i = 0; i < 5; i++) {
        double viscosity = lagrange(T, mu, n, xVal[i]);
        cout << xVal[i] << "\t\t\t" << viscosity << endl;
    }

    return 0;
}