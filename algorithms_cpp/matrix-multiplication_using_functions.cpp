#include <iostream>
using namespace std;

void create_mat(int A[][20], int n, int m)
{
    cout << "Enter datas: " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin >> A[i][j];
    }
}

void multiply_mat(int A[][20], int B[][20], int C[][20], int n, int m, int k)
{
    // create C:
    for(int i=0; i<n; i++)
        for(int j=0; j<k; j++) C[i][j]=0;
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
            for (int z=0; z<m; z++) C[i][j]+=A[i][z]*B[z][j];
    }
}

int main()
{
    int A[20][20], B[20][20], C[20][20], n, m, k;
    cin >> n >> m >> k;
    cout << "A - ";
    create_mat(A, n, m);
    cout << "B - ";
    create_mat(B, m, k);
    multiply_mat(A, B, C, n, m, k);
    cout << "A x B: " << endl;
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++) cout << C[i][j] << " ";
        cout << endl;
    }
}
