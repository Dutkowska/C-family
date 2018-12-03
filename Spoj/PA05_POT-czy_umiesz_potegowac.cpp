//+: 2; 2; 3; 3; 3; => 8;7 (the last num of a^b
#include <iostream>
#include <math.h>
using namespace std;

//without using pow(a, b) from math.h:
int pot(long long a, long long b)
{
    if (b==0)
        return 1;
    else
        return (a*(pot(a, b-1)));
}

int main()
{
    unsigned short D;
    cin >> D;
    for(unsigned short i=0; i<D; i++)
    {
        long long a, b, w;
        cin >> a >> b;
        //w=pot(a%10,4+b%4);
        w=pow(a%10, 4+b%4);
        cout << w%10 << endl;
    }
    return 0;
}
