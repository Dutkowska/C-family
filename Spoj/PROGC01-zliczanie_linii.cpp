// i/o: text file => number of lines
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    char a;
    int num = 0;
    while ((a=cin.get())!=EOF) // end of file
    {
        if (a=='\n')
            num++;
    }
    cout << num+1 << endl;
    return 0;
}
