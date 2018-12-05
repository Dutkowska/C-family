// 0.3 0.3 0.3 => 0; 0.5; 1; 0.5 => 1; -0.5; -0.5; 0 => 2
//Ax^2 + Bx + C = 0
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    while (cin >> a >> b >> c)
    {
        double delta;
        delta=(b*b)-(4*a*c);
        if (delta<0)
            cout << "0" << endl;
        else if (delta==0)
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
    return 0;
}
