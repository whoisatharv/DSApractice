//leet code hard question Slidingwindow maximum 
//our solution is takes time complexity of of o(n^2)
//for optimized we willl use deque concept 
#include <iostream>
#include<vector>
#include<climits>
using namespace std;


void getMax(vector<int>nums,int l,int r,vector<int>&arr){
    int maxi=INT_MIN;
    for(int i=l;i<=r;i++){
        maxi=max(maxi,nums[i]);
    }
    arr.push_back(maxi);

}

vector<int>maxSlidingWindow(vector<int>&nums,int k){
    int left=0;
    int right=0;
    vector<int>arr;
    while(right<k-1){
        right++;
    }
    while(right<nums.size()){
        getMax(nums,left,right,arr);
        left++;
        right++;
    }
    return arr;
}





int main() {
  int i, j, n, k = 3, x;
  vector < int > arr {
4,0,
-1,
3,
5,
3,
6,
8};
  vector < int > ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << "  ";
  return 0;
}