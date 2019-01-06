// by searching minimum
//find minimum of the list from i-position to its end,
//then swap this value with number in i-position
#include <iostream>
using namespace std;

int selection(int tab[], int n)
{
    for(int i=0; i<n; i++)
    {
        int k=i;
        for(int j=i+1; j<n; j++)
            if(tab[j]<tab[k]) k=j;
        swap(tab[i], tab[k]);
    }
    for (int k=0; k<n;k++)
        cout << tab[k] << ", ";
}
int main()
{
    int tab[6]={22,11,23,54,45,62};
    int n=6;
    selection(tab,n);
    return 0;
}
