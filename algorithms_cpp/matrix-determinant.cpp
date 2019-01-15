#include <iostream>
using namespace std;
void add_mat(int A[][20], int n)
{
    cout << "Enter datas: " << endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> A[i][j];
}

int adjugate(int A[][20], int temp[20][20], int n, int p, int q)
{
    int ii=0, jj=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=p && j!=q)
            {
                temp[ii][jj++]=A[i][j];
                if(jj==n-1)//new col
                {
                    jj=0;
                    ii++;
                }
            }
        }
    }
}

int det(int A[][20], int n)
{
    if(n==1)
        return A[0][0];
    else
    {
        int de=0;
        int B[20][20], sign=1;
        for(int i=0; i<n; i++)
        {
            adjugate(A, B, n, 0, i);
            de+=A[0][i]*sign*det(B, n-1);
            sign=-sign;
        }
        return de;
    }
    /* or not with recursive:
    else if(n==2)
        return A[0][0]*A[1][1]-A[1][0]*A[0][1];
    else if (n==3)
        return A[0][0]*A[1][1]*A[2][2]+A[1][0]*A[2][1]*A[0][2]+A[2][0]*A[0][1]*A[1][2]-A[1][0]*A[0][1]*A[2][2]-A[0][0]*A[2][1]*A[1][2]-A[2][0]*A[1][1]*A[0][2];*/
}
int main()
{
    int A[20][20], n, de;
    cout << "Enter the number of columns of a matrix n x n: " << endl;
    cin >> n; // for that moment: try 3;
    add_mat(A,n);
    de=det(A, n);
    cout << "Det(A) = " << de << endl;
    return 0;
}
