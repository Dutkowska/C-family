// is there a triangle with this 3 sides? (No - 0, yes - 1)
// 2 4 8 => 0
#include <iostream>
#include <algorithm>
using namespace std;
float sorter(float tab[], int length)
{
    int tmp;
    for (int i=0; i<length; i++)
    {
        tmp=i;
        int tmp2;
        while(tmp > 0 && tab[tmp] < tab[tmp-1]) // check if this one isn't smaller than the previous ones
        {
            // 2 1
            tmp2 = tab[tmp];     //1
            tab[tmp] = tab[tmp - 1]; //2
            tab[tmp - 1] = tmp2; //1
            tmp--; // 1 2
        }
    }
}
int main()
{
    float tab[3];
    while (cin >> tab[0] >> tab[1] >> tab[2])
    {
        sorter(tab, 3);
        //sort(tab[0], tab[0]+3, greater<float>());
        if (tab[0]+tab[1]>tab[2])
        {
            cout << "1" << endl;
        }
        else
            cout << "0" << endl;
    }
    return 0;
}

