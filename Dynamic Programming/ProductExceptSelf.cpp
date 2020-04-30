/**
 * 
 * Title: Product of Array Except Self
 * Description: Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * Author: Ajit Panigrahi
 * GitHub: https://github.com/AjitZero
 * Twitter: https://twitter.com/AjitZero
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Calculates the product of all elements except the one in position
 * 
 * @param nunms [list of integers]
 */
vector<int> productExceptSelf(vector<int>& nums) {
    int N = nums.size();
    vector<int> results(N, 1);
    for (int i = 0; i < N; ++i) {
        results[i] = nums[i - 1] * results[i - 1];
    }
    int t = 1;
    for (int i = N - 1; i >= 0; --i) {
        results[i] *= t;
        t *= nums[i];
    }
    
    for (auto &elem: results) {
    	cout << elem << ' ';
    }
    cout << endl;
}

// Driver function
int main() {
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	productExceptSelf(input);
	return 0;
}

/*
Sample Input:
--------------------
4
1 2 3 4
Sample Output:
--------------------
24 12 8 6
 */
 
