/* write number without pair:
input:
2
3
1 2 1
5
3 3 3 3 3
output:
2
3
*/
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int n, a, b;
        cin>>n;
        a=0;
        while(n--)
        {
            cin >> b;
            a ^= b;
        }
        cout << a << endl;
    }
    return 0;
}
