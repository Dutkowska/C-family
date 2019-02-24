// task: https://pl.spoj.com/problems/KC010/
#include <iostream>
using namespace std;
int main()
{
    string text;
    while(getline(cin, text))
    {
        bool new_w = true;
        int words = 0, nums = 0;
        for (int i = 0; i < text.length(); i++)
        {
            if(new_w == true)
            {
                if(text[i] >= 48 && text[i] <=57)
                    nums++;
                else
                    words++;
                new_w = false;
            }
            if(text[i] == ' ')
                new_w = true;
        }
        cout << nums << " " << words << endl;
    }
}
