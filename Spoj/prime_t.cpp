// +: 3; 11; 1; 4 => TAK; NIE; NIE
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int j=1; j<=n; j++)
    {
        int l;
        cin >> l;
        int pyt;  // maly bool
        if (l==1)
        {
            pyt=0;
        }


        for(int i=2; i<l; i++)
        {
            if (l%i==0)
            {
                pyt=0;
                i=l;

            }
        }

        switch(pyt)
        {
        case 0:
            cout << "NIE" << endl;
            break;
        default:
            cout << "TAK" << endl;
            break;
        }
        pyt = 1;
    }
    return 0;
}
