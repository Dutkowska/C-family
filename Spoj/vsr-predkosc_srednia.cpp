// +: 2; 50; 50; 40; 60 => 50; 48
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    short int t;
    short int v, w;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        //scanf("%f%f",&v,&w);
        cin >> v >> w;
        short int wynik;
        wynik = 2*v*w/(v+w);
        cout << wynik << endl;
    }
    return 0;
}
