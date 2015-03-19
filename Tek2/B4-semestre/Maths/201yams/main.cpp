#include <iostream>
#include <stack>

#include "yams.hpp"

int                     main(int ac, char **av) {
    std::stack<int>     comb;

    if (ac > 6) {
        Yams yams(av);
        yams.calc_proba();
    }
    else
        std::cout << "Usage : ./201yams [dé * 5] [type]" << std::endl;
    return 0;
}