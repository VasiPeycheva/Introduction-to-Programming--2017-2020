/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   enum_switch.cpp
 * @author Ivan Filipov
 * @date   10.2019
 * @brief  Basic example, showing the usage
 *         of enumerations and transferring control
 *         to one of the several statements,
 *         depending on the value of a condition.
 */

#include <iostream>

// enumerations could be used to "pack"
// related constants
enum weekday {
    MON = 0, // as a general rule: values could be initialized
    TUE,     // but if they aren't - the last value + 1 is passed automatically (TUE = 1)
    WED,     // WED = 2 (TUE + 1), and so on.
    THU,
    FRI,
    SAT,
    SUN
};

int main() {

    int day_num;
    std::cout << "Enter a number (weekday 1-7): ";
    std::cin >> day_num;

    day_num -= 1; // from 1-7 to 0-6
    weekday day = (weekday)day_num;
    std::cout << "The inputted day is: " << std::endl;

    // switch can be used instead of multiple if statements
    switch (day) { // the value here SHOULD be from an integer-like type (aka only numbers -10, 10, 0, 20, etc.)
    case MON: // check if day == MON
        std::cout << "Monday" << std::endl;
        break; // we use "break", to show, that no more cases should be matched
    case TUE:
        std::cout << "Tuesday" << std::endl;
        break;
    case WED:
        std::cout << "Wednesday" << std::endl;
        break;
    case THU:
        std::cout << "Thursday" << std::endl;
        break;
    case FRI:
        std::cout << "Friday" << std::endl;
        break;
    case SAT:
        std::cout << "Saturday" << std::endl;
        break;
    case SUN:
        std::cout << "Sunday" << std::endl;
        break;
    default: // matches all other possible values for (day)
        std::cout << "Invalid day" << std::endl;
    }

    // we can also take advantage of switch cases fall-through-s
    switch (day) {
    case MON: // fall-through (go to the below case)
    case TUE: // down
    case WED: // down
    case THU: // down
    case FRI: // up to here
        std::cout << "Which is part of the weekdays." << std::endl;
        break;
    case SAT:
    case SUN:
        std::cout << "Which is part of the weekend." << std::endl;
        break;
    }

    return 0;
}
