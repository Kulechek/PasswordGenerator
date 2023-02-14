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

CTEST(HANDLING_MAIN_ARGUMENT, CHECK_VALUE_FLAG_1)
{
    int quantity_argument = 7;
    const char *argument[] = {"", "5", "3", "", "", "", "", ""};

    int quantity_password = 0;
    int length_password = 0;
    bool digit_flag = true;
    bool small_symbol_flag = true;
    bool large_symbol_flag = true;
    bool special_symbol_flag = true;
    handling_main_argument(
            quantity_argument,
            (char**)argument,
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
}

CTEST(HANDLING_MAIN_ARGUMENT, CHECK_VALUE_FLAG_2)
{
    int quantity_argument = 2;
    const char *argument1[] = {"", "-a", "",""};
    int quantity_password = 0;
    int length_password = 0;
    bool digit_flag = true;
    bool small_symbol_flag = true;
    bool large_symbol_flag = true;
    bool special_symbol_flag = true;
    ASSERT_EQUAL(1, handling_main_argument(
            quantity_argument,
            (char**)argument1,
            &quantity_password,
            &length_password,
            &digit_flag,
            &small_symbol_flag,
            &large_symbol_flag,
            &special_symbol_flag));
    ASSERT_EQUAL(0, quantity_password);

}

CTEST(HANDLING_MAIN_ARGUMENT, CHECK_VALUE_FLAG_3)
{
    int quantity_argument = 7;
    const char *argument2[] = {"", "5", "3", "-a", "-s", "-0", "-A", ""};
    int quantity_password = 0;
    int length_password = 0;
    bool digit_flag = true;
    bool small_symbol_flag = true;
    bool large_symbol_flag = true;
    bool special_symbol_flag = true;
    ASSERT_EQUAL(0, handling_main_argument(
            quantity_argument,
            (char**)argument2,
            &quantity_password,
            &length_password,
            &digit_flag,
            &small_symbol_flag,
            &large_symbol_flag,
            &special_symbol_flag));
    ASSERT_TRUE(digit_flag);
    ASSERT_TRUE(small_symbol_flag);
    ASSERT_TRUE(large_symbol_flag);
    ASSERT_TRUE(special_symbol_flag);
}

CTEST(HANDLING_MAIN_ARGUMENT, CHECK_VALUE_FLAG_4)
{
    int quantity_argument = 7;
    const char *argument2[] = {"", "5", "", "-a", "-s", "-0", "-A", ""};
    int quantity_password = 0;
    int length_password = 0;
    bool digit_flag = true;
    bool small_symbol_flag = true;
    bool large_symbol_flag = true;
    bool special_symbol_flag = true;
    ASSERT_EQUAL(1, handling_main_argument(
            quantity_argument,
            (char**)argument2,
            &quantity_password,
            &length_password,
            &digit_flag,
            &small_symbol_flag,
            &large_symbol_flag,
            &special_symbol_flag));
}

