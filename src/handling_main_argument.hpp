#pragma once

#include <string>

using namespace std;

int handling_main_argument(
    int argc,
    char* argv[],
    int* quantity_password,
    int* length_password,
    bool* digit_flag,
    bool* small_symbol_flag,
    bool* large_symbol_flag,
    bool* special_symbol_flag);
    