#include <iostream>
using namespace std;
int main()
{
    string text;
    while(cin >> text)
    {
        for(int i = text.length()-1; i>=0; i--)
            cout << text[i];
        cout << endl;
    }
}
