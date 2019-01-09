#include <iostream>
using namespace std;
unsigned long long factorial(unsigned int a) //a!
{
    if (a==0) return 1;
    else return a*factorial(a-1);
}

unsigned long long bin_coe(unsigned int n, unsigned int k)
{
    if(n>k) return factorial(n)/(factorial(k)*factorial(n-k));
    else return 0;
}
int main()
{
    unsigned int n, k;
    cin >> n >> k;
    cout << bin_coe(n, k);
    return 0;
}
