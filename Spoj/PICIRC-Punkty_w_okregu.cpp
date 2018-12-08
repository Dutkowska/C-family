// check where are this points (in our out of the circle)
/*
I, je�li punkt le�y w obszarze wewn�trznym okr�gu (x-x_0)^2+(y-y_0)^2 < r^2
O, je�li punkt le�y w obszarze zewn�trznym okr�gu
E, je�li punkt le�y na okr�gu
I/O:
centre_of_circle (x_o y_o) radius
number of points
n-points (x y)
5 5 2
4
0 0
6 5
5 7
5 5
*/
#include <iostream>
using namespace std;
int main()
{
    float x_0, y_0, r; //
    int n;
    cin >> x_0 >> y_0 >> r;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        float x, y;
        cin >> x >> y;
        if((x-x_0)*(x-x_0)+(y-y_0)*(y-y_0) < r*r) // in
            cout << "I";
        else if((x-x_0)*(x-x_0)+(y-y_0)*(y-y_0) > r*r) //out
        {
            cout << "O";
        }
        else
            cout << "E";
        cout << endl;
    }
    return 0;
}
