#include "alphabet_generation.hpp"


const string digit_alphabet = "0123456789";
const string small_character = "abcdefghijklmnopqrstuvwxyz";
const string large_character = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string special_symbol = "!@#$^&*?";

int generation_alphabet(
        string* alphabet,
        int* length_alphabet,
        bool take_digit_flag,
        bool take_small_symbol_flag,
        bool take_large_symbol_flag,
        bool take_special_symbol_flag)
{
    if (take_digit_flag) {
        *alphabet += digit_alphabet;
    }
    
    if (take_small_symbol_flag) {
        *alphabet += small_character;
    }

    if (take_large_symbol_flag) {
        *alphabet += large_character;
    }

    if (take_special_symbol_flag) {
        *alphabet += special_symbol;
    }

    *length_alphabet = alphabet->length();

    if (*alphabet == "") {
        *length_alphabet = 0;
        return 1;
    }
    
    return 0;
}
