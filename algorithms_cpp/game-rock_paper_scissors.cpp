#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

//--variables--
string shapes[3]={"r", "p", "s"};
string name, chosen, mess="number of chances: ";
int repeat, loss=0, wins=0;

void beginer()
{
    cout << "Write your name: " << endl;
    cin >> name;
    cout << "Hello " << name << " let's start a game! Enter number of repetitions: " << endl;
    cin >> repeat;
    if(cin.fail())
        cout << "Not a numerical data, end of the game!" << endl;
}
void game()
{
    srand(time(NULL));
    int i=0;
    while(i<repeat)
    {
        int randindex=rand()%3;
        string shape=shapes[randindex];
        cout << shape; //for quick tests
        cout << "Your shape - rock/paper/scissors [r/p/s]? Enter 'stop' to stop." << endl;
        cin >> chosen;
        if(shape==chosen)
        {
            cout << "Good! You won!" << endl;
            wins+=1;
        }
        else if(chosen=="stop")
            break;
        else if (!(chosen=="r" || chosen=="p" || chosen=="s"))
        {
            cout << "Write only r/p/s" <<endl;
            i--;
        }
        else
        {
            cout << "You lost." << endl;
            loss+=1;
        }
        i++;
        cout << mess << repeat-i << endl;
    }
}
void ender()
{
    cout << endl << "---- End of the game ----"<<endl;
    cout << "Statistics of " << name << ":" << endl;
    cout << "Number of rounds: " << repeat << endl;
    cout << "Wins: " << wins << endl;
    cout << "Lost: " << loss << endl;
    cout << "Thank you for the game!" << endl;
}

int main()
{
    beginer();
    game();
    ender();
    return 0;
}
