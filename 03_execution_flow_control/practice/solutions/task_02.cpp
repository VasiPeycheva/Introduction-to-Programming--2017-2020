/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   task_02.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @date   11.2019
  * @brief  Solution for task 2 from practice 3.
  */

#include <iostream>

// well known facts
const int CARDS_COUNT      = 52;
const int CARDS_FROM_COLOR = 13;

// valid only for MS (tested on MS-VS2017)
#ifdef _WIN32
#define CLUBS_SYMBOL    "\x05"
#define DIAMONDS_SYMBOL "\x04"
#define HEARTS_SYMBOL "\x03"
#define SPADES_SYMBOL "\x06"
#else // on *NIX we can use UNICODE symbols
#define CLUBS_SYMBOL    "\xE2\x99\xA3"
#define DIAMONDS_SYMBOL "\xE2\x99\xA6"
#define HEARTS_SYMBOL "\xE2\x99\xA5"
#define SPADES_SYMBOL "\xE2\x99\xA0"
#endif // _WIN32

enum card_colors {
	CLUBS_CLR,    // = 0
	DIAMONDS_CLR, // = previous + 1
	HEARTS_CLR,
	SPADES_CLR
};

int main() {

	unsigned int card_ind;

	do {

		std::cout << "Which card do you want to see?" << std::endl;
		std::cout << "Enter a value in [0; 51]" << std::endl;
		std::cin >> card_ind;

		// handle invalid input
		if (card_ind > CARDS_COUNT - 1) {
			std::cout << "Invalid input!" << std::endl
				      << "Do you want to try again? - y/n" << std::endl;

			char choice;
			std::cin >> choice;

			if (choice == 'y')
				continue; // starting the loop from the beginning
			else {
				if (choice == 'n')
					std::cout << "Goodbye!" << std::endl;
				else
					std::cout << "Again invalid command, maybe we don't speak the same language?" << std::endl;

				return 1; // exit the program
			}

		}

		// we get here only on correct input

		unsigned int card_color   = card_ind / CARDS_FROM_COLOR; // results in [0;3]
		unsigned int card_picture = card_ind % CARDS_FROM_COLOR; //results  in [0;12]

		std::cout << "The chosen card is:" << std::endl;

		// plus 1, because it is easier to 'code' the cases
		card_picture += 1;
		switch (card_picture) {
		case 1: std::cout << 'A';   break;
		case 10: std::cout << "10"; break;
		case 11: std::cout << 'J';  break;
		case 12: std::cout << 'Q';  break;
		case 13: std::cout << 'K';  break;
		default: // all digits can be handled with a simple trick
		    // we add the decimal value to the '0' ASCII code
		    // the trick works, because '1' is the next symbol after '0'
		    // '2' is '0' plus two and so on.
            std::cout << (char)('0' + card_picture);
		}

		// using the enumeration makes our own code much easier
		// to read and understand
		switch (card_color) {
		case CLUBS_CLR:    std::cout << CLUBS_SYMBOL; break;
		case DIAMONDS_CLR: std::cout << DIAMONDS_SYMBOL; break;
		case HEARTS_CLR:   std::cout << HEARTS_SYMBOL; break;
		case SPADES_CLR:   std::cout << SPADES_SYMBOL; break;
		}

		// we have done our job
		std::cout << std::endl;
		break;

	} while (true); // endless loop - the only way to 'exit' the loop is by breaking it or using return

	return 0;
}
