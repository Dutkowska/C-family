#include <iostream>
using namespace std;
unsigned long long factorial(unsigned int a) //a!
{
    if (a==0) return 1;
    else return a*factorial(a-1);
}
int main()
{
    unsigned int a;
    cin >> a;
    cout << factorial(a);
}
