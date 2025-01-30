// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.
///solution 

//Now, we know the summation of the first N numbers is:

//Sn = (N*(N+1))/2
//Let’s say, S = the summation of all the elements in the given array.

//Therefore, S - Sn = X - Y…………………equation 1
//Step 2: Form equation 2:

//Now, we know the summation of squares of the first N numbers is:

//S2n = (N*(N+1)*(2N+1))/6
//Let’s say, S2 = the summation of squares of all the elements in the given array.

//Therefore, S2-S2n = X2-Y2...................equation 2
//From equation 2 we can conclude,

//X+Y = (S2 - S2n) / (X-Y) [From equation 1, we get the value X-Y] ………… equation 3
//From equation 1 and equation 3, we can easily find the value of X and Y. And this is what we want.

//Note: Here, we are summing all the numbers and squares of all the numbers, so we should use a bigger data type(Like in C++, long long instead of int).

//Approach:
//Assume the repeating number to be X and the missing number to be Y.

//The steps are as follows:

//First, find out the values of S and Sn and then calculate S - Sn (Using the above formulas).
//Then, find out the values of S2 and S2n and then calculate S2 - S2n.
//After performing steps 1 and 2, we will be having the values of X + Y and X - Y. Now, by substitution of values, we can easily find the values of X and Y.
#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> &a) {
    long long n = a.size();
    
    // Expected sum and sum of squares for numbers 1 to n
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Actual sum and sum of squares in the array
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    // Calculate differences
    long long diff = S - SN;            // X - Y
    long long sum = (S2 - S2N) / diff; // X + Y

    // Solve for X (repeating) and Y (missing)
    long long x = (diff + sum) / 2; // Repeating number
    long long y = x - diff;         // Missing number

    return {(int)x, (int)y};
}

int main() {
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}
