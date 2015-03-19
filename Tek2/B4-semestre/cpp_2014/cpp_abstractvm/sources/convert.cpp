//
// convert.cpp for  in /home/somasu_b/rendu/cpp_abstractvm/sources
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Feb 21 18:17:48 2015 SOMASUNDRAM Barathan
// Last update Sun Mar  1 16:16:21 2015 SOMASUNDRAM Barathan
//

#include <iostream>

int         my_power(int nb_org, int pow)
{
    int     nb;

    nb = 1;
    for (int i = 0 ; i < pow; i++) {
        nb *= nb_org;
    }
    return (nb);
}

int		my_atoi(char const *value)
{
    int nb = 0;
    int i = 0;

    if (value[0] == '-')
        i++;
    for (i = i; value[i] != '\0' && value[i] != '.'; i++)
        nb = (nb * 10) + (value[i] - 48);
    if (value[0] == '-')
        nb = nb * -1;
    return (nb);
}

double		my_atof(char const *value)
{
    double  nb;
    int a, i, j = 0;

    for (i = 0; value[i] != '\0' && value[i] != '.'; i++);
    a = my_atoi(&value[++i]);
    for (j = 0; value[i] != '\0'; j++, i++);
    nb = (double)my_atoi(value) + ((double)a / my_power(10, j));
    return (nb);
}
