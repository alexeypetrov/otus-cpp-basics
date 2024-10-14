#include <iostream>
#include <string>
#include "game.h"
#include "random_number.h"
#include "high_scores.h"

int main(int argc, char** argv) {
	const std::string high_scores_filename = "high_scores.txt";
	int max_number {100};
	int level {0};
	if (argc > 1) {
		if (argc > 3) {
			std::cerr << "Count of arguments is more then one: " << std::endl;
			return -1;
		}
		std::string argument {argv[1]};
		if (argument == "-table") {
			high_scores::show_high_scores(high_scores_filename);
			return 0;
		}
		if (argc == 3) {
			std::string argument_value {argv[2]};
			if (argument == "-max") {
				max_number = std::stoi(argument_value);
				std::cout << "Set max number: " << max_number << std::endl;
			}
			if (argument == "-level") {
				level = std::stoi(argument_value);
				if (level < 1 || level > 3) {
					std::cerr << "Wrong value level argument. It must be: 1, 2 or 3 " << std::endl;
					return -1;
				}
				std::cout << "Set level: " << level << std::endl;
			}
		}
	}
    
    int secret_number = rundom_number::get_rundom_number(max_number, level);

    std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;
	int attempts_count = game::guess_the_number(secret_number);
    
	high_scores::add_high_score(high_scores_filename, user_name, attempts_count);
    high_scores::show_min_high_scores(high_scores_filename);
}
