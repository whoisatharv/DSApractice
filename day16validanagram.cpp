//leetcode242 Valid anagram
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool validAnagram(string s,string t){
    //check the length of the string first
    vector<int>freq(26,0);
    if(s.length()!=t.length()){
        return false;
    }
    // now we will  store the frequency of characters in s and t
    for(int i=0;i<s.length();i++)
    {
        freq[s[i]-'a']++;// increasing frequency of 1st string
        freq[t[i]-'a']--; // decreasing freq of second array.

    }
// check if the frequency of every character is 0
for(int i=0;i<26;i++){
    if(freq[i]!=0){
        return false;
    }
    else{
        return true;
    }
}



}
 int main(){
     string s1,s2;
     cin>>s1>>s2;
     if(validAnagram(s1,s2)){
        cout<<"string are anagram"<<endl;
     }
     else{
        cout<<"strings are not anagram"<<endl;
        
     }
 }
