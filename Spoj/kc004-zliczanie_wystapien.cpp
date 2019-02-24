// task: https://pl.spoj.com/problems/KC004/
#include <iostream>
using namespace std;
int main()
{
    int a, b, tab[10000];
    while (cin >> a >> b)
    {
        for (int i = 0; i < 10000; i++)
            tab[i] = 0;
        for (int i = 0; i < b; i++)
        {
            int c;
            cin >> c;
            tab[c] += 1;
        }
        cout << tab[a] << endl;
    }
}
