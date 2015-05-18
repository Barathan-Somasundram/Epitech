
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include "206.hpp"

int			recup_parameter(const char *param)
{
  int			nb = 0;

  for (int i = 0; param[i] != '\0'; i++)
    {
      if (param[i] < '0' || param[i] > '9')
	return (-1);
      nb = (nb * 10) + (param[i] - '0');
    }
  return (nb);
}

Neutrinos::Neutrinos(char *p1, char *p2, char *p3, char *p4)
{
  if ((_nb_mesure = recup_parameter(p1)) <= 0)
    {
      std::cout << "FR => Mauvaise valeur pour le nombre de mesures relevées" << std::endl;
      std::cout << "DA => Darlig vaerdi for antallet af malingen undersogelse" << std::endl;
      exit (1);
    }
  if ((_moy_arith = recup_parameter(p2)) <= 0)
    {
      std::cout << "FR => Mauvaise valeur pour la moyenne arithmétique" << std::endl;
      std::cout << "DA => Darlig værdi for det aritmetiske gennemsnit" << std::endl;
      exit (1);
    }
  if ((_moy_harmo = recup_parameter(p3)) <= 0)
    {
      std::cout << "FR => Mauvaise valeur pour la moyenne harmonique" << std::endl;
      std::cout << "DA => Darlig vaerdi for harmoniske gennemsnit" << std::endl;
      exit (1);
    }
  if ((_ecar_type = recup_parameter(p4)) <= 0)
    {
      std::cout << "FR => Mauvaise valeur pour l'équart-type" << std::endl;
      std::cout << "DA => Darlig vaerdi for SD" << std::endl;
      exit (1);
    }
}

Neutrinos::~Neutrinos() {}

void				Neutrinos::loop_run()
{
  std::string			value;

  while (value != "ende")
    {
      std::cout << "indtast din vaerdi : ";
      std::cin >> value;
      if (value != "ende")
	exec(value.c_str());
    }
}

void				Neutrinos::reinit_value()
{
  _sum = _moy_arith * _nb_mesure;
  _sum_square = (pow(_ecar_type, 2.0) + pow(_moy_arith, 2.0)) * _nb_mesure;
  return ;
}

int				Neutrinos::exec(const char *mesur)
{
  if ((_new_mesur = recup_parameter(mesur)) <= 0)
    {
      std::cout << "FR => Mauvaise valeur entrée" << std::endl;
      std::cout << "DA => Darlig vaerdi insert" << std::endl;
      return (-1);
    }
  reinit_value();
  calc_nb_mesure();
  calc_moy_arith();
  calc_moy_quadr();
  calc_moy_harmo();
  calc_ecrt_type();
  print_res();
  return (1);
}

void				Neutrinos::calc_nb_mesure()
{
  _nb_mesure++;
  return ;
}

void				Neutrinos::calc_ecrt_type()
{
  double			var;

  var = ((_sum_square + pow(_new_mesur, 2)) / (_nb_mesure)) - pow(_moy_arith, 2);
  _ecar_type = sqrt(var);
  return ;
}

void				Neutrinos::calc_moy_arith()
{
  _moy_arith = (_sum + _new_mesur) / (_nb_mesure);
  return ;
}

void				Neutrinos::calc_moy_quadr()
{
  _moy_quadr = sqrt((_sum_square + pow(_new_mesur, 2.0)) / (_nb_mesure));
  return ;
}

void				Neutrinos::calc_moy_harmo()
{
  _moy_harmo = (_nb_mesure) / ((1.0 / _new_mesur) + ((_nb_mesure - 1.0 ) / _moy_harmo));
  return ;
}

void				Neutrinos::print_res()
{
  std::cout << "\tantal mãlinder :\t\t" << _nb_mesure << std::endl;
  std::cout << "\tstandardafvilgelse :\t\t" << _ecar_type << std::endl;
  std::cout << "\taritmetisk gennemsnit :\t\t" << _moy_arith << std::endl;
  std::cout << "\tkvadratisk gennemsnit :\t\t" << _moy_quadr << std::endl;
  std::cout << "\tharmonisk gennemsnit :\t\t" << _moy_harmo << std::endl << std::endl;
}

int			usage()
{
  std::cout << "FR => Usage : ./206neutrinos [nombre de mesure relevé] [moyenne arithmétique] [moyenne harmonique] [écart-type]" << std::endl;
  std::cout << "DA => Brug : ./206neutrinos [antal malinger] [aritmetiske gennemsnit] [harmoniske middelværdi] [SD]" << std::endl;
  return (-1);
}

int			main(int ac, char **av)
{
  if (ac != 5)
    return (usage());
  Neutrinos		neutri(av[1], av[2], av[3], av[4]);
  neutri.loop_run();
  return (1);
}
