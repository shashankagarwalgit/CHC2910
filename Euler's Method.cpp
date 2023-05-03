#include <iostream>
#include <math.h>

using namespace std;

const double k1 = 3;
const double k2 = 1;

double dCAdt(double CA) {
    return -k1 * CA;
}

double dCBdt(double CA, double CB) {
    return k1 * CA - k2 * CB;
}

double dCCdt(double CB) {
    return k2 * CB;
}
void euler(double CA0, double CB0, double CC0, double t0, double tf, int n) {
    double h = (tf - t0) / n;
    double t = t0;
    double CA = CA0;
    double CB = CB0;
    double CC = CC0;

    cout << "\nEuler Method:" << endl;
    cout << "t\tCA\tCB\tCC" << endl;
    cout << t << "\t" << CA << "\t" << CB << "\t" << CC << endl;

    for (int i = 1; i <= n; i++) {
        CA += h * dCAdt(CA);
        CB += h * dCBdt(CA, CB);
        CC += h * dCCdt(CB);

        t += h;

        cout << t << "\t" << CA << "\t" << CB << "\t" << CC << endl;
    }
}

int main() 
{

    double Cai, Cbi, Cci, timei, timef;
    cout<<"Enter initial Value of Ca: ";
    cin>>Cai;
    cout<<"Enter initial Value of Cb: ";
    cin>>Cbi;
    cout<<"Enter initial Value of Cc: ";
    cin>>Cci;

    cout<<"Enter intial and final time: ";
    cin>>timei>>timef;

    euler(Cai, Cbi, Cci, timei, timef, 1000);

    return 0;
}
