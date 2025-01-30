#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int romanToint(string s){
     int res=0;
  unordered_map<char,int>roman={
       
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
     };
     for(int i=0;i<=s.size()-1;i++)
     {
        if(roman[s[i]]<roman[s[i+1]]){
            res=res-roman[s[i]];
        }
        else{
            res=res+roman[s[i]];
        }
     }
     return res;
}
int main(){
    string s1;
    cout<<"enter the string"<<endl;
    cin>>s1;
    cout<<"roman to integer conversion of the given string is: "<< romanToint(s1)<<endl;
    

}