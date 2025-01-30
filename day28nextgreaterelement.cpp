//next greater elemnt leet code
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
vector<int>nextGreaterElements(vector<int>& nums){
    int n=nums.size();
    vector<int>nge(n,-1);
    stack<int>st;
    for (int i=n-1;i>=0;i++){
        //pop the elements in the stack which are less then given elemnt in the array
        while(!st.empty()&& st.top()<=nums[i]){
            st.pop();
        }
        //if stack is not empty ,the top element is the next greater elemnt for nums[i]
     if(!st.empty()){
            nge[i]=nums[st.top()];
        }


            //push the current index onto the stack
     st.push(i);

        }
            
return nge;
    
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}