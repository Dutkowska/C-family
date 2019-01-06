#include <iostream>
using namespace std;

int bubble(int tab[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1; j++)
            if(tab[j]>tab[j+1]) swap(tab[j], tab[j+1]);
    }
    for (int k=0; k<n;k++)
        cout << tab[k] << ", ";
}
int main()
{
    int tab[6]={22,11,23,54,45,62};
    int n=6;
    bubble(tab,n);
    return 0;
}
