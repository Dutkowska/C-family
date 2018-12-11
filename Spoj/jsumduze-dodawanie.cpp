//add 2 huge numbers
//using asci (+48) and primary school way
#include <iostream>
#include <string>
using namespace std;

string add(string a, string b)
{
    int as=a.size();
    int bs=b.size();

    //minimum of a and b:
    int min=as;
    if(bs<as)
        min=bs;

    int c=0;
    int d=0;
    string wynik="";
    //like in primary school + ASCI
    for(int i=1; i<=min; i++)
    {
        //having both numbers:
        d=(int)(a[--as])+(int)(b[--bs])+c - 96;
        c=d/10;
        wynik=(char)((d%10)+48)+wynik;
    }

    //minimum of as and bs is 0. so we have only one of them:

    while(as)
    {
        //having a:
        d=a[--as]+c-48;
        c=d/10;
        wynik=(char)((d%10)+48)+wynik;
    }
    while(bs)
    {
        d=b[--bs]+c-48;
        c=d/10;
        wynik=(char)((d%10)+48)+wynik;
    }



    if(c)
        wynik=(char)(c+48)+wynik;
    return wynik;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        string a, b;
        cin >> a >> b;
        cout << add(a, b) << endl;
    }
    return 0;
}
