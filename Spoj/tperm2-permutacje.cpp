/*
problem should be solved in c - include <cstdio>, printf, scanf.
write all permutacion of n-letters.
*/
#include <iostream>
using namespace std;

int letters[11];
char perm[11];

void permutacje(int n, int pos) {
    if(pos == n) {
        for(int i = 0; i < n; i++)
            cout << perm[i];
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!letters[i]) {
            perm[pos] = (char) (i + 'a');
            letters[i] = 1;
            permutacje(n, pos + 1);
            letters[i] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; j++)
    {
        int n;
        cin >> n;
        permutacje(n, 0);
    }

}
