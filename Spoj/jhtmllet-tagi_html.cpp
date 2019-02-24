// task: https://pl.spoj.com/problems/JHTMLLET/
#include <iostream>
using namespace std;
int main()
{
    bool check = false;
    string text;
    while(getline(cin, text))
    {
        for (int i = 0; i < text.length(); i++)
        {
            if(text[i] == '<')
                check = true;
            else if(text[i] == '>')
                check = false;
            if(check == true)
            {
                if(text[i] >= 97 && text[i] <= 122)
                    text[i] -=32;
            }
        }
        cout << text << endl;
    }
}
