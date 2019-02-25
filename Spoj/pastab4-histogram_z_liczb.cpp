/*
task: https://pl.spoj.com/problems/PASTAB4/
there is a problem here, find its!
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num, tab[21], n = 0;
    for(int i=0; i<21; i++)
        tab[i] = 0;
    while(cin >> num)
        tab[num+10]++;
    for(int j=0; j<21; j++)
    {
        if(tab[j]> n)
            n = tab[j];
    }
    for(int k=-10; k<11; k++)
    {
        int res;
        if(n>0 && tab[k+10]>0)
        {
            double m = tab[k+10]*100/n;
            res = m*30/100;
        }
        else
            res = 0;
        if(k >= 0 || abs(k)!=10)
        {
            cout << " ";
            if(k >= 0)
                cout << k << ":|";
        }
        for(int l=0; l<res; l++)
            cout << "*";
        for(int i=0; i<30 - res; i++)
            cout << " " << "|" << endl;
    }
}
