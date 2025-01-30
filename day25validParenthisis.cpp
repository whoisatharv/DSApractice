//valid parantheese Leetcode
#include<iostream>
using namespace std;
#include<stack>

bool validParanthesis(string s){
    stack <char>st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch=='('|| ch=='{'|| ch=='['){
            st.push(ch);

        } else{
            //closing bracket
            if(st.empty()){
                return false;//no opening bracket to match
            }
          char top=st.top();
           if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) {
                st.pop(); // Matching pair found, pop the top element
            }   else
{
    return false;
}
        }
    
    }
 return st.empty();
}


int main(){
    string s;
    cin>>s;
    cout<< <<endl;
    return 0;

}
