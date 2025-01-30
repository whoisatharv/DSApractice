//leet code 3 longest substring without repeating characters.
#include <iostream>
#include<vector>
using namespace std;
 int lengthofLongestSubstring(string s){
    vector<int>map(256,-1) ;// act like hasmap
    int left=0;
    int right=0;
    int n=s.size();
    int len=0;
     while(right<n){
        if(map[s[right]]!= -1){
            left=max(map[s[right]]+1,left);// updateing left to avoid repeating character

        } 
        map[s[right]]=right; //update the characters last seeen position
         len =max(len,right-left+1);
         right++;
     }
     return len;
 }
 int main() {
  string str = "aaaabcbbbbbbbb";
  cout << "The length of the longest substring without repeating characters is " << 
  lengthofLongestSubstring(str);
  return 0;
}