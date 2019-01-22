#include <iostream>
using namespace std;
int k, num[10];
char chars[10];

void perm(int k, int pos, string repet)
{
    if(k!=pos)
    {
        for(int i=0; i<k; i++)
        {
            if(num[i]==0)
            {
                // num[i] = 1,0 in comments = > permutations with repetitions
                chars[pos]=(char)(i+'a');
                if(repet=="with")
                    perm(k, pos+1, repet);
                else if(repet=="without")
                {
                    num[i]=1;
                    perm(k, pos+1, repet);
                    num[i]=0;
                }
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
    cout << "With repetitions: " << endl;
    perm(k, 0, "with");
    cout << endl << "Without repetitions: " << endl;
    perm(k, 0, "without");
    return 0;
}
