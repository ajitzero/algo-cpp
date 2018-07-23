/**
 * 
 * Title: Quick Sort
 * Description: Perform Quick Sort algorithm on a given list of numbers.
 * Author: Ajit Panigrahi
 * GitHub: https://github.com/AjitZero
 * Twitter: https://twitter.com/AjitZero
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Partitions the list in the given range with a selected element as pivot and places all elements smaller than the pivot to its left and the rest to the right of pivot
 * 
 * @param  v    [List of values]
 * @param  low  [Lower bound limit]
 * @param  high [Upper bound limit]
 * @return      [Finalised sorted position]
 */
int partition (vector<int>& v, int low, int high) {

	// Choosing pivot as last element
	int pivot = v[high];

	// Index of smaller element
	int i = low - 1;

	// Check all elements in range with pivot
	for (int j = low; j <= high - 1; ++j) {

		// If current element is smaller than or equal to pivot
		if (v[j] <= pivot) {

			// Increment lower value to switch with pivot
			i++;

			/**
			 * Switch with lower element
			 *
			 * Header file required: `algorithm`
			 */
			swap(v[i], v[j]);
		}
	}

	// Switch with pivot
	swap(v[i + 1], v[high]);

	// Return the fixed pivot position
	return i + 1;
}

/**
 * Driver function for Quick Sort
 * 
 * @param v    [List of values]
 * @param low  [Lower bound limit]
 * @param high [Upper bound limit]
 */
void quickSort(vector<int>& v, int low, int high) {

	// Only for valid ranges
	if (low < high) {

		// v[sortedPosition] is at the right position on partitioning
		int sortedPosition = partition(v, low, high);

		// Separate sorting of sub-list before partition and after partition
		quickSort(v, low, sortedPosition - 1);
		quickSort(v, sortedPosition + 1, high);
	}
}

// Driver function
int main() {
	int noOfElements;
	cin >> noOfElements;
	vector<int> V(noOfElements);

	// Enter `noOfElements` values:
	for (int i = 0; i < noOfElements; ++i)
		cin >> V[i];

	quickSort(V, 0, noOfElements - 1);

	// Sorted values:
	for (int i = 0; i < noOfElements; ++i)
		cout << V[i] << ' ';
	return 0;
}

/*

Sample Input:
--------------------

15
3 44 38 5 47 15 36 26 27 2 46 4 19 50 48

Sample Output:
--------------------

2 3 4 5 15 19 26 27 36 38 44 46 47 48 50 

 */
