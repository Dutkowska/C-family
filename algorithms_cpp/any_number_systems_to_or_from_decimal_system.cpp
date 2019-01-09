//chose your number system and then convert number from/to this system to/from decimal system
//example: 8, s (from 8-base), 345 -> 229 .... 2, d (to 2-base), 21 -> 10101;
#include <iostream>
using namespace std;
int num_sys(int n, int from, int to)
{
    int k, sum=0, i=1;
    while(n>0)
    {
        k=n%to;
        sum=sum+k*i;
        i*=from;
        n=n/to;
    }
    return sum;
}
void chose(string c, int n, int system)
{
    if(c=="d")
    {
        cout << "From decimal to your number system: ";
        cout << num_sys(n,10, system);
    }
    else if (c=="s")
    {
        cout << endl << "From your number system to decimal: ";
        cout << num_sys(n, system, 10);
    }
    else cout << "Wrong letter";
}
int main()
{
    int n, system;
    string way;
    cout << "Choose number system by base (from 2 to 9): " << endl;
    cin >> system;
    cout << "Choose: 10-base system to " << system << "-base system (d) or " << system << "-base system to 10-base system (s): " << endl;
    cin >> way;
    cout << "Enter your number: ";
    cin >> n;
    chose(way, n, system);
    return 0;
}
