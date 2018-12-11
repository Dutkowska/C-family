/* move n-numbers by k positions */
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int tab[n];
    for(int i=0; i<n; i++)
        cin >> tab[i];
    for(int j=k; j<n; j++)
        cout << tab[j] << " ";
    for(int m=0; m<k; m++)
        cout << tab[m] << " ";
    return 0;
}
