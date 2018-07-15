/**
 * 
 * Title: Maximum Sum of Non-Empty Subsequence
 * Description: Display the maximum sum of any non-empty subsequence of a given list of integers.
 * Author: Ajit Panigrahi
 * GitHub: https://github.com/AjitZero
 * Twitter: https://twitter.com/AjitZero 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Calculates the maximum sum of all possible subsequences
 * @param  a            [Input integer list]
 * @param  noOfElements [Size of list]
 * @return              [maximum sum result]
 */
int MaximumSubsequenceSum(vector<int> const &a, const int noOfElements) {

	/**
	 * If at least one non-negative number exists,
	 * the maximum subsequence sum is the sum of all non-negative integers
	 */
	int totalSum = 0;
	
	/**
	 * If no non-negative numbers exist, 
	 * the maximum subsequence sum is the largest negative number in the list
	 */
	int largestNumber = a[0];
	
	// Iterating through the list
	for (int i = 0; i < noOfElements; ++i) {
	
		// Calculating largest number for every new element
		if (a[i] > largestNumber) {
			largestNumber = a[i];
		}
	
		// Calculating sum of all positive numbers
		if (a[i] > 0) {
			totalSum += a[i];
		}
	}
	
	// Returns the sum of all positive integers or zero, if at least one non-negative integer exists
	if (largestNumber > 0) {
		return totalSum;
	}
	
	// Returns the largest negative number, if at least no non-negative integer exists
	return largestNumber;
}

// Driver function
int main() {
	int noOfElements;
	cin >> noOfElements;
	vector<int> a(noOfElements);
	for (int i = 0; i < noOfElements; ++i) {
		cin >> a[i];
	}
	cout << MaximumSubsequenceSum(a, noOfElements);
	return 0;
}

/*

Sample Input:
--------------------

7
20 -17 34 11 -5 20 -5 2

Sample Output:
--------------------

85

 */
