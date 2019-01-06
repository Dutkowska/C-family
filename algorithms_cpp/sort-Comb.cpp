// by searching minimum
//find minimum of the list from i-position to its end,
//then swap this value with number in i-position
#include <iostream>
#include <math.h>
using namespace std;

int comb(int tab[], int n)
{
    int gap=n;
    while(gap>1)
    {
        gap=10*gap/13;
        if(gap==0) gap=1;//exit
        gap=floor(gap);
        for(int i=0; i<n-gap; i++)
        {
            if(tab[i+gap]<tab[i]) swap(tab[i], tab[i+gap]);
        }
    }
    for (int k=0; k<n;k++)
        cout << tab[k] << ", ";
}
int main()
{
    int tab[6]={22,11,23,54,45,62};
    int n=6;
    comb(tab,n);
    return 0;
}
