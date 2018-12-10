//how many times do i have to cut my cake to receive n equal pieces?
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    double n;
    while (cin >> n) {
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        double m = (n - 1)*2.0;
        m = -m;
        double delta = 1.0 - 4.0*m;
        double x_1 = (-1.0 + sqrt(delta))/2.0;
        double x_2 = (-1.0 - sqrt(delta))/2.0;
        if (x_1 > 0) {
            cout << static_cast<int>(ceil(x_1)) << endl;
        }else if (x_2 > 0) {
            cout << static_cast<int>(ceil(x_2)) << endl;
        }
    }
    return 0;
}

