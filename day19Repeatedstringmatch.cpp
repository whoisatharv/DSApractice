//leetcode 686
//given two string a and b, return the minimum number of times you should repeat string a so that string b is a substring of it.if it si impossible for b to be a substring of a after repeating it.


//Problem analysation=> basically we are given two strings  a  and b  we have to repeat a such a time  such that it becomes b . If there is no possibilities of (a) becoming (b) or if it is impossible for (b) to be a substring of (a) after repeating it.
//solution


// string (b) is such that 
//(b)=prefix +n*string(a) +prfix  =>cd(abcd)ab ==> here we have to add sting a n+2 times
// (b)=prefix +n*string(a)=>cd(abcd) ==> here we have to add string a n+1 time.
//b=n*a+suffix =>(abcd)ab==> here we have to add string a n+1 times .
// b= n*a=> (abcd)==> here we have to add stirng n times.
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int minRepetitions(string a, string b){
    //Lengths of strings
    int lenA=a.size();
    int lenB=b.size();
    //calculate the minimum repetitions required
    int n=ceil((double)lenB/lenA);

    //create a repeated string ntimes
    string repeatedA="";
    for(int i=0;i<n;i++){
        repeatedA+=a;
        //step3 check if b is a substring  after nrepetitions
        if(repeatedA.find(b)!=string::npos)//string::npos is a special constant defined in the std::string class , this checks if the result of find() is not equal to npos, meaning the substring b exist in repeatedA
        return n;//
    }
    //step4  if not found add one more repetitio and found again
    repeatedA+=a;
    if(repeatedA.find(b)!=string::npos){
        return n+1;
    }

    //if not found add one more repetition and check again
     repeatedA+=a;
    if(repeatedA.find(b)!=string::npos){
        return n+2;
    }
    return -1;
}
int main() {
    string a, b;
    cout << "Enter string a: ";
    cin >> a;
    cout << "Enter string b: ";
    cin >> b;

    int result = minRepetitions(a, b);
    if (result == -1) {
        cout << "It's impossible for b to be a substring of repeated a." << endl;
    } else {
        cout << "Minimum repetitions required: " << result << endl;
    }

    return 0;
}