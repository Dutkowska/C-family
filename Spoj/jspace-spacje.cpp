//+: text with spaces => text without spaces & touppering the first characters of words.

#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

string sms(string text)
{
    for(int i=0;i<text.size();i++)
    {
        while(text[i]==' ')
        {
               text.erase(i,1);
               text[i]= toupper(text[i]);
        }
    }
    return text;
}

int main()
{
    string text;
    while(getline(cin, text))
    {
        cout << sms(text) << endl;
    }
    // cout << text.size() << endl;
    // isspace(text)
    return 0;
}
