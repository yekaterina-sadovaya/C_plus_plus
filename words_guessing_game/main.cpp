#include <iostream>
#include <string>

using namespace std;



void clean_screen() {
    // Cleaning screen by printing 100 empty lines.
    for ( int i = 0; i < 100; ++i ) {
        cout << endl;
    }
}


bool is_word_already_guessed(string secret, string guessed) {
    // Going through all the characters in secret string.
    int count = 0;
    for (int i = 0; i <= int(secret.size()); i++)
    {
        for (int j = 0; j <= int(guessed.size()); j++)
        {
            if (secret[i] == guessed[j])
            {
                count = count + 1;
            }

        }
    }

    if (count == int(secret.length()) + 1 )
    {   return true;}
    else
    { return false;}
}


void print_game_status(string secret, string guessed) {
    // The characters of a string can be gone through also with such a for loop
    // that looks like "for x in y" structure in Python.
    // This is an alternative for the for loop with index variable
    // used in previous function.
    for ( char secret_char: secret ) {
        if ( guessed.find(secret_char) == string::npos ) {
            cout << "_";
        } else {
            cout << secret_char;
        }
    }

    cout << endl;
}


int main() {

    const int MAX_GUESSES = 10;

    // Prints empty lines at the beginning of execution
    void clean_screen();

    // Checks if all the letters include in the list of guessed letters
    bool is_word_already_guessed(string secret, string guessed);

    // Prints string using '_' in the places of letters not guessed
    void print_game_status(string secret, string guessed);

    string secret_word = "";
    cout << "Give a word to be guessed: ";
    getline(cin, secret_word);

    clean_screen();

    string guessed_letters = "";
    int guesses_used = 0;

    while ( not is_word_already_guessed(secret_word, guessed_letters)
              and guesses_used < MAX_GUESSES ) {

        cout << endl
             << "Game status: ";
        print_game_status(secret_word, guessed_letters);

        if ( guessed_letters.size() > 0 ) {
            cout << "You have used " << guesses_used
                 << " guesses!"
                 << endl
                 << "You have guessed letters: " << guessed_letters
                 << endl;
        }

        string guess = "";
        cout << "Guess a letter: ";
        getline(cin, guess);

        if ( guess.size() != 1 ) {
            cout << "You failed: give exactly one letter!"
                 << endl;
            continue;

        } else if ( guessed_letters.find(guess) != string::npos ) {

            cout << "You failed: you had already guessed the letter " << guess << "!"
                 << endl;
            continue;
        }

        guessed_letters += guess;

        if ( secret_word.find(guess) == string::npos ) {
            cout << "Guessed letter does not include the word!" << endl;
        }

        ++guesses_used;
    }

    if ( guesses_used >= MAX_GUESSES ) {
        cout << endl
             << "Guesses expired!"
             << endl;

    }

    if (is_word_already_guessed(secret_word, guessed_letters) && guesses_used < MAX_GUESSES) {

        cout << endl
             << "Right guess. You used " << guesses_used
             << " guesses!"
             << endl;
    }
}
