/**
 * 
 * Title: 0-1 Knapsack Problem
 * Description: Display the maximum value that can be accumulated within a given weight limit.
 * Author: Ajit Panigrahi
 * GitHub: https://github.com/AjitZero
 * Twitter: https://twitter.com/AjitZero
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

/**
 * Calculate the maximum value that can be accumulated within a given weight limit.
 * 
 * @param  values       [List of values]
 * @param  weights      [List of weights]
 * @param  noOfElements [Size of lists]
 * @param  maxCapacity  [Weight limit]
 * @return              [Maximum accumulated value]
 */
ll KnapsackProblem(vector<ll> const &values, vector<ll> const &weights, const ll noOfElements, const ll maxCapacity) {

	// `memo` is a two-dimensional vector used for memoization, with `noOfElements + 1` rows and `maxCapacity + 1` columns
	ll memo[noOfElements + 1][maxCapacity + 1];

	// Bottom-Down Approach
	for (ll i = 0; i <= noOfElements; ++i) {
		for (ll j = 0; j <= maxCapacity; ++j) {

			// Initializing first row and column to `0`
			if (i == 0 || j == 0) {
				memo[i][j] = 0;
			}

			// If weight of the element is less than or equal to the current capacity
			else if (weights[i - 1] <= j) {

				// Take the maximum of the value of this element, or ignore this element
				memo[i][j] = max(values[i - 1] + memo[i - 1][j - weights[i - 1]], memo[i - 1][j]);
			}

			// If weight of the element is more than the capacity, then ignore this element
			else {
				memo[i][j] = memo[i - 1][j];
			}
		}
	}

	// Return last element of `memo` as result
	return memo[noOfElements][maxCapacity];
}

// Driver function
int main() {
	ll noOfElements;
	cin >> noOfElements;
	vector<ll> values(noOfElements), weights(noOfElements);

	// Enter `noOfElements` values:
	for (ll i = 0; i < noOfElements; ++i)
		cin >> values[i];

	// Enter `noOfElements` weights:
	for (ll i = 0; i < noOfElements; ++i)
		cin >> weights[i];

	ll maxCapacity;
	cin >> maxCapacity;

	cout << KnapsackProblem(values, weights, noOfElements, maxCapacity) << endl;
	return 0;
}

/*

Sample Input:
--------------------

5
50 120 110 70 40
5 40 50 20 10
80

Sample Output:
--------------------

280

 */
