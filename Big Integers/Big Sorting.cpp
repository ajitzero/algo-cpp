
#include<iostream>
#include<vector>
#include<algorithm> //for sort()
using namespace std;
bool customSorting(string a, string b){
    if(a.length() == b.length()) // if both the strings are of same length
        return a < b; // check if first string is less than the second string
    return a.length() < b.length(); // if both strings are of different lenth, then the one with smallest length will be the smallest number
}
int main(){
    int n;
    cin >> n;
    vector<string> s;//an array can also be used instead
    for(int i = 0;i < n; i++)
    {string a; cin >> a; s.push_back(a);}
    sort(s.begin(),s.end(),customSorting); // this is an inbuilt method available in `algorithm`. it will call `customSorting()` for each comparision
    for(string i : s) //finally, print the output, which is sorted.
    cout << i << endl;
}
/*
-------------------------
Sample Input: 
6
31415926535897932384626433832795
1
3
10
3
5

Sample Output:
1
3
3
5
10
31415926535897932384626433832795
*/
