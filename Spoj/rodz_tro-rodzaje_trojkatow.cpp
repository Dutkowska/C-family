#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int a, b, c;
    while(cin >> a >> b >> c)
    {
        int tab[]={a, b, c};
        sort(tab, tab+3);
        if (tab[0]+tab[1]<=tab[2])
            puts("brak");
        else if(tab[0] * tab[0] + tab[1] * tab[1] == tab[2] * tab[2])
            puts("prostokatny");
        else if(tab[0] * tab[0] + tab[1] * tab[1] > tab[2] * tab[2] )
            puts("ostrokatny");
        else
            puts("rozwartokatny");
    }
    return 0;
}
