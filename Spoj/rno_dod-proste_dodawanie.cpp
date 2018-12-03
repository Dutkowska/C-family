// +: 1; 2; -100; 100 => 0
#include <iostream>
using namespace std;

int main()
{
    unsigned int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        int suma=0;
        for (int j=0; j<n; j++)
        {
            int wp;
            cin >> wp;
            suma+=wp;
        }
        cout << suma << endl;
    }
    return 0;
}
