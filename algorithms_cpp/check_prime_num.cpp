#include <iostream>
using namespace std;

string prime_num(int n)
{
    bool prime=true;
    for(int i=2; i<n/2; i++)
    {
        if (n%i==0) prime=false; break;
    }
    if (prime) cout << "YES";
    else cout << "NO";
}
int main()
{
    int a;
    cin >> a;
    prime_num(a);
    return 0;
}
