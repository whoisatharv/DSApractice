#include <iostream>
#include <vector>
using namespace std;

vector<int> mergesortedarray(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    int i = n - 1;            // Index for the last valid element in nums1
    int j = m - 1;            // Index for the last element in nums2
    int k = n + m - 1;        // Index for the end of nums1 (size after merging)

    // Merge nums1 and nums2 from the back
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If there are any remaining elements in nums2
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    return nums1; // Return the merged array
}

int main() {
    // Input arrays
    vector<int> A{1, 2, 3, 0, 0, 0}; // nums1 with space for merging
    vector<int> B{2, 5, 6};          // nums2

    int n = 3; // Number of valid elements in A
    int m = 3; // Number of elements in B

    // Call the function
    mergesortedarray(A, n, B, m);

    // Output the merged array
    cout << "The sorted array is: [";
    for (auto it : A) {
        cout << it << " ";
    }
    cout << "]\n";

    return 0;
}
