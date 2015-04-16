#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <sys/timeb.h>


#include "hotline.hpp"

Hotline::Hotline() {}

Hotline::~Hotline() {}

int getMilliCount(){
  timeb tb;
  ftime(&tb);
  int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
  return nCount;
}

int getMilliSpan(int nTimeStart){
  int nSpan = getMilliCount() - nTimeStart;
  if(nSpan < 0)
    nSpan += 0x100000 * 1000;
  return nSpan;
}

int         Hotline::setParam(int p1, int p2)
{
    param1 = p1;
    param2 = p2;
    return (1);
}

double	calc_combi(int k, int n)
{
  double ret = 1;
  
  if (k > n)
      return (0);
    for (int i = 1; i <= k; i++)
      {
	ret = ret * n;
	ret = ret / i;
	n--;
      }
    return (ret);
}

int             Hotline::getCombi()
{
  mpz_class   n(param2);
  mpz_class   k(param1);
  mpz_class   ret(1);
  
  if (k > n)
    return (0);
  for (int i = 1; i <= k; i++)
    {
      ret = ret * n;
      ret = ret / i;
      n--;
    }
  std::cout << "combinaison de " << param1 << " parmi " << param2 << " : " << ret << std::endl;
  return (1);
}

int             Hotline::getBin()
{
  double	proba_appel = (param1 / (8.0 * 3600.0));
  double	proba_binom;
  std::ofstream	fd_binomial("data/binomial.test", std::ios::out | std::ios::trunc);
  double	sum = 0;
  double	start;
  double	end;
  
  start = getMilliCount();
  for (int i = 0; i <= 50; i++)
    {
      proba_binom = calc_combi(i, 3500) * std::pow(proba_appel, i) * std::pow((1 - proba_appel), 3500 - i);
      if (i <= 25)
	sum += proba_binom;
      fd_binomial << i << " " << std::fixed << proba_binom << std::endl;
    }
  end = getMilliSpan(start);
  std::cout << "loi binomiale :" << std::endl;
  std::cout << "\t\ttemps de calcul :\t" << std::fixed << end << " ms" << std::endl;
  std::cout << "\t\tprobabilite d’encombrement :\t" << std::setprecision(3) << 100.0 * (1 - sum) << " %" << std::endl;
  fd_binomial.close();
  return (1);
}

int             Hotline::getPoisson()
{
  double	lambda;
  double	proba_poisson;
  std::ofstream	fd_poisson("data/poisson.test", std::ios::out | std::ios::trunc);
  double	sum = 0;
  double	start;
  double	end;

  start = getMilliCount();
  for (int i = 0; i <= 50; i++)
    {
      lambda = (3500.0 / (8.0 * 3600.0)) * (double)param1;
      proba_poisson = std::exp(-lambda) * std::pow(lambda, i);
      for (int j = 1; j <= i; j++)
	proba_poisson /= j;
      if (i <= 25)
	sum += proba_poisson;
      fd_poisson << i << " " << std::fixed << proba_poisson << std::endl;
    }
  end = getMilliSpan(start);
  std::cout << "loi Poisson :" << std::endl;
  std::cout << "\t\ttemps de calcul :\t" << std::fixed << end << " ms" << std::endl;
  std::cout << "\t\tprobabilite d’encombrement :\t" << std::setprecision(3) << 100.0 * (1 - sum) << " %" << std::endl;
  fd_poisson.close();
  return (1);
}

int             main(int ac, char **av)
{
    Hotline     line;

    if (ac == 3 && atoi(av[1]) > 0 && atoi(av[2]) > 0)
    {
        line.setParam(atoi(av[1]), atoi(av[2]));
        line.getCombi();
    }
    else if (ac == 2 && atoi(av[1]) > 0 && atoi(av[1]) <= (3600 * 8))
    {
        line.setParam(atoi(av[1]), 0);
        line.getBin();
        line.getPoisson();
	std::cout << "Press Enter to exit" << std::endl;
	system("gnuplot 203hotline.cmd");
    }
    else
    {
        std::cout << "usage : ./203hotline 0 < [k] < [n]" << std::endl;
        std::cout << "usage : ./203hotline 0 < [Durée] < " << 3600 * 8 << std::endl;
    }
}
