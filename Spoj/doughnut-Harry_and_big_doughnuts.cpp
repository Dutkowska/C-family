// task: https://pl.spoj.com/problems/DOUGHNUT/
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int c, k, w;
        cin >> c >> k >> w;
        if((c*w)>k)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
    return 0;
}
