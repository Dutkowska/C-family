#include <iostream>
#include <cmath>
using namespace std;
void pr_fac(unsigned int n)
{
    for (int i=2; i<sqrt(n); i++)
    {
        while(n%i==0 && n>0)
        {
            cout << i << ", ";
            n /=i;
        }
    }
    cout << n;
}
int main()
{
    unsigned int n;
    cin >> n;
    pr_fac(n);
    return 0;
}
