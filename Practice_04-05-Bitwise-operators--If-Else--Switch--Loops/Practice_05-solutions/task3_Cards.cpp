#include<iostream>

const int CardCount = 52;
const int CardsFromColor = 13;

//valid only for MS  
const char ClubSymbol = 0x05;
const char DiamondSymbol = 0x04;
const char HeartSymbol = 0x03;
const char SpadeSymbol = 0x06;


enum CardColors {

	Clubs  , // = 0
	Diamonds, // = previous + 1
	Hearts,
	Spades

};


int main() {


	unsigned int cardId;

	do {

		std::cout << "which card do you want to see?\n";
		std::cin >> cardId;

		//invalid input
		if (cardId > CardCount - 1) 
		{
			std::cout << "Invalid input!\n"
				<< "Do you want to try again? : y/n \n";

			char choice;

			std::cin >> choice;

			if (choice == 'y')
				continue; //starting the loop from the beginning
			else {
				if (choice == 'n')
					std::cout << "Goodbye!\n";
				else
					std::cout << "again invalid command, maybe we don't speak the same language!\n";

				return 0; //exiting the program
			}

		}

		//if we get here the input is correct 

		unsigned int cardColor = cardId / CardsFromColor; //in [0;3]
		unsigned int cardPicture = cardId % CardsFromColor; //in [0;12]

		std::cout << "the chosen card is : ";


		//plus 1, because it is easier to 'code' the cases
		switch (cardPicture + 1) {

		case 1: std::cout << 'A'; break; //we should use break,bacause
										 //otherwise we will "fall down" 
										//and enter in every other case clause
										//before 'seeing' the next break
		case 2: std::cout << '2'; break;
		
		case 3: std::cout << '3'; break;

		case 4: std::cout << '4'; break;

		case 5: std::cout << '5'; break;

		case 6: std::cout << '6'; break;

		case 7: std::cout << '7'; break;

		case 8: std::cout << '8'; break;

		case 9: std::cout << '9'; break;

		case 10: std::cout << "10"; break;

		case 11: std::cout << 'J'; break;

		case 12: std::cout << 'Q'; break;

		case 13: std::cout << 'K'; break;

		default: std::cout << "is it even possible to get here?";

		}

		//using enumeration makes our own code to be much easier
		//to read and understand
		switch (cardColor){

		case Clubs: std::cout << ClubSymbol; break;

		case Diamonds: std::cout << DiamondSymbol; break;

		case Hearts: std::cout << HeartSymbol; break;

		case Spades: std::cout << SpadeSymbol; break;

		}

		//we have done our job 
		std::cout << '\n';
		break;

	} while (true); //endless loop - the only way to 'exit' the loop is by breaking it or using return 

	
	return 0;
}
