#include "ctest.h"
#include <string>

#include "alphabet_generation.hpp"
#include "password_generation.hpp"

CTEST(ALPHABET_GENERATION, ALPHABET_FLAG)
{
    string alphabet = "";
    int len_alphabet = 0;

    ASSERT_EQUAL(1, generation_alphabet(&alphabet, &len_alphabet, false, false, false, false));

    alphabet = "";
    len_alphabet = 0;

    ASSERT_EQUAL(0, generation_alphabet(&alphabet, &len_alphabet, true, true, true, true));
    ASSERT_EQUAL(len_alphabet, 70);
}

CTEST(PASSWORD_GENERATION, EMPTY_POINTER_STRING) {
    string *passwords = nullptr;
    int len_password = 10;
    int numb_passwords = 10;
    string alphabet = "";
    int length_alphabet = 10;
    ASSERT_EQUAL(1, password_generation(passwords, len_password, numb_passwords, alphabet, length_alphabet));
}

CTEST(PASSWORD_GENERATION, CORRECT_DATA) {
    int len_password = 10;
    int numb_passwords = 10;
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyz";
    int length_alphabet = 37;
    string *passwords = nullptr;
    passwords = new string[numb_passwords];
    ASSERT_EQUAL(0, password_generation(passwords, len_password, numb_passwords, alphabet, length_alphabet));
}
