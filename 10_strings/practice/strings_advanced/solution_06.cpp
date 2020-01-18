/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solution_06.cpp
  * @author Ivan Filipov
  * @date   01.2020
  * @brief  Solution for task 6 from advanced_string tasks (practice 11).
  */

#include <iostream>
#include <iomanip>
#include <cstring>

const char* USAGE = R"(
usage: $./pass-encrypt [mode]

where [mode] can be one of:

    - pass-check - the program reads from it's STDIN a password,
                   and tells the users if the password is strong enough.

    - pass-encrypt <plain_text_pass> - the program encrypts it's third
                                       command line argument, using an one-time-pad,
                                       read from STDIN.
    - pass-decrypt <cipher_text_pass> - the program decrypts it's third
                                       command line argument, using an one-time-pad,
                                       read from STDIN.
)";

const size_t MIN_LEN = 12;
const size_t BUFF_SIZE = 1024;

void handle_pass_check() {

    char pass[BUFF_SIZE];
    std::cin >> std::setw(BUFF_SIZE) >> pass;

    size_t len = std::strlen(pass);

    if (len < MIN_LEN) {
        std::cout << "Your password is not long enough!" << std::endl;
        return;
    }

    // bits for markers
    enum {
        AT_LEAST_ONE_LOW_ALPHA = 0x1,
        AT_LEAST_ONE_UP_ALPHA  = 0x2,
        AT_LEAST_ONE_DIGIT     = 0x4,
        AT_LEAST_ONE_SPECIAL   = 0x8,
    };

    unsigned char valid_marker = (
        AT_LEAST_ONE_LOW_ALPHA | AT_LEAST_ONE_UP_ALPHA |
        AT_LEAST_ONE_DIGIT     | AT_LEAST_ONE_SPECIAL
    );

    unsigned char marker = 0;
    for (size_t i = 0; i < len; i++) {
        if (islower(pass[i])) {
            marker |= AT_LEAST_ONE_LOW_ALPHA;
        } else if (isupper(pass[i])) {
            marker |= AT_LEAST_ONE_UP_ALPHA;
        } else if (isdigit(pass[i])) {
            marker |= AT_LEAST_ONE_DIGIT;
        } else {
            marker |= AT_LEAST_ONE_SPECIAL;
        }

        if (marker == valid_marker) {
            std::cout << "Your password seems to be strong!" << std::endl;
            return;
        }
    }

    if (!(marker & AT_LEAST_ONE_LOW_ALPHA)) {
        std::cout << "Your password should contain at least one lowercase alpha!" << std::endl;
    }
    if (!(marker & AT_LEAST_ONE_UP_ALPHA)) {
        std::cout << "Your password should contain at least one uppercase alpha!" << std::endl;
    }
    if (!(marker & AT_LEAST_ONE_DIGIT)) {
        std::cout << "Your password should contain at least one digit!" << std::endl;
    }
    if (!(marker & AT_LEAST_ONE_SPECIAL)) {
        std::cout << "Your password should contain at least one special symbol!" << std::endl;
    }
}

unsigned char* read_one_time_pad(size_t& pad_len) {

    std::cin >> std::setbase(10) >> pad_len;

    unsigned char* pad = new (std::nothrow) unsigned char[pad_len];
    if (!pad) return nullptr;
    unsigned int num;
    for (size_t i = 0; i < pad_len; i++) {
        std::cin >> std::setbase(16) >> num;
        pad[i] = (unsigned char)num;
    }

    return pad;
}

// because ^ (XOR) is used in both encryption and decryption,
// we can have only one handler.
void handle_pass_encrypt_decrypt(const char* pass) {

    size_t pad_len;
    unsigned char* pad = read_one_time_pad(pad_len);

    if (!pad) {
        std::cerr << "Internal error." << std::endl;
        return;
    }

    size_t pass_len = std::strlen(pass);
    if (pad_len < pass_len) {
        std::cerr << "The pad should be longer then the password!" << std::endl;
        delete[] pad;
        return;
    }

    for (size_t i = 0; i < pass_len; i++)
        std::cout << char(pass[i] ^ pad[i]);

    std::cout << std::endl;
    delete[] pad;
}


void exit_on_err() {

    std::cerr << USAGE << std::endl;
    std::exit(1);
}

int main(int argc, const char* argv[]) {

    if (argc < 2) exit_on_err();

    if (std::strcmp(argv[1], "pass-check") == 0) {
        handle_pass_check();
        return 0;
    }

    // for other modes we need an extra command line argument
    if (argc < 3) exit_on_err();

    if ((std::strcmp(argv[1], "pass-encrypt") == 0) ||
        (std::strcmp(argv[1], "pass-decrypt") == 0)) {
        handle_pass_encrypt_decrypt(argv[2]);
        return 0;
    }

    exit_on_err();
	return 0;
}
