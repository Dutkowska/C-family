#include <iostream>
using namespace std;
void print(int A[],int nn)
{
    for (int i=0; i<nn; i++)
        cout << A[i] << " ";
    cout << endl;
}
void heap(int A[], int n, int nn)
{
    if(n==1)
    {
        print(A, nn);
        return;
    }

    for (int i=0; i<n; i++)
    {
        heap(A,n-1,nn);
        if (n%2==0) swap(A[i], A[n-1]);
        else swap(A[0], A[n-1]);
    }
}

int main()
{
    int A[] = {1, 2, 3};
    int n = sizeof(A)/sizeof(A[0]);
    heap(A, n, n);
    return 0;
}
