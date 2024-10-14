#include <iostream>
#include <fstream>
#include <string>
#include <map>

namespace high_scores {
	void show_high_scores(const std::string& high_scores_filename) {
		std::ifstream file{high_scores_filename, std::fstream::out};
		if (!file.is_open()) {
			std::cerr << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			return;
		}

		std::cout << "High scores table:" << std::endl;
		std::string line;
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
	}

	void add_high_score(const std::string& high_scores_filename, const std::string& user_name, int attempts_count) {

		std::ofstream out_file{high_scores_filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cerr << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return;
		}

		out_file << user_name << ' ' << attempts_count << std::endl;
	}

	void show_min_high_scores(const std::string& high_scores_filename) {

		std::ifstream in_file{high_scores_filename, std::fstream::in};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			return;
		}
		std::map<std::string, int> user_high_scores;
		std::string user_name;
		int high_score;
		while (true) {
			in_file >> user_name;
			in_file >> high_score;
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}
			if (user_high_scores.find(user_name) == user_high_scores.end()
				|| user_high_scores[user_name] > high_score
			) {
				user_high_scores[user_name] = high_score;
			}
		}
		std::cout << "High scores table:" << std::endl;
		for (const auto &[user, high_score] : user_high_scores) {
			std::cout << user << ' ' << high_score << std::endl;
		}
	}
}
