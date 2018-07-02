/**
 * 
 * Title: Euclidean algorithm (Recursive & non-recursive approaches)
 * Description: Display the greatest common divisor (GCD) of two numbers.
 * Author: Ajit Panigrahi
 * GitHub: https://github.com/AjitZero
 * 
 */

#include <iostream>
using namespace std;

/**
 * Recursive solution
 * @param  x [first number]
 * @param  y [y number]
 * @return   [GCD of both numbers]
 */
int recursive_approach(int x, int y) {

	if (y == 0) {

		// `x` becomes gcd if `y` becomes zero
		return x;
	}
	else {

		// Otherwise find the GCD of the remainder of `x / y` and `y`
		return recursive_approach(y, x % y);
	}
}

/**
 * Non-recursive solution
 * @param  x [first number]
 * @param  y [y number]
 * @return   [GCD of both numbers]
 */
int non_recursive_approach(int x, int y) {

	// Iterate till y becomes zero
	while (y) {

		// Temporary variable to hold original value of `y`
		int temp = y;

		// Reduce `y` to remainder of `x / y`
		y = x % y;

		// Update `x` with the original value of `y`
		x = temp;
	}

	// `x` becomes gcd if `y` becomes zero
	return x;
}

// Driver function
int main() {
    int first_number, second_number;
    cin >> first_number >> second_number;
	cout << recursive_approach(first_number, second_number) << endl;
	cout << non_recursive_approach(first_number, second_number) << endl;
	return 0;
}