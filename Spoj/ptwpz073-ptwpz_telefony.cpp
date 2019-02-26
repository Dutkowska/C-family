// task: https://pl.spoj.com/problems/PTWPZ073/
// with using ascii
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        string text;
        cin >> text;
        for(int j=0; j<text.length(); j++)
        {
            if(text[j] >= 65 && text[j] <= 67) //a,b,c
                cout << 2;
            else if(text[j] >= 68 && text[j] <= 70)
                cout << 3;
            else if(text[j] >= 71 && text[j] <= 73)
                cout << 4;
            else if(text[j] >= 74 && text[j] <= 76)
                cout << 5;
            else if(text[j] >= 77 && text[j] <= 79)
                cout << 6;
            else if(text[j] >= 80 && text[j] <= 83)
                cout << 7;
            else if(text[j] >= 84 && text[j] <= 86)
                cout << 8;
            else if(text[j] >= 87 && text[j] <= 90)
                cout << 9;
        }
        cout << endl;
    }
}
