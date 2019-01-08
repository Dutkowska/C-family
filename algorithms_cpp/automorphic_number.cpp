//is a number whose square "ends" in the same digits as the number itself.
//n=n*n mod(10^k), k-length of n
#include <iostream>
using namespace std;
bool auto_numb(int n)
{
    int a=10;
    while(n>a) a*=10;
    if((n*n)%a==n) return true;
    else return false;
}
int main()
{
    cout << auto_numb(25) << endl;
    cout << auto_numb(76) << endl;
    cout << auto_numb(27) << endl;
    cout << auto_numb(16) << endl;
    return 0;
}
