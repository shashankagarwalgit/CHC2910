#include <iostream>
#include <math.h>

using namespace std;

const int k1 = 3;
const int k2 = 1;

double dCAdt(double CA) {
    return -k1 * CA;
}

double dCBdt(double CA, double CB) {
    return k1 * CA - k2 * CB;
}

double dCCdt(double CB) {
    return k2 * CB;
}

void rungeKutta(double CA0, double CB0, double CC0, double t0, double tf, int n) {
    double h = (tf - t0) / n;
    double t = t0;
    double CA = CA0;
    double CB = CB0;
    double CC = CC0;

    cout << "Runge-Kutta Method:" << endl;
    cout << "t\tCA\tCB\tCC" << endl;
    cout << t << "\t" << CA << "\t" << CB << "\t" << CC << endl;

    for (int i = 1; i <= n; i++) {
        double k1CA = h * dCAdt(CA);
        double k1CB = h * dCBdt(CA, CB);
        double k1CC = h * dCCdt(CB);

        double k2CA = h * dCAdt(CA + k1CA / 2);
        double k2CB = h * dCBdt(CA + k1CA / 2, CB + k1CB / 2);
        double k2CC = h * dCCdt(CB + k1CB / 2);

        double k3CA = h * dCAdt(CA + k2CA / 2);
        double k3CB = h * dCBdt(CA + k2CA / 2, CB + k2CB / 2);
        double k3CC = h * dCCdt(CB + k2CB / 2);

        double k4CA = h * dCAdt(CA + k3CA);
        double k4CB = h * dCBdt(CA + k3CA, CB + k3CB);
        double k4CC = h * dCCdt(CB + k3CB);

        CA += (k1CA + 2 * (k2CA + k3CA) + k4CA) / 6;
        CB += (k1CB + 2 * (k2CB + k3CB) + k4CB) / 6;
        CC += (k1CC + 2 * (k2CC + k3CC) + k4CC) / 6;

        t += h;

        cout << t << "\t" << CA << "\t" << CB << "\t" << CC << endl;
    }
}

int main()
{   cout<<"Range Kutta method\n";

    double Cai, Cbi, Cci, timei, timef;
    cout<<"Enter initial Value of Ca: ";
    cin>>Cai;
    cout<<"Enter initial Value of Cb: ";
    cin>>Cbi;
    cout<<"Enter initial Value of Cc: ";
    cin>>Cci;

    cout<<"Enter intial and final time: ";
    cin>>timei>>timef;

    rungeKutta(Cai, Cbi, Cci, timei, timef, 40);
    return 0;
}
