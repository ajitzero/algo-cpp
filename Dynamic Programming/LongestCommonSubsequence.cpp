/**
 * 
 * Title: Longest Common Subsequence (LCS)
 * Description: Display the length of the longest common subsequence (LCS) between two strings and then display the LCS.
 * Author: Ajit Panigrahi
 * GitHub: https://github.com/AjitZero
 * Twitter: https://twitter.com/AjitZero
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Calculates the length of the longest common subsequence between two strings and displays it
 * 
 * @param firstString  [first string]
 * @param secondString [second string]
 */
void LongestCommonSubsequence(string const &firstString, string const &secondString) {

	int M = firstString.length(), N = secondString.length();

	// `memo` is a two-dimensional vector used for memoization, with `M + 1` rows and `N + 1` columns
	vector<vector<int> > memo(M + 1, vector<int>(N + 1));

	// Bottom-Down Approach, Length calculation
	for (int i = 0; i <= M; ++i) {
		for (int j = 0; j <= N; ++j) {

			// Initializing first row and column to `0`
			if (i == 0 || j == 0) {
				memo[i][j] = 0;
			}

			else {

				// If common character is found, increment value in `memo`
				if (firstString[i - 1] == secondString[j - 1]) {
					memo[i][j] = memo[i - 1][j - 1] + 1;
				}

				// Otherwise, update value in `memo` with previous maximum length
				else {
					memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
				}
			}
		}
	}

	// Last element in `memo` is the calculated length of LCS
	int lengthOfLCS = memo[M][N];
	
	// Preparing resultant LCS
	string resultantLCS = "\0";

	// Starting from the last row and last column corner element, update `resultantLCS`
	int i = M, j = N;
	while (i > 0 && j > 0) {

		// If current character in `firstString` and `secondString` are same, then it is part of `resultantLCS`
		if (firstString[i - 1] == secondString[j - 1]) {

			// Put current character in result by prepending to `resultantLCS`
			resultantLCS = firstString[i - 1] + resultantLCS;

			// reduce values of i and j
			--i; --j;
		}
		else {

			// If they are not same, then find the larger of two and go in the direction of larger value
			if (memo[i - 1][j] > memo[i][j - 1]) {

				// Go left
				--i;
			}
			else {

				// Go up
				--j;
			}
		}
	}

	// Final output
	cout << "Length of LCS: " << lengthOfLCS << endl;
	cout << "Resultant LCS: " << resultantLCS << endl;
}

// Driver function
int main() {
	string firstString, secondString;
	cin >> firstString >> secondString;
	LongestCommonSubsequence(firstString, secondString);
	return 0;
}

/*

Sample Input:
--------------------

SAFOWAQMNXQOA
ESPOFNSSXAOQA

Sample Output:
--------------------

Length of LCS: 6
Resultant LCS: SONXOA

 */
