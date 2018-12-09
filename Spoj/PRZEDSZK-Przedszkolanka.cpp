//Least common multiple
#include <iostream>
using namespace std;
int nwd(int a, int b)
{
    int minn=min(a,b);

    int d=1;
    for(int j=1; j<=minn; j++)
    {
        if(a%j==0 && b%j==0)
            d=j;
    }
    return d;
}
int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int a, b;
        cin >> a >> b;
        int d=nwd(a,b);
        int nww=a*b/d;
        cout << nww << endl;
    }
    return 0;
}
