//-: num of tests; size of array; array;.... => the nearest num to average
// 4 3 2 1 => 3
#include <iostream>
// for using abs => include cmath
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        float srednia;
        int rozmiar_tab;
        int suma=0, liczba=0;
        cin >> rozmiar_tab;
        int *tab;
        tab=new int[rozmiar_tab];

        for(int j=0; j<rozmiar_tab; j++)
        {
            cin >> tab[j];
            liczba++;
            suma +=tab[j];
        }
        srednia=static_cast<float>(suma)/static_cast<float>(liczba);
        //cout << endl << "srednia: " << srednia << endl;
        int tmp = tab[0]-srednia;
        if (tmp<0)
            tmp = - tmp; // abs i cmath

        int a=1, b, najbl;
        while(a!=rozmiar_tab)
        {
            najbl=tab[a]-srednia;
            if(najbl<0)
                najbl=-najbl;
            if (najbl<tmp)
            {
                tmp=najbl;
                b=tab[a];
            }
            a++;
        }
        cout << b << endl;
        delete [] tab;
    }
    return 0;
}
