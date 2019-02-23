// task: https://pl.spoj.com/problems/AL_17_01/
#include <iostream>
using namespace std;
int main()
{
    string text = "Mundial ";
    char temp;
    temp = 'R'-' ';
    text += temp;
    temp = 'P'-' ';
	text += temp;
	temp ='Q'-' ';
	text += temp;
	temp = 'T'-' ';
	text += temp;
	cout << text << endl;
}
