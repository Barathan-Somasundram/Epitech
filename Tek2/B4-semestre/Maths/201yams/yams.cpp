#include <iostream>
#include <iomanip>
#include <complex>

#include "yams.hpp"

Yams::Yams()
{
}

Yams::Yams(char **av)
{
    int     nb;

    combi = new std::vector<int>;
    for (int i = 1; i < 6; i++) {
        nb = atoi(av[i]);
        if (nb < 0 || nb > 6)
        {
            std::cout << "Value of dice mut be between 0 and 6" << std::endl;
            exit(0);
        }
        this->combi->push_back(nb);
    }
    recup_arg(std::string(av[6]));
}

void Yams::recup_arg(std::string param) {
    int pos;
    std::string tmp;

    pos = (int)param.find('_', 0);
    if (pos == (int)std::string::npos || pos + 1 == (int)param.size()) {
        std::cout << "Bad parameter => " << param << std::endl;
        exit(0);
    }
    tmp = param;
    tmp.resize(pos);
    if (tmp == "paire")
        this->type = paire;
    else if (tmp == "brelan")
        this->type = brelan;
    else if (tmp == "carre")
        this->type = carre;
    else if (tmp == "full")
        this->type = full;
    else if (tmp == "suite")
        this->type = suite;
    else if (tmp == "yams")
        this->type = yams;
    else {
        std::cout << "Bad parameter => " << tmp << std::endl;
        exit(0);
    }
    param.erase(0, pos + 1);
    tmp = param;
    pos = tmp.find('_', 0);
    if (pos + 1 == (int)tmp.size())
    {
        std::cout << "Bad parameter => " << tmp << std::endl;
        exit(0);
    }
    if (pos != (int)std::string::npos) {
        tmp.resize(pos);
        this->param1 = stoi(tmp, 0, 10);
        param.erase(0, pos + 1);
        this->param2 = std::stoi(param, 0, 10);
        const char *val[] = {"paire, brelan", "carre", "full", "suite", "yams"};
        if (this->param1 <= 0 || this->param1 > 6 || this->param2 <= 0 || this->param2 > 6)
        {
            std::cout << "Error value of " << val[this->type] << " must be between 1 and 6" << std::endl;
            exit(0);
        }
        if (this->param1 == this->param2)
        {
            std::cout << "Error parameters of " << val[this->type] << " can't to be equal" << std::endl;
            exit(0);
        }
    }
    else {
      this->param1 = std::stoi(param, 0, 10);
        if (this->param1 <= 0 || this->param1 > 6)
        {
            const char *val[] = {"brelan", "carre", "full", "suite", "yams"};
            std::cout << "Error value of " << val[this->type] << " must be between 1 and 6" << std::endl;
            exit(0);
        }
        this->param2 = -1;
    }
}

void                    Yams::calc_proba()
{
    float               value = -1;
    float               tmp = -1;
    std::string         rent = "La combinaison la plus rentable est ";
    std::stringstream   result;

    for (int i = 1; i <= 6; i++) {
        if ((tmp = proba_yams(i)) > value) {
            value = tmp;
            result.str("");
            result << rent << "le Yams de " << i << " avec une probabilité de " << value << " et un score de 50 points";
        }
    }

    for (int i = 6; i >= 5; i--) {
        if ((tmp = proba_suite(i)) > value) {
            value = tmp;
            result.str("");
            if (i == 6)
                result << rent << "la Grande Suite avec une probabilité de " << value << " et un score de 40 points";
            if (i == 5)
                result << rent << "la Petite Suite avec une probabilité de " << value << " et un score de 30 points";
        }
    }

    for (int i = 6; i >= 1; i--) {
        if ((tmp = proba_carre(i)) > value) {
            value = tmp;
            result.str("");
            result << rent << "le Carre de " << i << " avec une probabilité de " << value << " et un score de : " << i * 4 << " + resultat unique";
        }
    }

    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i != j)
            {
                if ((tmp = proba_full(i, j)) > value) {
                    value = tmp;
                    result.str("");
                    result << rent << "le Full de " << i << " par " << j << " avec une probabilité de " << value << " et un score de 25 points";
                }
            }
        }
    }

    for (int i = 6; i >= 1; i--) {
        if ((tmp = proba_brelan(i)) > value) {
            value = tmp;
            result.str("");
            result << rent << "le Brelan " << i << " avec une probabilité de " << value << " et un score de " << i * 3 << " + resultats unique";
        }
    }

    for (int i = 6; i >= 1; i--) {
        if ((tmp = proba_paire(i)) > value) {
            value = tmp;
            result.str("");
            result << rent << "la Paire " << i << " avec une probabilité de " << value << " et un score de " << i * 2 << " + resultats unique";
        }
    }

    std::cout << result.str() << std::endl;

    switch (this->type)
    {
        case paire:
            value = proba_paire(param1);
            std::cout << "probabilité d’obtenir une paire de " << param1 << " : " << std::setprecision(5) << value << "%" << std::endl;
            break;
        case brelan:
            value = proba_brelan(param1);
            std::cout << "probabilité d’obtenir un brelan de " << param1 << " : " << std::setprecision(5) << value << "%" << std::endl;
            break;
        case carre:
            value = proba_carre(param1);
            std::cout << "probabilité d’obtenir un carré de " << param1 << " : " << std::setprecision(5) << value << "%" << std::endl;
            break;
        case full:
            value = proba_full(param1, param2);
            std::cout << "probabilité d’obtenir un full de " << param1 << " par les " << param2 << " : " << std::setprecision(5) << value << "%" << std::endl;
            break;
        case suite:
            value = proba_suite(param1);
            if (param1 == 5)
                std::cout << "probabilité d’obtenir une petite suite : " << std::setprecision(5) << value <<"%" << std::endl;
            if (param1 == 6)
                std::cout << "probabilité d’obtenir une grande suite : " << std::setprecision(5) << value <<"%" << std::endl;
            break;
        case yams:
            value = proba_yams(param1);
            std::cout << "probabilité d’obtenir un yams de " << param1 << " : " << std::setprecision(5) << value << "%" << std::endl;
            break;
    }
}

int                     factoriel(int nb)
{
    int                 value = 1;

    for (int i = 1; i <= nb; i++)
        value = value * i;
    return (value);
}

float                   combi_proba(int k, int n)
{
    float               value;

    value = factoriel(n) / (factoriel(k) * factoriel((n - k)));
    return (value);
}

float                    Yams::proba_paire(int param)
{
    float                           value = 0.0;

    find = new std::vector<int>;
    for (int i = 0; i < 2; i++)
        find->push_back(param);
    recup_dice();
    for (int i = (int)find->size(); i <= size; i++)
        value += combi_proba(i, size) * (1 / std::pow(6, i)) * (std::pow(5, size - i) / std::pow(6, size - i));
    value *= 100.0;
    return (value);
}

float                    Yams::proba_brelan(int param)
{
    float                           value = 0.0;

    find = new std::vector<int>;
    for (int i = 0; i < 3; i++)
        find->push_back(param);
    recup_dice();
    for (int i = (int)find->size(); i <= size; i++)
        value += combi_proba(i, size) * (1 / std::pow(6, i)) * (std::pow(5, size - i) / std::pow(6, size - i));
    value *= 100.0;
    return (value);
}

float                    Yams::proba_carre(int param)
{
    float                           value = 0.0;

    find = new std::vector<int>;
    for (int i = 0; i < 4; i++)
        find->push_back(param);
    recup_dice();
    for (int i = (int)find->size(); i <= size; i++)
        value += combi_proba(i, size) * (1 / std::pow(6, i)) * (std::pow(5, size - i) / std::pow(6, size - i));
    value *= 100.0;
    return (value);
}

float                    Yams::proba_full(int param, int param02)
{
    float                           value;

    find = new std::vector<int>;
    for (int i = 0; i < 3; i++)
        find->push_back(param);
    for (int i = 0; i < 2; i++)
        find->push_back(param02);
    recup_dice();
    value = (1 / std::pow(6, size)) * 100;
    return (value);
}

float                    Yams::proba_suite(int param)
{
    float                value;
    int                  i = 0;

    find = new std::vector<int>;
    if (param < 5) {
        std::cout << "Parameter for suite must be 5 or 6" << std::endl;
        return -1;
    }
    if (param == 5) {
        i = 1;
        while (i <= 5)
            find->push_back(i++);
    }
    if (param == 6) {
        i = 2;
        while (i <= 6)
            find->push_back(i++);
    }
    recup_dice();
    value = (1 / std::pow(6, size)) * 100;
    return (value);
}

float                                Yams::proba_yams(int param)
{
    float                           value = 0;

    find = new std::vector<int>;
    for (int i = 0; i < 5; i++)
        find->push_back(param);
    recup_dice();
    for (int i = (int)find->size(); i <= size; i++)
        value += combi_proba(i, size) * (1 / std::pow(6, i)) * (std::pow(5, size - i) / std::pow(6, size - i));
    value *= 100.0;
    return (value);
}

void                                  Yams::recup_dice()
{
    int                               in;

    size = (int)combi->size();
    for (std::vector<int>::iterator it = combi->begin(); combi->size() > 0 && it != combi->end(); it++)
    {
        in = 1;
        for (std::vector<int>::iterator jt = find->begin(); in == 1 && find->size() > 0 && jt != find->end(); jt++)
        {
            if (*it == *jt)
            {
                in = 0;
                find->erase(jt);
                size--;
                if (find->size() == 0 || combi->size() == 0) {
                    return;
                }
            }
        }
    }
    return;
}

Yams::~Yams()
{

}