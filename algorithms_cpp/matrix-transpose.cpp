#include <iostream>
using namespace std;

void create_mat(int A[][20], int n, int m)
{
    cout << "Enter datas: " << endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> A[i][j];
}

void transpose_mat(int A[][20], int n, int m)
{
    int B[20][20];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++) B[i][j] = A[j][i];

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++) cout << B[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int A[20][20], n, m;
    cin >> n >> m;
    create_mat(A, n, m);
    transpose_mat(A, n, m);
    return 0;
}
