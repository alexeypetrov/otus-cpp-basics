#pragma once
#include <string>

namespace high_scores {
    int show_high_scores(const std::string& high_scores_filename);

    int add_high_score(const std::string& high_scores_filename, const std::string& user_name, int attempts_count);

    int show_min_high_scores(const std::string& high_scores_filename);
}
