#include <iostream>
using namespace std;
void add_mat(int A[][20], int n)
{
    cout << "Enter datas: " << endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> A[i][j];
}
int trace(int A[][20], int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=A[i][i];
    return sum;
}
int main()
{
    int A[20][20], n, tra;
    cout << "Enter the number of columns of a matrix n x n:" << endl;
    cin >> n;
    add_mat(A, n);
    cout << "Trace = " << trace(A, n);
    return 0;
}
