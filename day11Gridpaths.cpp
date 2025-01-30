#include<iostream>
using namespace std;
 int F( int i, int j, int m ,int n){
    if(i==m-1 && j==n-1) return 1;
    if(i>=m || j>=n) return 0;
    else{
        return F(i+1,j,m,n)+F(i,j+1,m,n);
    }
 }
 int main(){
    cout<<F(0,0,2,3);
    return 0;
 }