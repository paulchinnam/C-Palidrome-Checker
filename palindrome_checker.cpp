#include <iostream>

using namespace std;

// Recursive function declaration
bool isPalindrome(string);

// Main function
int main() {

    string userInput="";

    // Loops until the user enters "*" to exit
    do {

        cout << "Enter a string (numbers allowed, enter '*' to quit): ";

        // Get's the user's input
        getline(cin, userInput);

        if (userInput != "*") {

            // Calls recursive function
            if (isPalindrome(userInput)) {

                // User's input is a palindrome if the function returns True
                cout << "\"" << userInput << "\"" << " is a palindrome." << endl;
            }
            
            else {

                // User's input is not a palindrome if the function returns False
                cout << "\"" << userInput << "\"" << " is not a palindrome." << endl;
            }
        }
    } while (userInput != "*");

    return 0;
}


// Checks if the string is a palindrome
bool isPalindrome(string userInput) {

    // Checks if the string's length is less than or equal to 1
    if (userInput.length() <= 1) {

        // The string is a palindrome if it's length is 1
        return true;
    }

    // Converts the first index of the string to lowercase
    char firstCharacter = tolower(userInput[0]);

    // Converts the last index of the string to lowercase
    char lastCharacter = tolower(userInput[userInput.length() - 1]);

    // Checks if the first and last characters are alphanumeric
    if (isalnum(firstCharacter) && isalnum(lastCharacter)) {

        // Checks if the first and last characters match
        if (firstCharacter != lastCharacter) {

            // Not a palindrome if the first and last characters don't match
            return false;
        }
                                
        else {

            // Checks if the remaining characters in between the first and last characters are palindromic
            return isPalindrome(userInput.substr(1, userInput.length() - 2));
        }
    }
                
    else if (!isalnum(firstCharacter)) {

        // Ignores the first character if it's not alphanumeric
        return isPalindrome(userInput.substr(1, userInput.length()));
    }
    
    else {

        // Ignores the last character if it's not alphanumeric
        return isPalindrome(userInput.substr(0, userInput.length() - 1));
    }
}
