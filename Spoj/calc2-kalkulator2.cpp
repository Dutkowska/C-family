//+ dodawanie, - odejmowanie, * mnoÅ¼enie, / dzielenie caÅkowitoliczbowe, % reszta z dzielenia, z - zapisanie do rejestru
#include <iostream>

using namespace std;

int main ()
{
    int a,b;
    char sign;
    int tab[10] = {0};
    int w;
    while (cin >> sign >> a >> b) {
        switch (sign) {
            case '+':
                w = tab[a] + tab[b];
                cout << w << endl;
                break;
            case '-':
                w = tab[a] - tab[b];
                cout << w << endl;
                break;
            case '*':
                w = tab[a] * tab[b];
                cout << w << endl;
                break;
            case '/':
                w = tab[a] / tab[b];
                cout << w << endl;
                break;
            case '%':
                w = tab[a] % tab[b];
                cout << w << endl;
                break;
            case 'z':
                tab[a] = b;
                break;
            default:
                break;
        }
    }
    return 0;
}

