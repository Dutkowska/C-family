#include <iostream>
using namespace std;


void add_mat(int A[][20], int n)
{
    cout << "Enter datas: " << endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> A[i][j];
}
string identity_mat(int A[][20], int n)
{
    for(int i=0; i<n; i++)
    {
        if(A[i][i]!=1) return "identity matrix: false";
        else
        {
            for(int j=0; j<n; j++)
                if (i!=j && A[i][j]!=0) return "identity matrix: false";
        }
        return "identity matrix: true";
    }
}
string zero_mat(int A[][20], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if(A[i][j]!=0) return "zero matrix: false";
    }
    return "zero matrix: true";
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

string nilpotent_mat(int A[][20], int n) // A^k = zeros
{
    int B[20][20];
    for(int i=0; i<20; i++)
    {
        int check=0;
        multiply_mat(A, A, B, n, n, n);
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
                if(B[i][j]==0) check+=1;
        }
        if (check==n*n) return "nilpotent mat: true";
    }
    return "nilpotent mat: false";
}

string symmetric_mat(int A[][20], int n) //A^t=A
{
    int B[20][20];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if (A[i][j]!=A[j][i]) return "symmetric mat: false";
    }
    return "symmetric mat: true";
}
string skew_symmetric_mat(int A[][20], int n) //A^t=-A
{
    int B[20][20];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if(A[i][j]!=-A[j][i]) return "skew-symmetric mat: false";
    }
    return "skew-symmetric mat: true";
}

string orthogonal_mat(int A[][20], int n) //A*A^t=I
{
    int trans[20][20], unit[20][20], mult[20][20];
    for(int i=0; i<n; i++) // create A^t and I
    {
        for(int j=0; j<n; j++)
        {
            trans[i][j]=A[j][i];
            if(i==j) unit[i][j]=1;
            else unit[i][j]=0;
        }
    }
    multiply_mat(A, trans, mult, n, n, n);
    for(int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            if(mult[i][j]!=unit[i][j]) return "orthogonal mat: false";
    }
    return "orthogonal mat: true";
}

int main()
{
    int A[20][20], n, de;
    cout << "Enter the number of columns of a matrix n x n: " << endl;
    cin >> n;
    add_mat(A,n);
    cout << identity_mat(A, n) << endl;
    cout << zero_mat(A, n) << endl;
    cout << nilpotent_mat(A, n) << endl;
    cout << symmetric_mat(A, n) << endl;
    cout << skew_symmetric_mat(A, n) << endl;
    cout << orthogonal_mat(A, n) << endl;
    return 0;
}
