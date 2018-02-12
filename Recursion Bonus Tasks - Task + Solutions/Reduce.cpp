#include <iostream>
//Нека е дадена цяло неотрицателно число. Да се напише функция reduce,
//която го редуцира до едноцифрено по следната схема:
//Взимат се и се премахват последните 2 цифри , умножават се,
//след което се дели с остатък на 10 и числото което остане се добавя към  
//останалато число
//Пример: 757=> Взимаме 5 и 7  => 5*7=35 =>35%10=5      
//  след като сме взели двете числа остава само 7 и към нея отдясно добавяме("залепяме") 5 =>75
//повторяме стъпките: взимаме 7 и 5 => 7*5=35 => 35%10=5
// вече оставаме без цифри => 0  добавяме 5=> 5 Край
unsigned int reduceEasy(unsigned int num) 
{
	if (num<10)
	{
		return num;
	}
	unsigned short first = num % 10;
	num /= 10;
	unsigned short second = num % 10;
	num /= 10;
	return reduceEasy(num * 10 + (first*second) % 10);
}

//Нека е дадено неотрицателно цяло число n.Напишете функция(reduce n), която го "редуцира" до едноцифрено по следната процедура :
//-намира най - голямата цифра в числото и я "премахва" от него(при повече от едно срещания премахва най - лявата такава цифра)
//- умножава новополученото число по тази премахната цифра и, ако полученото число не е едноцифрено, повтаря процедурата наново за него.
//Нека, например, n = 26364. Най - голямата цифра е 6 и след премахване на първата шестица получаваме 2634.
//Умножаваме 2634 * 6 = 15804, което още не е едноцифрено, така че продължаваме от това число.

unsigned short findMaxDigit(unsigned int num)
{
	unsigned short max = 0;
	while (num>0) {
		if (max<num%10) {
			max = num % 10;
		}
		num /= 10;
	}

	return max;
}

void removeMaxDigit(unsigned int& num,unsigned short max)
{
	char numStr[32];
	itoa(num,numStr,10);
	unsigned int len = strlen(numStr);
	for (int i = 0; i < len; i++)
	{
		if (numStr[i]==('0'+max))
		{
			for (int j= i+1; j <= len; j++)
			{
				numStr[j - 1] = numStr[j];
			}
			break;
		}
	}
	num = atoi(numStr);
}

unsigned int reduceHard(unsigned int num)
{
	if (num<10)
	{
		return num;
	}

	unsigned short maxDig = findMaxDigit(num);
	removeMaxDigit(num,maxDig);
	return reduceHard(num*maxDig);
}

int main()
{
	unsigned int n;
	while (1)
	{
		std::cin >> n;
		std::cout << reduceHard(n) << '\n';
	}
	return 0;
}