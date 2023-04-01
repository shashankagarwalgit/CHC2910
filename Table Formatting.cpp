// Name - Shashank Agarwal
#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdlib.h>

using namespace std;

double molarVol(double Pc, double Tc)
{ float z,b,b0,b1,tr,p,t,pr,v,w;
  float R = 0.0821;
  cin>>w;
  cout<<"Temp(k)\t 10 atm\t20 atm\t30 atm\t40 atm\t50 atm"<<endl;
  
  for(t=223.15;t<=773;t=t+50)
  { cout<<setprecision(5)<<t<<"\t";
    for(p=10;p<=50;p=p+10)
  {tr = t/Tc;
  pr = p/Pc;
  b1 = 0.139-(0.172/pow(tr,4.2));
  b0 = 0.083-(0.422/pow(tr,1.6));
  b  = b0 + w*b1;
  z  = 1 + (b*pr)/tr;
  v  = (z*R*t)/p;
  cout<<setprecision(4)<<v<<"\t";
  }
  cout<<"\n";
  }
  return 0;
}

int main()
{
    double Ct,Cp;
    char name[50];
    cout<<"Enter name of gas: "<<endl;
    cin.getline(name,50);
    cout<<"Enter Critical Temp for "<<name<<", Tc: ";
    cin>>Ct;
    cout<<"Enter Critical Pressure for "<<name<<", Pc: ";
    cin>>Cp;
    cout<<"Enter w for "<<name<<": ";
    molarVol(Cp,Ct);
    return 0;
}
