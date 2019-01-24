#include <iostream>
#include <algorithm>
using namespace std;
string rotation(string text)
{
    int n=text.length();
    string tab[n], cat=text+text;
    for(int i=0; i<n; i++)
        tab[i]=cat.substr(i, n);
    sort(tab, tab+n);
    // for all lexicographically rotation: print all from tab.
    return tab[0];
}
int main()
{
    cout << rotation("dutkowska") << endl;
    return 0;
}
