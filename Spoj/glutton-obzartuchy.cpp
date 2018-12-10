// t - tests; n - number of people; m - how many cakes in the box; sec - time of eating for one person
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double doba=60*60*24;
    int t;
    cin>> t;
    for(int i=0; i<t; i++)
    {
        double n, m, suma=0;
        cin >> n >> m;
        for(int j=0; j<n; j++)
        {
            double sec;
            cin >> sec;
            suma+=floor(doba/sec); // he cant start eating piece of cake
        }
        if(suma!=0)
            cout << ceil(suma/m) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
