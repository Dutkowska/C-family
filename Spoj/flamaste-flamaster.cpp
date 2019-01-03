/*
input:
4
OPSS
ABCDEF
ABBCCCDDDDEEEEEFGGHIIJKKKL
AAAAAAAAAABBBBBBBBBBBBBBBB
output:
OPSS
ABCDEF
ABBC3D4E5FGGHIIJK3L
A10B16
*/

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        char text[201];
        cin >> text;
        int num=1;
        for(int j=0; j<200; j++)
        {
            if(text[j]== NULL)
                break;
            if(num<3)
            {
                if(text[j] == text[j+1])
                    num ++; // when char is repeated
                else
                    num=1;
                if(num<3)
                    cout << text[j];
            }
            else
            {
                if(text[j]==text[j+1])
                    num++;
                else
                {
                    cout <<num;
                    num=1;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
