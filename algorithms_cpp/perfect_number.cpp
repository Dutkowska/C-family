#include <iostream>
using namespace std;

bool perfect_number(int n)
{
    int sum=0;
    for(int i=1; i<=(n/2); i++)
        if((n%i)==0) sum+=i;
    if(sum==n) return true;
    else return false;
}

int main()
{
    cout << perfect_number(28);
    return 0;
}
