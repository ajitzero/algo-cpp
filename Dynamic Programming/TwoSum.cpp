/**
 * 
 * Title: Two Sum
 * Description: Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * Author: Ajit Panigrahi
 * GitHub: https://github.com/AjitZero
 * Twitter: https://twitter.com/AjitZero
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Finds the required two indices.
 * 
 * @param nums   [list of integers]
 * @param target [specific integer]
 */
void twoSum(vector<int> nums, int target) {
    int N = nums.size();
    vector<int> result(2);
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; i + 1 < N; ++j) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }
    
    cout << result[0] << result[1] << endl;
}

// Driver function
int main() {
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
  int target;
  cin >> target;
	twoSum(input, target);
	return 0;
}

/*
Sample Input:
--------------------
4
2 7 11 15
9
Sample Output:
--------------------
0 1
 */
 
