// 1; 7 2 4 => 2 6
//all numbers < n divided by x and indivisible by y
// t = num of tests; n = max; x = number for divisibility; y = indivisibility
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int p=x;
        if (p%y!=0)
            cout << p;
        while(p+x<n)
        {
            p+=x;
            if(p%y!=0)
                cout << " " << p;
        }
        cout << endl;
    }

    return 0;
}
