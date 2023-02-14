#include "alphabet_generation.hpp"
#include "password_generation.hpp"
#include "handling_main_argument.hpp"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string* password = nullptr;
    string alphabet;
    int length_alphabet;
    int quantity_password = 10;
    int length_password = 10;
    bool digit_flag = false;
    bool small_symbol_flag = false;
    bool large_symbol_flag = false;
    bool special_symbol_flag = false;
    
    int checkReturn = handling_main_argument(
        argc,
        argv,
        &quantity_password,
        &length_password,
        &digit_flag,
        &small_symbol_flag,
        &large_symbol_flag,
        &special_symbol_flag);

    if(checkReturn == 1) {
        cout << "Error reading arguments. Run the program with the -h flag" << endl;            
        return 0;
    }
    if(checkReturn == 2) {
        return 0;
    }

    password = new string[quantity_password];

    checkReturn = generation_alphabet(
        &alphabet,
        &length_alphabet,
        digit_flag,
        small_symbol_flag,
        large_symbol_flag,
        special_symbol_flag);
    
    if(checkReturn == 1) {
        cout << "Error generation alphabet. Run the program with the -h flag" << endl;
        return 0;
    }


    password_generation(
        password,
        length_password,
        quantity_password,
        alphabet,
        length_alphabet);

    return 0;
}
