#include <iostream>
#include <cstdlib>
#include <cmath>
#include "invendus.hpp"

int                 main(int ac, char **av)
{
    if (ac > 2)
    {
        Invendus inv(atoi(av[1]), atoi(av[2]));
	inv.generate_tab_x_y();
	inv.generate_tab_z();
	inv.generate_esp_var();
    }
    else
        std::cout << "Usage => [A > 50] [B > 50]"  << std::endl;
    return (1);
}
