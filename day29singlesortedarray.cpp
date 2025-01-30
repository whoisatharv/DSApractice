//single element in the sorted array
//(even,odd)->weare in the left side of the array
//(odd,even )->we are in the right side of the array.
#include<iostream>
#include<vector>
using namespace std;
int singleDuplicate(vector<int>&arr){
    int n=arr.size();//size of the array
    //edge cases;
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2])return arr[n-1];

    int low=1, high=n-2;
    while(low<=high){
        int mid=low+(high-low)/2 ;
        //if mid elemnt is the single element
        if(arr[mid]!=arr[mid+1]&& arr[mid]!=arr[mid-1])
        return arr[mid];


        //we are in left(even ,odd)
        if((mid%2==1 &&arr[mid]==arr[mid-1])
        ||(mid%2==0 &&arr[mid]==arr[mid+1])){
            //eliminate the left half;
            low=mid+1;
        }
        //we are in the right
        else{
            high=mid-1;
        }
    }
    return -1
}

nt main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}