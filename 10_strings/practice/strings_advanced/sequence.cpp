#include <iostream>
#include <string.h>

size_t get_same_symb_cnt(const char* str) {

	size_t cnt = 1;
	while (*str != '\0' && *str == *(str + 1)) {
		++str;
		++cnt;
	}

	return cnt;
}

void resize(char*& str, const char* next_symbols) {
	
	if (str == nullptr) {
		str = new char[strlen(next_symbols) + 1];
		strcpy(str, next_symbols);
		return;
	}

	size_t len = strlen(str);
	size_t more_symb = strlen(next_symbols);
	char* new_str = new char[len + more_symb + 1];
	strcpy(new_str, str);
	strcat(new_str, next_symbols);

	delete[] str;
	str = new_str;
}

char* get_sequence(size_t n) {

	char* result_str = new char[2];
	strcpy(result_str, "1");

	const char* temp_ptr = result_str;
	
	char* temp_str = nullptr;

	char temp[32];

	for (size_t i = 1; i < n; i++) {

		while (*temp_ptr != '\0') {

			size_t symb_cnt = get_same_symb_cnt(temp_ptr);

			temp[0] = '0' + symb_cnt;
			temp[1] = *temp_ptr;
			temp[2] = '\0';

			resize(temp_str, temp);
			temp_ptr += symb_cnt;
		}
		delete[] result_str;
		result_str = new char[strlen(temp_str) + 1];
		strcpy(result_str, temp_str);
		delete[] temp_str;
		temp_str = nullptr;
		temp_ptr = result_str;
	}

	delete[] temp_str;
	return result_str;
}

int main() {

	char* sequence = get_sequence(5);
	
	delete[] sequence;
	return 0;
}
