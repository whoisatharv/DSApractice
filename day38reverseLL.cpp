#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node(int data){
        val=data;
        next=NULL;
    }
};
class Linkedlist{
    publuc:
    Node*head;
    Linkedlist()
    {
        head=NULL;
    }
    //inserting elements in linked list
void insertatTail(int val){
    Node*new_node=new Node(val);
 if(head=NULL){
    head=new_node;
    return;
 }
 Node*temp=head;
 while(temp->next!=NULL){
    temp=temp->next;

 }
 temp->next=new_node;
}
void display(){
    Node*temp=head;
    while(temp!=Null){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}
Node*reverseLL(Node*&head){
    Node*prevptr=Null;
    Node*currptr=head;
    while(currptr!=NULL){
        Node*nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
}
Node*new_head=prevptr;
return new_head;
}
