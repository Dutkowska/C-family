// basic version of hangman, without GUI
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <algorithm>
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


void start(string word, string lines[])
{
    cout << "Write your name: " << endl;
    cin >> name;
    cout << "Hello " << name << ". Let's start a game!" << endl;
    cout << "Your word has length: " << word.length() << endl;
    for(int i=0; i<word.length(); i++)
        cout << lines[i] << " ";
    cout << endl << "Try to guess its, write a letter. Enter 'stop' to stop. " << endl;
    //cout << word; //to quick tests
}
bool checker(string ch, string word, string lines[], int good_count, int word_count)
{
    //and making _ o o _ _
    bool check=false;
    int position=word.find(ch);
    if(position!=string::npos)
    {
        check=true;
        if (good_count!=0 && word_count>1)
        {
            int new_position=word.find(ch, position+1);
            position=new_position;
        }
        lines[position]=ch;
    }
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

void game(string ch, int stay, int good_count, size_t word_count, string lines[], string word)
{
    good[g]=ch;
    g+=1;
    for(int i=0; i<word.length(); i++)
        cout << lines[i] << " ";
    if(stay==0) cout << endl << "Good! It was your last chance." << endl;
    else cout << endl << "Good! " << m1 << stay << m2 << endl;
}

void ender(string word, string lines[])
{
    cout << "Wrong answers: " << wrong << " times." << endl;
    cout << "Correct answers: " << repeat-wrong << " times." << endl;
    cout << "Your characters: " << endl;
    for(int i=0; i<word.length(); i++)
        cout << lines[i] << " ";
    cout << endl << "Try to write word: " << endl;
    cin >> try_word;
    if(try_word==word) cout << "Good!" << endl;
    else cout << "Wrong, right word: " << word << endl;
}

int main()
{
    //--- variables ---
    srand(time(NULL));
    int randindex=rand()%9;
    string word=words[randindex];
    int len=word.length();
    string lines[len]; // for sth like: _ _ a _ m
    for(int i=0; i<len; i++)
        lines[i]="_";

    start(word, lines);
    while (turn<repeat)
    {
        int stay=repeat-turn-1;
        string ch;
        cin >> ch;
        int good_count=count(good, good+repeat, ch); //for good_count!=word_count ==> 'loop' and second 'o'
        size_t word_count=count(word.begin(), word.end(), ch[0]);

        if(ch=="stop") break;
        else if (ch.length()>1)
        {
            turn-=1;
            for(int i=0; i<word.length(); i++)
                cout << lines[i] << " ";
            cout << endl << "Write only 1 character!" << m1 << stay+1 << m2 << endl;
        }
        else if (checker(ch, write, turn)==true && good_count==word_count) //if we have 'loop' and third 'o'
        {
            turn-=1;
            for(int i=0; i<word.length(); i++)
                cout << lines[i] << " ";
            cout << endl << "You have already written that character! " << m1 << stay+1 << m2 << endl;
        }
        else
        {
            bool check = checker(ch, word, lines, good_count, word_count);
            if (check==false)
            {
                wrong+=1;
                for(int i=0; i<word.length(); i++)
                    cout << lines[i] << " ";
                if(stay==0)
                {
                    cout << endl << "It was your last chance." << endl;
                    break;
                }
                cout << endl << "Wrong. " << m1 << stay << m2 << endl;
            }
            else
                game(ch, stay, good_count, word_count, lines, word);
        }
        write[turn]=ch;
        turn+=1;
        cin.clear();
        cin.ignore(100, '\n');
    }
    ender(word, lines);
    return 0;
}
