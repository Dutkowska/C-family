#include <iostream>
using namespace std;
unsigned int bin_coe(unsigned int n, unsigned int k)
{
    if(k==0 || k==n) return 1;
    else return bin_coe(n-1, k-1)+bin_coe(n-1,k);
}
int main()
{
    unsigned int n, k;
    cin >> n >> k;
    cout << bin_coe(n,k);
    return 0;
}
