/*
* Title: Big Sorting
* Description: Given a list of numbers, including Big Integers of an arbitrary number of digits, sort it in ascending order.
* Author: Vanamala Srikanth
* GitHub: https://github.com/srikanth7785
* Twitter: https://twitter.com/srikanth7785
*/

#include<iostream>
#include<vector>
#include<algorithm> //for sort()
using namespace std;

bool customSorting(string a, string b){
    //below, first two conditions, will check if one of the strings are having a `-ve`..
    // if only first string is `-ve`
    if(a[0] == '-' and b[0] != '-')
        return true;
    // if only second string is `-ve`
    if(a[0] != '-' and b[0] == '-')
        return false;
    //if both are negative
    if(a[0] == '-' and b[0] == '-'){
        if(a.length() == b.length())
            return a > b;
        return a.length() > b.length();
    }
    // below conditions will check only when both are `+ve`
    if(a.length() == b.length()) // if both the strings are of same length
        return a < b; // check if first string is less than the second string
    return a.length() < b.length(); // if both strings are of different length, then the one with smallest length will be the smallest number
}

int main(){
    int n;
    cin >> n;
    vector<string> numbers;//an array can also be used instead
    
    for(int i = 0;i < n; i++)
    {string temp; cin >> temp; numbers.push_back(temp);}
    
    sort(numbers.begin(),numbers.end(),customSorting); // this is an inbuilt method available in `algorithm`. it will call `customSorting()` for each comparision
    
    for(string num : numbers) //finally, print the output, which is sorted.
    cout << num << endl;
}
/*
-------------------------
Sample Input:
26
-29587466846
1
5
-3
999999999999999999999999999
-999999999999999999999999999
56584811425369978558466998629
34183682863148623287364532568384314852
55885698726558891335532227899
55885698726558891335532227897
54181768138176
55885698726558891335532227895
8797879883232132154654
55885698726558891335532227893
987563214569875
55885698726558891335532227890
-854551541265
-2184634134
-245
3242
-8461844655468628
-8461844655468627
6548965813654
-8461844655468622
987456215
-8461844655468625

Sample Output: 

-999999999999999999999999999
-8461844655468628
-8461844655468627
-8461844655468625
-8461844655468622
-854551541265
-29587466846
-2184634134
-245
-3
1
5
3242
987456215
6548965813654
54181768138176
987563214569875
8797879883232132154654
999999999999999999999999999
55885698726558891335532227890
55885698726558891335532227893
55885698726558891335532227895
55885698726558891335532227897
55885698726558891335532227899
56584811425369978558466998629
34183682863148623287364532568384314852

*/
