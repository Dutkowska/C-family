// reversed tab
#include <iostream>
using namespace std;

int main()
{
    int a;
    while(cin >> a)
    {
        tab.push_back(a);
    }
    for(int i=tab.size()-1; i>=0; i--)
        cout<<tab[i]<<" ";
    return 0;
}

