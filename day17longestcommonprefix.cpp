//leet code 14 Longest common prefix
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

 string LongestCommonPrefix(vector<string>&strs){
sort(strs.begin(), strs.end());
    string s1=strs[0];
    string s2=strs[strs.size()-1];
    string ans=" ";
int i=0;
int j=0;
while(i<s1.size()&& j<s2.size()){
    if(s1[i]==s2[j]){
        ans+=s1[i];
        i++; j++;
    }
    else{
        break;
    }
}return ans;


 }
 int main(){
    vector<string>strs={"flower", "flow", "flight"};
   cout<< LongestCommonPrefix(strs)<<endl;
 }