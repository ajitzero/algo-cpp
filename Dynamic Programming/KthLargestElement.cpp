/**
 * 
 * Title: Kth Largest Element in an Array
 * Description: Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Author: Ajit Panigrahi
 * GitHub: https://github.com/AjitZero
 * Twitter: https://twitter.com/AjitZero
 * 
 */

#include <iostream>
#include <vector>
#include <priority_queue>

using namespace std;

/**
 * Calculates the kth largest element in array
 * 
 * @param nums [list of integers]
 * @param k    [positional value]
 */
void findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    int N = nums.size();
    for (auto &elem : nums) {
        pq.push(elem);
    }
    k -= 1;
    while (k--) {
        pq.pop();
    }
    cout << pq.top() << endl;
}

// Driver function
int main() {
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
    
    int k;
    cin >> k;
	findKthLargest(input);
	return 0;
}

/*
Sample Input:
--------------------
6
3 2 1 5 6 4
2
Sample Output:
--------------------
5
 */
 
