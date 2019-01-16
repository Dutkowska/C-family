//a0 + a1x + a2x ^ 2 + ...
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

double der(double x, double a[], int n)
{
    double sum=0, b=1;
    for(int i=1; i<n; i++)
    {
        sum=sum+a[i]*b*i;
        b*=x;
    }
    return sum;
}
int main()
{
    double a[]={0,0,1}, x=2;
    int n=sizeof(a)/sizeof(a[0]);
    cout << "Derivative: " << der(x, a, n);
    return 0;
}
