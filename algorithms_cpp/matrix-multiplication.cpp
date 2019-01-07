#include <iostream>
using namespace std;
// the simplest solution, without functions
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int **A; // n x m
    A=new int*[n];
    for (int i=0; i<n; i++)
        A[i]=new int[m];
    for(int j=0; j<n; j++)
        for(int z=0; z<m; z++) cin >> A[j][z];

    int **B; // m x k
    B=new int*[m];
    for(int i=0; i<m; i++)
            B[i]=new int[k];
    for(int j=0; j<m; j++)
        for (int z=0; z<k; z++) cin >> B[j][z];

    int **C; // n x k
    C=new int*[n];
    for(int i=0; i<n;i++)
        C[i]=new int[k];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
          int s = 0;
          for(int z = 0; z < m; z++) s += A[i][z] * B[z][j];
          C[i][j] = s;
        }
    }
    cout << "A x B = \n";
    for(int i=0; i<n; i++)
    {
        for (int j=0; j<k; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
