#include <iostream>
using namespace std;

int insertion(int tab[], int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=i-1; j>=0; j--)
            if(tab[i]<tab[j]) swap(tab[j], tab[j+1]);
    }
    for (int k=0; k<n;k++)
        cout << tab[k] << ", ";
}
int main()
{
    int tab[6]={22,11,23,54,45,62};
    int n=6;
    insertion(tab,n);
    return 0;
}
