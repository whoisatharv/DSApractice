//leet code 5 longest palindromic substring
//given a string  s return the longest palindromic substring in s.
//time complexity o(n3)
#include<iostream>
#include<string>
using  namespace std;

bool checkPalindrome(string &s, int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;

    }
    return true;
}
string validPalindromeSubstring(string s){
    int n=s.size();
    int starting_index=0;
    int max_len=0;
    for(int i=0;i<n;i++){
        for(int j=i; j<n;j++){
            if(checkPalindrome(s,i,j)){
                if(j-i+1>max_len){
                    max_len=j-i+1;
                    starting_index=i;
                }
            }
        }
    }
    return s.substr(starting_index,max_len);
}
int main() {
    string input;
    cout << "Enter a string to find its longest palindromic substring: ";
    getline(cin,input);

    string result = validPalindromeSubstring(input);

    if (!result.empty()) {
        cout << "The longest palindromic substring is: " << result << endl;
    } else {
        cout << "No palindromic substring found." << endl;
    }

    return 0;
}