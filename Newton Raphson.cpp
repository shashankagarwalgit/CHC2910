//Program to find friction factor by Newton's Raphson Method
//Name- Shashank Agarwal

#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

#define Fn(Re,f) (4.0*log10(Re*pow(f,0.5))-0.4-pow(f,-0.5))
#define Fdn(Re,f) (2/(Re*pow(f,-1)) + 0.5*pow(f,-1.5))
#define e 0.000001
#define iexit 200000

int main()
{
int i = 0;
double xi,xn,fx,fdx,R;
cout<<"Enter Reynold No. b/w 5000-100000: "<<endl;
cin>>R;
cout<<"Enter the initial guess: "<<endl;
cin>>xi;

i=1;
start:
      fx = Fn(R,xi);
      fdx = Fdn(R,xi);
      xn = xi - fx/fdx;
      if(fabs((xn-xi)/xn)<e)
      { cout<<"Root = "<<xn<<endl;
	cout<<"Function value = "<<Fn(R,xn)<<endl;
	cout<<"Root Find at, Number of iteration: "<<i<<endl;
      }
      else
      { xi = xn;
      i++;
       if(i<iexit)
       { goto start;
       }
       else {
       cout<<"Solution does not converge ";
       cout<<"in iterations: "<<iexit;
       }
      }

return 0;
}
