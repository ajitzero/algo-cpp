/**
 * 
 * Title: Maximum Sum of Non-Empty Contiguous Subsequence [Kadane's Algorithm]
 * Description: Display the maximum sum of any non-empty contiguous subsequence of a given list of integers.
 * Author: Ajit Panigrahi
 * GitHub: https://github.com/AjitZero
 * Twitter: https://twitter.com/AjitZero 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Calculates the maximum sum of all possible contiguous subsequences
 *
 * Source: https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm_(Algorithm_3:_Dynamic_Programming)
 * 
 * @param  a            [Input integer list]
 * @param  noOfElements [Size of list]
 * @return              [maximum sum result]
 */
int MaximumContiguousSubsequenceSum(vector<int> const &a, const int noOfElements) {
	
	// `memo` is the temporary variable used for memoization
	int memo = a[0];

	// `sum` is initialized to the first element in the list as a minimum value
	int sum = memo;
	
	// Iterating through the list starting at index 1
	for (int i = 1; i < noOfElements; ++i) {

		// Store the larger of current index value and the previously largest sum value
		memo = max(a[i], memo + a[i]);

		// Update `sum` if the new `memo` value is larger than the previous sum
		sum = max(sum, memo);
	}

	// Returns the largest calculated sum
	return sum;
}

// Driver function
int main() {
	int noOfElements;
	cin >> noOfElements;
	vector<int> a(noOfElements);
	for (int i = 0; i < noOfElements; ++i) {
		cin >> a[i];
	}
	cout << MaximumContiguousSubsequenceSum(a, noOfElements);
	return 0;
}

/*

Sample Input:
--------------------

7
20 -17 34 11 -5 20 -5 2

Sample Output:
--------------------

63

 */
