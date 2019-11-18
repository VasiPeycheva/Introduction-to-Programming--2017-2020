/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_08.cpp
  * @author Ivan Filipov
  * @date   11.2019
  * @brief  Solution for task 8 from practice 4.
  */

#include <iostream>

int main() {

    int a1, a2, a3, a4, a;
    int p, q;

    std::cout << "a1 = ";
    std::cin >> a1;

    std::cout << "a2 = ";
    std::cin >> a2;

    std::cout << "a3 = ";
    std::cin >> a3;

    std::cout << "a4 = ";
    std::cin >> a4;

    std::cout << "a = ";
    std::cin >> a;

    std::cout << "Enter lower bound (p): ";
    std::cin >> p;

    std::cout << "Enter upper bound (q): ";
    std::cin >> q;

    if (p >= q) {
        std::cout << "Invalid input." << std::endl;
        return 1;
    }


    std::cout << "Solutions for: " << std::endl
              << a1 << " * x1 + "
              << a2 << " * x2 + "
              << a3 << " * x3 + "
              << a4 << " * x4 = "
              << a  << std::endl;

    std::cout << "in [" << p << ", " << q << "]:" << std::endl;

    for (int x1 = p; x1 <= q; x1++)
        for (int x2 = p; x2 <= q; x2++)
            for (int x3 = p; x3 <= q; x3++)
                for (int x4 = p; x4 <= q; x4++)
                    if (a1 * x1 + a2 * x2 + a3 * x3 + a4 * x4 == a)
                        std::cout << a1 << " * " << x1 << " + "
                                  << a2 << " * " << x2 << " + "
                                  << a3 << " * " << x3 << " + "
                                  << a4 << " * " << x4 << " = "
                                  << a  << std::endl;

	return 0;
}
