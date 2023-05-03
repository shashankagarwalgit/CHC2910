#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float x1[5], x2[5], fx1[5], fx2[5], x[5], fx[5];
    int i;
    float T[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    float mu[] = {1.792, 1.308, 1.005, 0.801, 0.656, 0.549, 0.469, 0.406, 0.357, 0.317, 0.284};
    cout << "Linear Interpolation \n";

    for (int j = 0; j < 5; j++)
    {
        cout << "Enter the value of Temperature " << j + 1 << ": ";
        cin >> x[j];
        cout << "Enter x1 and x2: ";
        cin >> x1[j] >> x2[j];
        cout << "Enter Fx1 and Fx2: ";
        cin >> fx1[j] >> fx2[j];
        fx[j] = fx1[j] + (x[j] - x1[j]) * (fx2[j] - fx1[j]) / (x2[j] - x1[j]);
        cout << "\n";
    }
    for (i = 0; i < 11; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (x[k] == T[i])
            {
                fx[k] = mu[i];
            }
        }
    }

    cout << "Viscosity(cP)\t temperature(C)\n ";
    for (int j = 0; j < 5; j++)
    {
        cout << fx[j] << " \t\t " << x[j] << "\n";
    }

    return 0;
}