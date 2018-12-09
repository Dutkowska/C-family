// how many numbers can i have from number 1 to n?
// 3: 123, 231, 321, 312, 132, 213
#include <iostream>
using namespace std;
int main()
{
    const int length = 1000001;
    int tab[length];
    tab[2] = 4;
    tab[3] = 6;

    for(int i = 4; i < length; i++)
        tab[i] = (tab[i-2] * 2) % 101010101;

    int t;
    cin >> t;
    for (int j=0; j<t; j++)
    {
        int n;
        cin >> n;
        cout << tab[n] << endl;
    }
}
