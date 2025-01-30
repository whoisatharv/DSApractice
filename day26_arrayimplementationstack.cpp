//array implementation of stack
#include<iostream>
using namespace std;
class Stack{

    int capacity;
    int*arr;
    int top;

    public:
    Stack(int c){
        //constructor
 this->capacity=c;
 arr=new int[c];
 this->top=-1;
    }
};


//function to push
void push(int data){
    if(this->top==this->capacity-1){
        cout<<"overflow"<<endl;
        return;
    }
    this->top++;
    this->arr[this->top]=data;
};
//function to pop
int pop(){
    if(this->top==-1){
        cout<<"underflow"<<endl;
        return -1;
    }
    this->top--;
}
int gettop(){
    if (thid->top==-1){
        cout<<"underflow"<<endl;
        return -1;
    }
    return this->arr[this->top];
}
bool isempty(){
    return this->top==-1;

}
bool isFull(){
  return this->top==this->capacity-1;
}


int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<"\n";
    st.push(4);
    st.push(5);
    cout<<st.top()<<endl;
    st.push(8);
}

