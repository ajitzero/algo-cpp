/**
 * 
 * Title: Sieve Of Eratosthenes [Value limited]
 * Description: Display all primes numbers up to a given value N as a limiter.
 * Author: Ajit Panigrahi
 * GitHub: https://github.com/AjitZero
 * 
 */

#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

/**
 * Creates and displays all prime numbers less than or equal to N
 * @param N [Upper bound range limiter]
 */
void SieveOfEratosthenes(const int N) {
    
    // Creating a boolean array for memoization
    bool store[N + 1];

    /**
     * Initializes all elements of the array `store` as `true`.
     *
     * Header file required: `cstring`
     * Source: http://en.cppreference.com/w/cpp/string/byte/memset
     */
    memset(store, true, sizeof(store));

    /**
     * Looping through all elements from 2 till N, using the limit as square root of N
     *
     * Source: https://stackoverflow.com/q/5811151/808018
     */
    for (int i = 2; i * i <= N; ++i) {

        // If element is assigned `false` then we have already calculated that it is not prime
        if (store[i]) {

            // At this point `store[i]` has a truth value of `true`
            for (int j = i * 2; j <= N; j += i) {

                // We need to mark each of its multiples as not prime by assigning a truth value of `false` to them
                store[j] = false;
            }
        }
    }

    // Output: Display all indices which store a truth value of `true`
    for (int i = 2; i <= N; ++i) {
        if (store[i]) {
            cout << i << " ";
        }
    }
}

// Driver function
int main() {
    int limit;
    cin >> limit;
    assert(("Limit should be at least 2.", limit >= 2));
    SieveOfEratosthenes(limit);
    return 0;
}
