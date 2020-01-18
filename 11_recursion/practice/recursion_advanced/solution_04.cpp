/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_04.cpp
  * @author Ivan Filipov
  * @date   01.2020
  * @brief  Solution for recursion task 04 from practice 13.
  */

#include <iostream>

//@{
/** definitions for used and unused numbers */
#define USED true
#define UNUSED false
//@}

/// the power of the set to permute
#define MAXN 4

/// the set we are permuting
int given[MAXN] = { 3, 11, 23, 7};

/// buffer for generating the current permutation
int cur_perm[MAXN];

/// markers for used in current permutation
bool used[MAXN] = { UNUSED, };

/// outputs the current permutation
void print_perm() {

	for (int i = 0; i < MAXN; i++)
        std::cout << cur_perm[i] << ' ';

	std::cout << std::endl;
}

/**
 * @brief Generates permutations recursively.
 * @param[in] i: element on which index we are permuting
 *
 * The following algorithm is implemented:
 * Place each possible element on the first position, then
 * permute the other n - 1 elements on the other positions, using
 * the same strategy.
 */
void perm(int i) {

	if (i >= MAXN) {
		// the bottom of the recursion,
		// when the last element is placed
		print_perm();
		return;
	}

	for (int k = 0; k < MAXN; k++) {
		// trying to use the k-th element of the set
		if (used[k] == UNUSED) {
			used[k] = USED;          // marking it as used
			cur_perm[i] = given[k];  // saving it's value
			perm(i + 1);             // generating the n-1 permutation
			used[k] = UNUSED;        // unmarking after coming back form the recursion call
		}
	}
}

int main() {

	/* run the algorithm stating from the element on index 0*/
	perm(0);

	return 0;
}

