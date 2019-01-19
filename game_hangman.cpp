// basic version of hangman, without GUI
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <time.h>
using namespace std;

//---variables---
string name;
int wrong=0, repeat=4, turn=0; // num of incorrect answers, size of game's loop
string* good = new string[repeat]; // only good chars
int g=0; //index for good
string* write = new string[repeat]; // all chars
string* guess = new string[repeat]; // to write sth like: _ _ a _ b
string words[9] = {"hangman", "input", "name", "hello", "loop", "dog", "cat", "hat", "map"};
string try_word;
string m1= "Try again, you still have ", m2=" chance(s). Enter 'stop' to stop.";


void start(string word, int len)
{
    cout << "Write your name: " << endl;
    cin >> name;
    cout << "Hello " << name << ". Let's start a game!" << endl;
    cout << "Your word has length: " << len << ". Try to guess its, write a letter. Enter 'stop' to stop. " << endl;
    //cout << word; //to tests
}
bool checker(string ch, string word)
{
    bool check=false;
    int position=word.find(ch);
    if(position!=string::npos)
        check=true;
    return check;
}

bool checker(string ch, string ar[], int siz)
{
    // check if ch is in the array ar of size siz
    for(int i=0; i<siz; i++)
    {
        if(ar[i]==ch)
            return true; //position where is ch.
    }
    return false;
}

void game(string ch, int stay)
{
    good[g]=ch;
    g+=1;
    if(stay==0) cout << "Good! It was your last chance." << endl;
    else cout << "Good! " << m1 << stay << m2 << endl;
}

void ender(string word)
{
    cout << "Wrong answers: " << wrong << " times." << endl;
    cout << "Correct answers: " << repeat-wrong << " times." << endl;
    cout << "Your characters: " << endl;
    for(int i=0; i<turn; i++)
        cout << good[i] << " ";
    cout << "Try to write word: " << endl;
    cin >> try_word;
    if(try_word==word) cout << "Good!" << endl;
    else cout << "Wrong, right word: " << word << endl;
}

int main()
{
    //--- variables ---
    srand(time(NULL));
    int randindex=rand()%(repeat+1);
    string word=words[randindex];
    int len=word.length();

    start(word, len);
    while (turn<repeat)
    {
        int stay=repeat-turn-1;
        string ch;
        cin >> ch;
        if(ch=="stop") break;
        else if (ch.length()>1)
        {
            turn-=1;
            cout << "Write only 1 character!" << m1 << stay+1 << m2 << endl;
        }
        // else if char in write and leng...
        else if (checker(ch, write, turn)==true) //and what if we have 'loop' and second 'o'?
        {
            turn-=1;
            cout << "You have already written that character! " << m1 << stay+1 << m2 << endl;
        }
        else
        {
            bool check = checker(ch, word);
            if (check==false)
            {
                wrong+=1;
                if(stay==0)
                {
                    cout << "It was your last chance." << endl;
                    break;
                }
                cout << "Wrong. " << m1 << stay << m2 << endl;
            }
            else
                game(ch, stay);
        }
        write[turn]=ch;
        turn+=1;
        cin.clear();
        cin.ignore(100, '\n');
    }
    ender(word);
    return 0;
}

/*
Things to do:
- what with 'loop' and second 'o':
    + during input
    + write to good with checker f
- make: h_n_a during every loop and in endler()
*/
