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
        sum+=k*i;
        i*=from;
        n/=to;
    }
    return sum;
}
void chose(string c, int n, int system)
{
    if(c=="d")
        cout << "From decimal system to your number system: " << num_sys(n,10, system);
    else if (c=="s")
        cout << "From your number system to decimal system: " << num_sys(n, system, 10);
    else cerr << "Wrong letter";
}
bool check_num(int n, int system)
{
    int k;
    while(n>0)
    {
        k=n%10;
        if (k>=system) return false;
        else n/=10;
        return true;
    }
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
    if (check_num(n, system)==true) chose(way, n, system);
    else cerr << "Wrong number in this system (out of range). ";
    return 0;
}
