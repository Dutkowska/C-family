// delete letters C from the line
// a ababbbaaa => bbbb
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string napis;
    char c;
    while(cin >> c >> napis)
    {
        string neww;
        for(int i=0; i<napis.size(); i++)
        {
            if (napis[i]!=c)
                neww += napis[i];
        }
        cout << neww << endl;
    }
    return 0;
}
