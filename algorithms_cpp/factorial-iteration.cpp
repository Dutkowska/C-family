#include <iostream>
using namespace std;
int main()
{
    unsigned int a;
    unsigned long long b=1;
    cin >> a;
    if(a==0) cout << "1";
    else
    {
        while(a>0)
        {
            b*=a;
            a--;
        }
        cout << b;
    }
    return 0;
}
