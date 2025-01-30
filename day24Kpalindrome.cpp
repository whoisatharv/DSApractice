// k palindromes
#include <iostream>
#include <string>
using namespace std;

bool canConstruct(string s, int k) {
    if (k > s.length()) 
        return false; // Cannot form more palindromes than the number of characters
    
    int charCount[26] = {0};
    
    // Count occurrences of each character in the string
    for (char c : s) {
        charCount[c - 'a']++;
    }
    
    int oddCount = 0;
    // Count the number of characters with odd frequencies
    for (int i = 0; i < 26; i++) {
        if (charCount[i] % 2 == 1) 
            oddCount++;
    }
    
    // A string can form k palindromes if oddCount <= k
    return oddCount <= k;
}

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter the number of palindromes to be made from the string: ";
    cin >> k;

    // Output result
    if (canConstruct(s, k)) {
        cout << "Yes, it is possible to form " << k << " palindromic substrings.\n";
    } else {
        cout << "No, it is not possible to form " << k << " palindromic substrings.\n";
    }

    return 0;
}
