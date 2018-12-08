/*
ax+b=c; a,b,c in real numb
solution: (c-b)/a
no solution: BR (a=0 && b!=0)
infinitely many solutions: NWR (a=0 && b=0)
*/
#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
float roundtwo(float x)
{
    return round(x*100)/100;
}
int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    float w;
    if (a!=0)
    {
        //w=roundtwo((c-b)/a);
        //cout << w << endl;
        printf("%.2f\n", (c-b)/a);
    }
    else if(a==b-c)
    {
        puts("NWR"); // infinitely
    }
    else if(a==0 && b-c!=0.0)
    {
        puts("BR"); // not solution
    }
    return 0;
}
