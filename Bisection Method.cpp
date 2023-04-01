//Program to find friction factor by Bisection Method
//Name- Shashank Agarwal
//Faculty Number- 21CHB242
//Assign -02
#include<iostream>
#include<conio.h>
#include<math.h>
#include<stdio.h>

using namespace std;

#define Fn(f) (4.0*log10(Re*pow(f,0.5))-0.4-pow(f,-0.5))
#define e 0.00001

int main()
{
int i=1;
double a,b,c,f0,f1,f2,Re;
cout<<"Enter Reynold's No. b/w 5000-100000: "<<endl;
cin>>Re;
cout<<"Enter the two initial guess: "<<endl;
cin>>a>>b;
f1 = Fn(a);
f2 = Fn(b);


if(f1*f2>0)
{ cout<<"Roots can't be find in this interval";
return 0;
}
else
{

while(fabs(a-b)>=e)
{ c = (a+b)/2.0;
 f1 = Fn(a);
 f2 = Fn(b);
 f0 =Fn(c);
  if(f0 == 0.0)
    {
        cout<<"Root of equation is: "<<c;
        return 0;
    }
  else if(f1*f0>0)
  { a=c;
  }
  else
  {b =c;
  }
 i++;
}
cout<<"Root is: "<<c<<endl;
cout<<"After iteration: "<<i<<endl;
cout<<"Function value at root is: "<<Fn(c);
getch();
return 0;
}
}
