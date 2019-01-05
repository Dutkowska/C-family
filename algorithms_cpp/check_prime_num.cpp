#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    bool prime=true;
    for(int i=2; i<a/2; i++)
    {
        if (a%i==0)
        {
            prime=false;
            break;
        }
    }
    if (prime) cout << "it is a prime num";
    else cout << "it isnt a prime num";
    return 0;
}
