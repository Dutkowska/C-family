// firstly write numbers from even positions, then from odd positions
//t - num of tests; n - num of numbers; n-numbers
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; t++)
    {
        int n, *tab;
        cin >> n;
        tab=new int[n];
        for(int j=0; j<n; j++)
            cin >> tab[j];

        for(int k=0; k<n; k++) // parzyste: 1, 3...
        {
            if(k%2!=0)
            {
                cout << tab[k] << " ";
            }
        }
        for(int l=0; l<n; l++)
        {
            if(l%2==0)
            {
                cout << tab[l] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

