#include <cstdlib>
#include <ctime>

namespace rundom_number {
    int get_rundom_number(int max_value, int level) {
        switch (level) {	
            case 1:
                max_value = 9;
                break;
            case 2:
                max_value = 49;
                break;
            case 3:
                max_value = 99;
                break;	
        }
        std::srand(std::time(nullptr));

        return std::rand() % max_value;
    }
}
