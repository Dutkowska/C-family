/* +: 10 10 => 235.62;  1000 1500 => 1374446.79
r - radius of 2 circles; d - distance between them */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double r, d;
    while(cin >> r >> d)
    {
        double p;
        double pi = 3.141592654;
        //r*=r;
        //d*=d;
        p=(pow(r,2) - pow(d,2)/4)*pi;  // r^2-(d/2)^2 * M_PI
        cout << p << endl;
    }
    return 0;
}
