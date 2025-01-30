//find the index of first ocuurence in a string
//leetcode 28
// basically we need to find the first occurence of needle  string in the haystack string
#include<iostream>
#include<string>
using namespace std;
int strstr(string s, string target){
    if(s.length()<target.length()){
        return -1;
    }
    for(int i=0;i<s.length()-target.length();i++){
        if(s.substr(i,target.length())==target){
            return i;
        }
    }
    return -1;
}
int main(){
    string s;
    string target;
    cin>>s;
    cin>>target;
    int result=strstr(s,target);
    cout<<result<<endl;
}