#include <iostream>
using namespace std;
unsigned int fac_it(unsigned int a)
{
    unsigned long long b=1;
    if(a==0) return 1;
    else
    {
        while(a>0)
        {
            b*=a;
            a--;
        }
        return b;
    }
}
int main()
{
    unsigned int a;
    cin >> a;
    cout << fac_it(a);
    return 0;
}
