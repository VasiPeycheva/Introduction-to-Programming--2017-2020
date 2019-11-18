/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_01.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   11.2019
  * @brief  Solution for task 1 from practice 4.
  */

#include <iostream>
#include <cmath>

int main() {

	unsigned long long a, b;
	unsigned long long sum = 0;

	std::cin >> a >> b;

	if (b <= a) {
		std::cout << "wrong interval" << std::endl;
		return 1;
	}

	// helpers
	unsigned long long sq;
	bool is_prime_current = true;

	// handle 1 and 2, outside the loop
	if (a == 2) {
		sum = 2;
		a++;
	} else if (a == 1) {
		sum = 3;
		a = 3;
	}

	// iterating each number between 'a' and 'b'
	for (unsigned long long i = a; i < b; i++) {
		sq = std::sqrt(i);
		is_prime_current = true;
		// we check if the number is prime
		for (unsigned long long j = 2; j <= sq; j++) {
			if (i % j == 0) {
				is_prime_current = false;
				break; // breaks the nearest loop
			}
		}

		if (is_prime_current)
			sum += i;
	}

	std::cout << "the sum is : " << sum << std::endl;
	return 0;
}
