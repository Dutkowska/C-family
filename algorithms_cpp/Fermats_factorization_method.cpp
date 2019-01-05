// with using p=x^2-y^2=(x+y)(x-y), p-odd number
//a=x+y; b=x-y
#include <iostream>
#include <cmath>

using namespace std;

void Fermats(unsigned int p)
{
  unsigned int x,y,a,b,y2;
  x = ceil(sqrt(p));
  y2 = x*x-p;
  y = floor(sqrt(y2));
  while(x + y < p)
  {
    if(y2==y*y) //p=x^2-y^2
    {
      a=x+y;
      b=x-y;
      if(b == 1) break;
      Fermats(a);
      Fermats(b);
      return;
    }
    x++;
    y2=x*x-p;
    y=floor(sqrt(y2));
  }
  cout << p << ". ";
}

int main()
{
  unsigned int p;
  cin >> p;
  while(p%2==0)
  {
    p /= 2;
    cout << 2 << ", ";
  }
  Fermats(p);
  return 0;
}
