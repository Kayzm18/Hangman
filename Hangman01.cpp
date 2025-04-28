#include<iostream>
#include<bits/stdc++.h>
#include<random>
#include<ctime>

using namespace std;
void intial(string& secretword, string& displayword, int& attempts, set<char>& Guessedletter);
void Current_word(const string& displayword);
char player(const set<char>& guessedletter);
bool checkwin(const string& secretword, const string& displayword);
void end(const string& secretword, bool won);
void track(set<char>& guessedletter, char guess);
bool update(const string& secretword, string& displayword, char guess);
void playgame();

int main(){
    playgame();
    return 0;
}

char player(const set<char>& guessedletter){
    char guess;
    cout<<"Enter Letter ";
    cin>> guess;
    guess = tolower(guess);

    return guess;
}

void intial(string& secretword, string& displayword, int& attempts, set<char>& Guessedletter){

    secretword = "cheetah";
    attempts = 6;

    displayword = string(secretword.length(), '_');
    Guessedletter.clear();
}

void track(set<char>& guessedletter, char guess){
    guessedletter.insert(guess);
}

bool update(const string& secretword, string& displayword, char guess){
    bool found = false;
    for(size_t i = 0 ; i<secretword.length(); i++){
        if(secretword[i] == guess){
            displayword[i] = guess;
            found = true;
        }

    }
    return found;
}

void Current_word(const string& displayword){
    for(char c : displayword){
        cout << c << " ";
    }
    cout<<endl;
}

bool checkwin(const string& secretword, const string& displayword){
    return secretword == displayword;
}

void end(const string& secretword, bool won){
    if (won){
        cout<<"Congratularions you won. The word was; "<< secretword<< endl;
    }else{
        cout<<"Loser; the word was: "<<secretword<<endl;
    }
}

void playgame(){
    string secretword, displayword;
    int attempts;
    set<char> guessedletter;

    intial( secretword, displayword, attempts, guessedletter);
    while (attempts>0){
        Current_word(displayword);
        char guess = player(guessedletter);
        track(guessedletter, guess);

        if(update(secretword, displayword, guess)){
            cout<<"Correct\n";
            if(checkwin(secretword, displayword)){
                end(secretword, true);
                return;
            }
        }else{
            attempts--;
            cout<<"Wrong!!! attempts left: "<< attempts<<endl;
        }
    }
    end(secretword, false);
}
