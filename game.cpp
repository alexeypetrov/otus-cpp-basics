#include <iostream>

namespace game {
    int guess_the_number(int secret_number) {
        int attempts_count = 0;
        int user_number;
        do {
            ++attempts_count;
            std::cin >> user_number;

            if (user_number < secret_number) {
                std::cout << "less than " << user_number << std::endl;
            } else if (user_number > secret_number) {
                std::cout << "greater than " << user_number << std::endl;
            } else {
                std::cout << "you win! attempts = " << attempts_count << std::endl;
                break;
            }

        } while(true);

        return attempts_count;
    }
}
