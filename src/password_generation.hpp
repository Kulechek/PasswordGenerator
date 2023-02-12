#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int password_generation(string* passwords, int len_password, int numb_passwords, string* alphabet, int length_alphabet);
void print_passwords(string* passwords, int len_password, int numb_passwords);
