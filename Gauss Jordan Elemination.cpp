//Program to find Solution of linear equation by Gauss-Jordan Elemination
//Name- Shashank Agarwal

#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

float gaussele(float Ar[5][5], int no)
{ int i,j,k;
float x[5],r;
for(j=1;j<=no;j++)
{
for(i=1;i<=no;i++)
{
if(i!=j)
{
r=Ar[i][j]/Ar[j][j];
for(k=1;k<=(no+1);k++)
{
Ar[i][k]=Ar[i][k]-r*Ar[j][k];
}
}
}
}
for(i=1;i<=no;i++)
{
x[i]=Ar[i][no+1]/Ar[i][i];
cout<<"x"<<i<<"= "<<x[i]<<endl;
}
return 0;
}

int main()
{
int i,j,k,n;
float A[5][5],x[5];

cout<<"Enter the size of the matrix: "<<endl;
cin>>n;
cout<<"Enter the elements of the augmented matrix ["<<n<<"*"<<n+1<<"]: "<<endl;
for(i=1;i<=n;i++)
{
for(j=1;j<=(n+1);j++)
{
cout<<"A["<<i<<j<<"]"<<endl;
cin>>A[i][j];
}
}

cout<<"The solution of the linear equations is:\n";
gaussele(A,n);
return 0;
}

