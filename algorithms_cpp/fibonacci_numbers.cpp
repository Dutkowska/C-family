#include <iostream>
using namespace std;
unsigned int fib(unsigned int n)
{
    if (n==1 || n==2) return 1;
    else return fib(n-1)+fib(n-2);
}
int main()
{
    unsigned int n;
    cin >> n;
    cout << fib(n);
    return 0;
}
