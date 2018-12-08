#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
    string pesel;
    int t, suma;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> pesel;
        int tab[11];
        for (int j=0; j<pesel.length(); j++)
        {
            tab[j]=pesel[j];
        }

        suma=tab[0]*1 + tab[1]*3 + tab[2]*7 + tab[3]*9 + tab[4]*1 +tab[5]*3 + tab[6]*7 + tab[7]*9 + tab[8]*1 + tab[9]*3 + tab[10]*1;
        //cout << suma;
        if(suma>0)
        {
            if(suma%10==0)
                puts("D");
            else
                puts("N");
        }
        else
        {
            puts("N");
        }
    }

    return 0;
}
