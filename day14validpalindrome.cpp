

#include <iostream>
#include <string>
#include <cctype> // For tolower()
using namespace std;

// Function to check if a character is alphanumeric
bool isalphanum(char ch) {
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
        return true;
    }
    return false;
}

// Function to check if a string is a palindrome
bool isPalindrome(string s) {
    int start = 0, end = s.length() - 1;

    while (start < end) {
        // Skip non-alphanumeric characters from the start
        if (!isalphanum(s[start])) {
            start++;
            continue;
        }

        // Skip non-alphanumeric characters from the end
        if (!isalphanum(s[end])) {
            end--;
            continue;
        }

        // Compare characters in a case-insensitive manner
        if (tolower(s[start]) != tolower(s[end])) {
            return false;
        }

        // Move pointers inward
        start++;
        end--;
    }

    return true;
}

int main() {
    string input;
    cout << "Enter a string to check if it's a palindrome: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
