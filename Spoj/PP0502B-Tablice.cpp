#include <iostream>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        cin >> n;
        int *tab;
        tab=new int[n];
        for (int j=0; j<n; j++)
        {
            cin >> tab[j];
        }
        cout << tab[n-1];
        for (int k=n-2; k>=0; k--)
        {
            cout << " " << tab[k];
        }
        cout << endl;
    }
    return 0;
}
