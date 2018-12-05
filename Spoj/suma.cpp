//+: 6;8;-3 => 6;14;11  add to the previous one
#include <iostream>
using namespace std;
int main()
{
    int x;
    int suma=0;
    while(cin >> x)
    {
        suma+=x;
        cout << suma << endl;
    }
    return 0;
}
