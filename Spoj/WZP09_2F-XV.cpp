// check if number n is divided by 15
// with using ASCI and %3, %5 == 0
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    char n[1000];
    int suma=0;
    while(cin>>n)
    {
        if(n[0]=='0')
            break;
        else
        {
            int sizee=strlen(n);
            for(int i=0; i<sizee; i++)
            {
                suma+=(n[i]-48);
            }
            if((suma%3 == 0) && (n[sizee-1]=='0' || n[sizee-1]=='5'))
                cout << "TAK" << endl;
            else
                cout << "NIE" << endl;
        }
    }
    return 0;
}
