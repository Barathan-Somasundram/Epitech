#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "invendus.hpp"

Invendus::Invendus() {}

Invendus::Invendus(int a, int b) : _param_a(a), _param_b(b) {
  if (a <= 50 || b <= 50)
    {
      std::cout << "Usage : Parameter A and B must be higher than 50" << std::endl;
      std::exit (0);
    }
}

Invendus::~Invendus() {}

float       Invendus::calc_math_proba(int x, int y) {
    float   result;

    result = ((_param_a - x) * (_param_b - y));
    result = result / (((5 * _param_a) - 150) * ((5 * _param_b) - 150));
    return (result);
}

int                     factoriel(int nb)
{
    int                 value = 1;

    for (int i = 1; i <= nb; i++)
        value = value * i;
    return (value);
}


float       Invendus::calc_math_P(int z) {
    float   result = 0.0;

    for (int y = 10; y <= 50; y+= 10)
        for (int x = 10; x <= 50; x += 10)
            if (x + y == z) {
                result += calc_math_proba(x, y);
            }
    return (result);
}

float       Invendus::calc_esp(float *t, int p) {
    float   result = 0.0;

    for (float i = 0.0; i < 5.0; i++)
        result += std::pow((i + 1.0) * 10.0, p) *  t[(int)i];
    return (result);
}

float       Invendus::calc_var(float *t) {
    return (calc_esp(t, 2) - std::pow(calc_esp(t, 1), 2));
}

void        Invendus::generate_tab_x_y() {
    float   sum;
    float   tot;
    float   value;

    std::cout << std::endl << "\t\tX=10\tX=20\tX=30\tX=40\tX=50\tloi de Y" << std::endl;
    tot = 0;
    for (int y = 10; y <= 50; y+= 10)
    {
        sum = 0;
        std::cout << "Y=" << y << "\t";
        for (int x = 10; x <= 50; x+= 10) {
            value = calc_math_proba(x, y);
            sum += value;
            std::cout << "\t" << std::setprecision(3) << std::fixed << value;
        }
        _tab_y[(y / 10) - 1] = sum;
        std::cout << std::resetiosflags(std::ios::fixed) << "\t" << sum << std::endl;
        tot += sum;
    }
    std::cout << "loi de X";
    for (int x = 10; x <= 50; x += 10)
    {
        sum = 0;
        for (int y = 10; y <= 50; y += 10)
            sum += calc_math_proba(x, y);
        _tab_x[(x / 10) - 1] = sum;
        std::cout << "\t" << std::setprecision(3) << std::fixed << sum;
    }
    std::cout << "\t" << std::resetiosflags(std::ios::fixed) << tot << std::endl << std::endl;
    return ;
}

void        Invendus::generate_tab_z() {
    float   value;
    float   sum = 0;

    std::cout << "z\t\t20\t30\t40\t50\t60\t70\t80\t90\t100\ttotal"  << std::endl;
    std::cout << "P(Z=z)\t";
    for (int z = 20; z <= 100; z += 10)
    {
        value = calc_math_P(z);
        sum += value;
        std::cout << "\t" << std::setprecision(3) << std::fixed << value;
    }
    std::cout << "\t" << std::resetiosflags(std::ios::fixed) << sum;
    return ;
}

void        Invendus::generate_esp_var() {
    float   value = 0;
    float   sum_esp;
    float   sum_var;

    std::cout <<  std::endl;
    std::cout <<  std::endl;

    value = calc_esp(_tab_x, 1);
    sum_esp = value;
    std::cout << "espérance de X :\t" << std::setprecision(3) << std::fixed << value << std::endl;
    value = calc_var(_tab_x);
    sum_var = value;
    std::cout << "variance de X :\t\t" << std::setprecision(3) << value << std::endl;
    value = calc_esp(_tab_y, 1);
    sum_esp += value;
    std::cout << "espérance de Y :\t" << std::setprecision(3) << value << std::endl;
    value = calc_var(_tab_y);
    sum_var += value;
    std::cout << "variance de Y :\t\t" << std::setprecision(3) << value << std::endl;
    std::cout << "espérance de Z :\t" << std::setprecision(3) << sum_esp << std::endl;
    std::cout << "variance de Z :\t\t" << std::setprecision(3) << sum_var << std::endl;
    std::cout <<  std::endl;
    return ;
}
