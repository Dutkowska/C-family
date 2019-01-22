// task have to be in C - but I made this in C++ for my own uses.
#include <iostream>
using namespace std;
int k, num[10];
char chars[10];

void perm(int k, int pos)
{
    if(k!=pos)
    {
        for(int i=0; i<k; i++)
        {
            if(num[i]==0)
            {
                // num[i] = 1,0 in comments = > permutations with repetitions
                chars[pos]=(char)(i+'a');
                num[i]=1;
                perm(k, pos+1);
                num[i]=0;
            }
        }
    }
    else
    {
        for(int i=0; i<k; i++)
            cout << chars[i];
        cout << endl;
        return;
    }
}
int main()
{
    cin >> k;
    perm(k, 0);
    return 0;
}
