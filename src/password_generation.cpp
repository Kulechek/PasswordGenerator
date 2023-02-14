#include "password_generation.hpp"

void print_passwords(string* passwords, int numb_passwords) {
    for(int i = 0; i < numb_passwords; i++) {
        cout << passwords[i] << endl;
    }
}

int password_generation(string* passwords, int len_password, int numb_passwords, string alphabet, int length_alphabet) {
    if(passwords == nullptr || len_password <= 0 || length_alphabet <= 0) {
        cout << len_password << " " << length_alphabet << endl;
        return 1;
    }

    srand(time(nullptr));
    for(int i = 0; i < numb_passwords; i++) {
        for(int j = 0; j < len_password; j++) {
            passwords[i] += alphabet[rand() % length_alphabet];
        }
    }

    print_passwords(passwords, numb_passwords);

    return 0;
}
