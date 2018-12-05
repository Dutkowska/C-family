//+: 2; 1; 4 => 0 1; 2 4;

#include <iostream>
#include <cstdio>
using namespace std;

/*int silnia_rek(unsigned long long n) // without time limits
{
    if (n<2)
    {
        return n;
    }
    else
        return silnia_rek(n-1)*n;
}*/

int main()
{
    unsigned int D; // liczba przypadkow
    cin >> D;
    //int w;
    for (int i=0; i<D; i++)
    {
        unsigned int n;
        cin >> n;
        //unsigned long long sil;
        //sil=silnia_rek(n);
        if (n>9)
        {
        	cout << "0 0" << endl;
        }
        else
        	/* without looking at the time limit & int w & silnia_rek & unsigned long long sil:
        	w=sil%100;
        	cout << w/10 << " " << w%10 << endl; */
            switch (n) {
                case 0:
                    cout << "0 1" << endl;
                    break;
                case 1:
                    cout << "0 1" << endl;
                    break;
                case 2:
                    cout << "0 2" << endl;
                    break;
                case 3:
                    puts("0 6");
                    break;
                case 4:
                    puts("2 4");
                    break;
                case 5:
                    puts("2 0");
                    break;
                case 6:
                    puts("2 0");
                    break;
                case 7:
                    puts("4 0");
                    break;
                case 8:
                    puts("2 0");
                    break;
                case 9:
                    puts("8 0");
                default:
                    break;
            }
    }

    return 0;

}
