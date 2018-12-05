// 2; pierwszy; lubiec => pier; lub
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        string text;
        cin >> text;
        for (int j=0; j<text.length()/2; j++)
            cout << text[j];
        cout << endl;
    }

    return 0;
}
