#include <iostream>
#include <vector>

using namespace std;

bool allLetters(string s) {
    vector<bool> checked(255, false);
    for (int i=0; i < int(s.size()); ++i)
        checked[s[i]] = true;
    for (int i='a'; i <= 'z'; ++i)
        if (!checked[i])
            return false;
    return true;
}

bool check_lowercase(string s, int N) {
    int count = 0;
    int check;
    for ( int i = 0; i <= int(s.length());i++ )
    {
        if ( int(islower(s[i])) == 0)
            {check = 0;}
        else
            {check = 1;}
        count = count + check;
    }
    if (count == N)
        {return true;}
    else
        {return false;}
}

bool check_alphabetic(string s, int N) {
    int count = 0;
    int check;
    for ( int i = 0; i <= int(s.length());i++ )
    {
        if ( int(isalpha(s[i])) == 0)
            {check = 0;}
        else
            {check = 1;}
        count = count + check;
    }
    if (count == N)
        {return true;}
    else
        {return false;}
}

string enrypt(string s, string new_alphabet)
{
    string encrypted_string = s;
    string alph = "abcdefghijklmnopqrstuvwxyz";
    for (int j = 0; j < int(s.length()); j++)
    {
        for (int i = 0; i < int(alph.length()); i++)
        {
            if (s[j] == alph[i])
            {
               encrypted_string[j] = new_alphabet[i];
            }
        }


    }

    return encrypted_string;

}


int main()
{
    std::cout << "Enter the encryption key: ";
    string enc_key;
    std::cin >> enc_key;
    int N = 26;
    if (int(enc_key.length()) == N) // 1st check if the length is 26
    {


        if ( check_lowercase(enc_key, N) ) // 2nd check if all the letters are lowercase
        {
            //std::cout << count;
            if (allLetters(enc_key)) // 3d check if all the letters of the alphabet are included
            {
                std::cout << "Enter the text to be encrypted: ";
                string to_be_encrypted;
                std::cin >> to_be_encrypted;
                if (check_lowercase(to_be_encrypted, int(to_be_encrypted.length())) && check_alphabetic(to_be_encrypted, int(to_be_encrypted.length())))
                {
                    std::cout << "Encrypted text: " << enrypt(to_be_encrypted, enc_key) ;
                }
                else
                {
                    std::cout << "Error! The encryption key must contain only lower case characters.";
                    return EXIT_FAILURE;
                }
            }
            else
            {
                std::cout << "Error! The encryption key must contain all alphabets a-z.";
                return EXIT_FAILURE;
            }

        }
        else
        {
            std::cout << "Error! The encryption key must contain only lower case characters.";
            return EXIT_FAILURE;
        }

    }
    else
    {
        std::cout << "Error! The encryption key must contain " << N << " characters.";
        return EXIT_FAILURE;
    }
    return 0;
}
