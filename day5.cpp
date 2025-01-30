//31 findinding next lexicographly greater permutation


//firstly find the break point: means first index i from the back of the given array where arr[i] becommes smaller than arr[i+1].
//if such a break point does not exist  we will reverse the whole array and will return it as our answer.
// if break point exist:
// find the smallest number i.e>arr[i] in the right half of index  (i+1,n-1 ) swap it with arr[i].
//reverse the entire right half.

#include <iostream>
#include <vector>
#include <algorithm> // For reverse and swap
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int breakpoint = -1;

    // Step 1: Find the breakpoint
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            breakpoint = i;
            break;
        }
    }

    // Step 2: If no breakpoint exists, reverse the entire array
    if (breakpoint == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find the next greater element to nums[breakpoint] in the right half
    for (int i = n - 1; i > breakpoint; i--) {
        if (nums[i] > nums[breakpoint]) {
            swap(nums[i], nums[breakpoint]);
            break;
        }
    }

    // Step 4: Reverse the right half after the breakpoint
    reverse(nums.begin() + breakpoint + 1, nums.end());
}

int main() {
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};

    // Call nextPermutation function to modify the array
    nextPermutation(A);

    // Print the result
    cout << "The sorted array is: [";
    for (auto it : A) {
        cout << it << " ";
    }
    cout << "]\n";
    return 0;
}
