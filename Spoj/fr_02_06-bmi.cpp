#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string name[t];
    double masa[t];
    double wzrost[t];
    double bmi[t];

    for(int i=0; i<t; i++)
    {
        cin >> name[i] >> masa[i] >> wzrost[i];
        bmi[i]=masa[i]*10000/(wzrost[i]*wzrost[i]);
    }

    cout << "niedowaga" << endl;
    for(int i=0; i<t; i++)
    {
        if(bmi[i]<18.5)
            cout << name[i] << endl;
    }

    cout<<endl << "wartosc prawidlowa"<<endl;
    for(int i=0; i<t; i++)
    {
        if(bmi[i] >= 18.5 && bmi[i] < 25.0)
            {
                cout<<name[i]<<endl;
            }
    }

    cout<<endl << "nadwaga"<<endl;
    for(int i=0; i<t; i++)
    {
        if(bmi[i] >= 25.0)
        {
            cout<<name[i]<<endl;
        }
    }
    return 0;
}
