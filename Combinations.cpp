#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

enum typeOfPassword {DIGITS = 10, LETTERS = 52, SYMBOLS = 32};

string getPassword();
int getAlphabetsize(string password);
unsigned int getNumberOfCombinations(int alphabetSize,int length);
int getBitStrenght(int alphabetSize,int length);

int main(){
    string password;
    int alphabetSize,bitStrenght;
    unsigned int numCombinations;

    password = getPassword();
    alphabetSize = getAlphabetsize(password);
    numCombinations = getNumberOfCombinations(alphabetSize,password.length());
    bitStrenght = getBitStrenght(alphabetSize,password.length());

    system("cls");
    cout << "The password is: " << password << endl;
    cout << "The number of combinations is: " << alphabetSize << "^" << password.length() << " = " << numCombinations << endl;
    cout << "The bit-strenght of the password is: " << bitStrenght << " bits" << endl;
    
    return 0;
}

int getAlphabetsize(string password){
    int alphabetSize = 0;
    bool hasDigits,hasLetters,hasSymbols;
    
    hasDigits = hasLetters = hasSymbols = false;
    for(int i = 0; i < password.length(); i++){
        if(isdigit(password[i]) && !hasDigits){
            alphabetSize += DIGITS;
            hasDigits = !hasDigits;
        }else if(isalpha(password[i]) && !hasLetters){
            alphabetSize += LETTERS;
            hasLetters = !hasLetters;
        }else if(ispunct(password[i]) && !hasSymbols){
            alphabetSize += SYMBOLS;
            hasSymbols = !hasSymbols;
        }
    }

    return(alphabetSize);
}

unsigned int getNumberOfCombinations(int alphabetSize,int length){
    unsigned int numCombinations;

    numCombinations = (int) pow(alphabetSize,length);

    return(numCombinations);
}

int getBitStrenght(int alphabetSize,int length){
    float bitStrenght;

    bitStrenght = log2(pow(alphabetSize,length));

    return((int)bitStrenght);
}

string getPassword(){
    string password;

    cout << "Ingress a password:\n";
    getline(cin,password);

    return password;
}


