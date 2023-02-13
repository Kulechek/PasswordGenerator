#include "ctest.h"
#include <string>

#include "alphabet_generation.hpp"
#include "password_generation.hpp"
#include "handling_main_argument.hpp"

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

CTEST(HANDLING_MAIN_ARGUMENT, CHECK_VALUE_FLAG)
{
    int quantity_argument = 7;
    char* argument = new char[quantity_argument];
    argument[1] = '5';
    argument[2] = '3';
    argument[3] = '0';
    argument[4] = '0';
    argument[5] = '0';
    argument[6] = '0';
    int quantity_password = 0;
    int length_password = 0;
    bool digit_flag = true;
    bool small_symbol_flag = true;
    bool large_symbol_flag = true;
    bool special_symbol_flag = true;
    handling_main_argument(
            quantity_argument,
            &argument,
            &quantity_password,
            &length_password,
            &digit_flag,
            &small_symbol_flag,
            &large_symbol_flag,
            &special_symbol_flag);
    ASSERT_EQUAL(5, quantity_password);
    ASSERT_EQUAL(3, length_password);
    ASSERT_TRUE(digit_flag);
    ASSERT_TRUE(small_symbol_flag);
    ASSERT_TRUE(large_symbol_flag);
    ASSERT_TRUE(special_symbol_flag);

    quantity_password = 0;
    argument[1] = 'a';
    ASSERT_EQUAL(1, handling_main_argument(
            quantity_argument,
            &argument,
            &quantity_password,
            &length_password,
            &digit_flag,
            &small_symbol_flag,
            &large_symbol_flag,
            &special_symbol_flag));
    ASSERT_EQUAL(0, quantity_password);

    argument[1] = '5';
    argument[3] = '-a';
    argument[4] = '-s';
    argument[5] = '-0';
    argument[6] = '-A';

    ASSERT_EQUAL(0, handling_main_argument(
            quantity_argument,
            &argument,
            &quantity_password,
            &length_password,
            &digit_flag,
            &small_symbol_flag,
            &large_symbol_flag,
            &special_symbol_flag));
    ASSERT_FALSE(digit_flag);
    ASSERT_FALSE(small_symbol_flag);
    ASSERT_FALSE(large_symbol_flag);
    ASSERT_FALSE(special_symbol_flag);
}
