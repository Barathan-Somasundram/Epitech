#include "Exo-1.h"

int main()
{
  t_koala* _LKoala = NewKoala("Legend", 1);
  t_koala* _NLKoala = NewKoala("NotLegend", 0);
  t_cthulhu* _cthulhu = NewCthulhu();

  printf("----Start----\n");
  PrintPower(_cthulhu);
  PrintPower(&_LKoala->m_parent);
  PrintPower(&_NLKoala->m_parent);
  Attack(_cthulhu);
  Attack(&_LKoala->m_parent);
  Attack(&_NLKoala->m_parent);
  Eat(_NLKoala);
  Attack(_cthulhu);
  Sleeping(_cthulhu);
  PrintPower(_cthulhu);
  Attack(&_NLKoala->m_parent);
  return (0);
}
