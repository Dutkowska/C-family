// task: https://pl.spoj.com/problems/BAJTST/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double heron_form(int a, int b, int c)
{
     if((a < (b+c)) && (b << (a+c)) && (c << (a+b)))
    {
        double p = (a+b+c)/2;
        double her = sqrt((p*(p-a)*(p-b)*(p-c)));
        return her;
    }
    else
        return 0;
}
int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int n;
        double k, res;
        cin >> n >> k;
        for (int j=0; j<n; j++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            res += (heron_form(a, b, c)/10)*k;
        }
        res = round(res);
        cout << res << endl;
    }
}
