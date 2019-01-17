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

int main()
{
    int A[20][20], n, de;
    cout << "Enter the number of columns of a matrix n x n: " << endl;
    cin >> n; // for that moment: try 3;
    add_mat(A,n);
    cout << identity_mat(A, n) << endl;
    cout << zero_mat(A, n) << endl;
    return 0;
}
