//transposing the matrix
// m x n => rows x columns (wiersze  x kolumny)
#include <iostream>
using namespace std;
int main()
{
    int tab[200][200]={0};
    int m,n;
    cin >> m >> n;
    for(int w=0; w<m; w++)
    {
        for(int k=0; k<n; k++)
        {
            cin >> tab[w][k];
        }
    }
    for(int k=0; k<n; k++)
    {
        for(int w=0; w<m; w++)
        {
            cout << tab[w][k] << " ";
        }
        cout << endl;
    }

    return 0;
}
