// firstly write numbers from odd positions, then from the even positions.
#include <iostream>

using namespace std;

int main()
{
    int t, tab[100];
    cin >> t;

    for (int i=0; i<t; i++)
    {
        int n, half, start=0;
        cin >> n;
        half = n/2;
        for(int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if (j%2 == 0) {
                tab[start] = a;
                start++;
            } else {
                tab[half] = a;
                half++;
            }
        }

        for (int k = 0; k < n; k++) {
            cout << tab[k] << " ";
        }
        cout << endl;
    }

    return 0;
}
