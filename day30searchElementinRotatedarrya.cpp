#inclde<iostream>
#include<vector>
using namespace std;
int search(int<vector>&arr,int k){
    int n=arr.size()-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        //if mid is target return mid
        if(arr[mid]==k) return mid;

        //if left part is sorted
        if(arr[low]<arr[mid]){
            if(arr[low]<=k && k<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            //if rigth part is sorted
            if(arr[mid]<=k && k<=arr[high] ){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
    }
    return-1
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}