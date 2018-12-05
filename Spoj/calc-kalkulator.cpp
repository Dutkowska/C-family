//+ dodawanie, - odejmowanie, * mnoÅ¼enie, / dzielenie caÅkowitoliczbowe, % reszta z dzielenia
#include <iostream>
using namespace std;
int main ()
{
    char sign;
    int a, b;
    while (cin >> sign >> a >> b) {
        switch (sign)
        {
            case '+':
                cout << a+b << endl;
                break;
            case '-':
                cout << a-b << endl;
                break;
            case '*':
                cout << a*b << endl;
                break;
            case '/':
                cout << a/b << endl;
                break;
            case '%':
                cout << a%b << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}

