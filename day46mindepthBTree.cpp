#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*left;
    Node*right;
    Node(int data){
        val=data;
    left=right=NULL;
    }
};
int mindepth(Node*root){
    //base case
    if(root=NULL){
        return 0;
    }
    if(!root->left &&!root->right){
        return 1;

    }
    if(root->left==NULL){
        return 1+ mindepth(root->right);

    }
    if(root->right==NULL){
        return 1+ mindepth(root->left);
        
    }
    return min(mindepth(root->left),mindepth(root->right))+1;

}
int main(){
    Node*rootNode=new Node(2);
    rootNode->left=new Node(4);
    rootNode->right=new Node(10);
    rootNode->left->left=new Node(6);
    rootNode->left->right=new Node(5);
    rootNode->right->right=new Node(11);
    cout<<mindepth(rootNode)<<endl;
    return 0;

}