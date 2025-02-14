#include<iostream>
#include<algorithm>
using namespace std;

class TreeNode
{
    int data;
    Node*left;
    Node*right;

    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int diameter(TreeNode*root){
    int diameter=0;
     dfs(root,diameter);
     return diameter;

}

int dfs(TreeNode*root, int &diameter){
    if(root==NULL){
        return 0;

    }
    int leftdepth= dfs(root->left);

    int rightdepth= dfs(root->right);
    int currrdiameter= leftdepth+rightdepth;
     diameter= max(diameter,currdiameter);
     return max(leftdepth,rightdepth)+1;
}
int main(){
    TreeNode*rootNode=new Node(2);
    rootNode->left=new Node(4);
    rootNode->right=new Node(10);
    rootNode->left->left=new Node(6);
    rootNode->left->right=new Node(5);
    rootNode->right->right=new Node(11);
    cout<<diameter(rootNode)<<endl;
    return 0;

}