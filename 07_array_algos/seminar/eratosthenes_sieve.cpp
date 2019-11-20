/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   eratosthenes_sieve.cpp
 * @author Ivan Filipov
 * @date   11.2019
 * @brief  Example implementation of Eratosthenes algorithm
 *         for finding out prime numbers below N.
 *
 * @see https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */

#include <iostream>

#define PRIME false // all occurrences of "PRIME" will be replaced with false
#define COMPOSITE true
#define MAX_N 20000

// array with markers
// if sieve[i] == PRIME -> the number i is PRIME
// note: that array will be initialized with zeros -> all values will be false (PRIME), because
// the array is placed at the global memory.
bool sieve[MAX_N] = { PRIME, };

// just output all prime numbers
void print_primes() {

	for (unsigned long long int i = 2; i < MAX_N; i++) {
		if (sieve[i] == PRIME) {
			std::cout << i << " is a prime!" << std::endl;
		}
	}
}

// The algorithm's implementation
void eratosthenes_sieve() {

    // for each number
	for (unsigned long long int i = 2; i < MAX_N; i++) {
        // if it is considered PRIME, mark all greater numbers, that are
        // dividable as COMPOSITE numbers
		if (sieve[i] == PRIME) {
			for (unsigned long long int j = i * i; j < MAX_N; j += i) { // the inner loops starts from i squared
		  		sieve[j] = COMPOSITE;
			}
		}
	}

	print_primes();
}

int main() {

	eratosthenes_sieve();
	return 0;
}
