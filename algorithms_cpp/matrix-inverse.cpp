//A−1 = adj(A) / det(A) for matrix 3x3
#include <iostream>
#include <math.h>
using namespace std;
void add_mat(int A[][20], int n)
{
    cout << "Enter datas: " << endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> A[i][j];
}
int det(int A[][20], int n)
{
    if(n==2)
        return A[0][0]*A[1][1]-A[1][0]*A[0][1];
    else if(n==1)
        return A[0][0];
    else if (n==3)
        return A[0][0]*A[1][1]*A[2][2]+A[1][0]*A[2][1]*A[0][2]+A[2][0]*A[0][1]*A[1][2]-A[1][0]*A[0][1]*A[2][2]-A[0][0]*A[2][1]*A[1][2]-A[2][0]*A[1][1]*A[0][2];
    else
        return 0; // not yet
}
int cofactor2(int A[][20], int temp[20][20], int n, int p, int q)
{
    //delete 0 from the start;
    int ii=0, jj=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=p && j!=q)
                temp[ii][jj++]=A[i][j];
            if(jj==n-1)//new col
            {
                jj=0;
                ii++;
            }
        }
    }
}
void cofactor(int A[][20], int n)
{
    int B[20][20];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            //int temp[20][20];
            //B[i][j]=pow(-1, i+j)*det(cofactor2(A, temp, 3, i, j), 2); //*A[without ij[]
            //delete 0 from cof2;
            //delete temp;
        }
    }
}
// if det == 0 return false
int main()
{
    int A[20][20], n=3;
    add_mat(A,n);
    int d;
    d=det(A, n);
    cout << "Det(A) = " << d << endl;
    /*int temp[20][20];
    cofactor2(A, temp, n, 0, 0);
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++) cout << temp[i][j] << " ";
    }
    */
    return 0;
}

