//all possible ways of presenting a number as a sum of other positive numbers

#include<iostream>

const size_t MAXN = 100;

unsigned int addends[MAXN];

void print(size_t len){


	for (size_t i = 1; i < len; i++)
		std::cout << addends[i] << '+' ;

	std::cout << addends[len] << '\n';

}

void creatSum(unsigned int n, size_t pos){

	if (n == 0){

		print(pos - 1);
		return;
	}

	for (unsigned int k = n; k >= 1; k--){

		addends[pos] = k;

		if (addends[pos] <= addends[pos - 1])
			creatSum(n - k, pos + 1);
	}

}


int main(){

	unsigned int n = 7;

	addends[0] = n + 1;

	creatSum(n, 1);

	return 0;
}
