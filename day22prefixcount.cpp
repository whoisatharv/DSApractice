//leet code 2185//counting words with a given prefix 
//you  are given an array of strings in words that contain as a prefix.
 //aprefix of a string s is any leading contiguous subtring  of s.
 //input: words=
// words ["pay ","attention","practice","attendance"] pref="at"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int prefixCount(vector<string>& words, string pref) {
    int count = 0;
    int v = pref.length();
    for (string word : words) {
        if (word.length() >= v && word.substr(0, v) == pref) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<string> words = {"apple", "application", "apex", "banana", "appetizer"};
    string prefix = "app";
    int result = prefixCount(words, prefix);

    cout << "The number of words starting with '" << prefix << "' is: " << result << endl;

    return 0;
}
