//169 majority element
//Given an array nums of size n, return the majority element.

//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

#include<iostream>
#include <vector>

using namespace std;
 int majorityElement(vector<int>v){
    int n= v.size();
     for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(v[j]==v[i]){
                count++;
            }
        }
        if(count>n/2){
            return v[i];
        }
     }
     return -1;
 }














int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}


 

