#include "handling_main_argument.hpp"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string.h>

using namespace std;

void outHelp() {
    cout << "Считывание опций выбранных пользователем при вызове генератора паролей." << endl
                <<"pwgen[num_pw][pw_length][OPTION]"<< endl
                << "pw_length - Длина паролей. ОБЯЗАТЕЛЬНЫЙ ПАРАМЕТР." << endl
                << "num_pw - Количество паролей. ОБЯЗАТЕЛЬНЫЙ ПАРАМЕТР." << endl
                << "-s - Использовать специальные символы в пароле."<< endl 
                << "-0 - Использовать цифры в пароле."<< endl
                << "-A - Использовать заглавные буквы в пароле."<< endl
                << "-a - Использовать прописные буквы в пароле."<< endl;
}

int handling_main_argument(
    int argc,
    char* argv[],
    int* quantity_password,
    int* length_password,
    bool* digit_flag,
    bool* small_symbol_flag,
    bool* large_symbol_flag,
    bool* special_symbol_flag)
{
    setlocale (LC_ALL, "ru");
    int i = 1;
    int temp = 0;

    if(argc  == 2 && strcmp(argv[1], "-h") == 0) {
        outHelp();
        return 2;
    }
   
    if (argc < 3) {
        return 1;
    }

    temp = atoi(argv[i]);
    if (temp != 0) {
        *quantity_password = temp;
        i++;
    } else {
        return 1;
    }

    temp = atoi(argv[i]); 
    if (temp != 0) {
        *length_password = temp;
        i++;
    } else {
        return 1;
    }

    if (i == argc) {
        *special_symbol_flag = true;
        *digit_flag = true;
        *large_symbol_flag = true;
        *small_symbol_flag = true;
        return 0;
    }

    for (int j = i; j <= argc; j++)
    {
        if (strcmp(argv[j], "-h") == 0) {
            outHelp();
            i++;
        }

        if (strcmp(argv[j], "-s") == 0) {
            *special_symbol_flag = true;
            i++;
        }        

        if (strcmp(argv[j], "-0") == 0) {
            *digit_flag = true;
            i++;
        }

        if (strcmp(argv[j], "-A") == 0) {
            *large_symbol_flag = true;
            i++;
        }

        if (strcmp(argv[j], "-a")== 0) {
            *small_symbol_flag = true;     
            i++;
        }

        if (i == argc) {
            return 0;
        }
    }
    return 0;
}
