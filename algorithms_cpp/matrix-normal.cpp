#include <iostream>
#include <math.h>
using namespace std;
void add_mat(int A[][20], int n)
{
    cout << "Enter datas: " << endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> A[i][j];
}
double norm(int A[][20], int n)
{
    double nor=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) nor+=A[i][j]*A[i][j];
    return sqrt(nor);
}

int main()
{
    int A[20][20], n, tra;
    cout << "Enter the number of columns of a matrix n x n:" << endl;
    cin >> n;
    add_mat(A, n);
    cout << "Normal = " << norm(A, n);
    return 0;
}
