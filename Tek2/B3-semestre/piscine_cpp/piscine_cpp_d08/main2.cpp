#include "droid.hh"
#include "droidmemory.hh"

int main()
{
  DroidMemory dm;
  DroidMemory dn;
  DroidMemory dg;
  dm += 42;
  DroidMemory dn1 = dm;
  std::cout << dm << std::endl;
  //std::cout << dn << std::endl;
  dn << dm;//0+42
  //std::cout << dn << std::endl;
  dn >> dm;//42+42
  dn << dm;//84+42
  std::cout << dn << std::endl;
  std::cout << dm << std::endl;
  dg = dm + dn1;
}



