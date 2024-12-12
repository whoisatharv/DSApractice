//Problem121 Best time to buy and sell the stock
#include<iostream>
#include <climits>

#include<math.h>
#include<vector>
using namespace std;

int maxProfit(vector<int>&prices){
    int maxprofit=0;
    int minprice=INT_MAX;
    for(int i=0;i<prices.size();i++){
minprice=min(minprice,prices[i]);
maxprofit=max(maxprofit,prices[i]-minprice);
    }
    return maxprofit;

}

int main() {
    int n;

    // Input the size of the price array
    cout << "Enter the number of days: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of days!" << endl;
        return 0;
    }

    vector<int> prices(n);

    // Input the prices for each day
    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Call the function and display the maximum profit
    int result = maxProfit(prices);
    cout << "The maximum profit is: " << result << endl;

    return 0;
}

