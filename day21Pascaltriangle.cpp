//118Pascal triangle question
//in Pascal triangle problem we can have three problem statements.
//1)(n-1 C r-1)Given Row and Column, find the the element at that point in the pascal triangle.
//2)Print the nth row of the pascal triangle.
//3)given N , print the entire pascal triangle with 6 rows


///printing the pascal triangle
#include<iostream>
#include<vector>
using namespace std;
//firstly we will write the function for generating the row of pascal triangle then generate the full triangle by using this function
vector<int>generateRow(int row){
    long long ans=1;
    vector<int>ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/(col);
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>>pascalTriangle(int N){
      vector<vector<int>>ans;
      for(int i=1;i<=N;i++){
        ans.push_back(generateRow(i));
      }
      return ans;
}
int main() {
    int N;
    cout << "Give number of rows to make Pascal's Triangle: " << endl;
    cin >> N;

    // Generate the triangle
    vector<vector<int>> triangle = pascalTriangle(N);

    // Print the triangle
    for (const auto& row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}










