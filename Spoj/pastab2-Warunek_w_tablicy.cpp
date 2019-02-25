// task: https://pl.spoj.com/problems/PASTAB2/
#include <iostream>
using namespace std;
int main()
{
    int t, n;
    char sign;
    cin >> t;
    int tab[t];
    for(int i = 0; i<t; i++)
    {
        int num;
        cin >> num;
        tab[i] = num;
    }
    cin >> sign >> n;
    if(sign == '>')
    {
        for(int j=0; j<t; j++)
        {
            if(tab[j] > n)
                cout << tab[j] << endl;
        }
    }
    else
    {
        for(int k=0; k<t; k++)
        {
            if(tab[k] < n)
                cout << tab[k] << endl;
        }
    }
}
