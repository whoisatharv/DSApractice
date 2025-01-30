//Min stack 
#include<iostream>
#include <stack>
using namespace std;
class MinStack{
    stack<pair<int,int>>st;
    public:
    MinStack(){

    }
    void push()
    {
        int min;
        if(st.empty())
        {
            min=x;
        }
        else{
            min= std::min(x,st.top().second)
        }
        st.push({x,min})
    }

    void pop(){
        st.pop();
    }
    int top(){
        return st.top().first;
    }
    int getMin(){
        return st.top().second;
    }
}