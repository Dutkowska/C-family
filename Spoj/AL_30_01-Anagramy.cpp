//check how many anagrams have text among n words
/*
algorytm 4
samolot
logarytm
rytmolgi
morgatyl   => 2
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string text;
    int n;
    int licz=0;
    cin >> text >> n;
    sort(text.begin(), text.end());
    for(int i=0; i<n; i++)
    {
        string spr;
        cin >> spr;
        sort(spr.begin(), spr.end());
        if(spr==text)
            licz++;
    }
    cout << licz << endl;
    return 0;
}
