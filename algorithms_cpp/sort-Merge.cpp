// dividing into 2 tab (and more, more...) and merge them
#include <iostream>
using namespace std;

int merger(int tab[], int a, int mid, int n)
{
    int i, j, k, tab2[n];
    for(i=a; i<=n; i++) tab2[i]=tab[i];
    i=a; j=a;
    k=mid+1;
    while(k<=n, i<=mid)
    {
        if(tab2[i]<tab2[k]) tab[j++]=tab2[i++];
        else tab[j++]=tab2[k++];
    }
    while(i<=mid) tab[j++]=tab2[i++];
}

int sort_merge(int tab[], int a, int n)
{
    int mid;
    if (a<n)
    {
        mid=(a+n)/2; // dividing into 2 tab and merge them
        sort_merge(tab, a, mid);
        sort_merge(tab, mid+1, n);
        merger(tab, a, mid, n);
    }
}
int main()
{
    int tab[]={22,11,55,3,22,50};
    int n=sizeof(tab)/sizeof(tab[0]);
    sort_merge(tab, 0, n-1);
    for(int i=0; i<n; i++)
        cout << tab[i] << " ";
    return 0;
}
