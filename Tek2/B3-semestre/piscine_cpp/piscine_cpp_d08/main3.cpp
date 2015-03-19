#include "droid.hh"
#include "droidmemory.hh"

int main()
{
  DroidMemory dm;
  DroidMemory dn;
  DroidMemory dg;
  dm += 42;
  DroidMemory dn1  = dm;
  std::cout << dm   << std::endl;
  dn << dm;
  dn >> dm;
  dn << dm;
  std::cout << dn  << std::endl;
  std::cout << dm << std::endl;
  dg = dm + dn1;

  Droid d("rudolf");
  Droid d2("gaston");
  size_t DuraSell = 40;
  d << DuraSell;
  d.setStatus(new std::string("having some reset"));
  d2.setStatus(new std::string("having some reset"));
  if (d2 != d && !(d == d2))
    std::cout << "a droid is a droid, all its matter is what it's doing" << std::endl;
  d(new std::string("take a coffee"), 20);
  std::cout << d << std::endl;
  while (d(new std::string("Patrol around"), 20))
    {
      if (!d(new std::string("Shoot some ennemies"), 50))
	d(new std::string("Run Away"), 20);
      std::cout << d << std::endl;
    }
  std::cout << d << std::endl;
  return (0);
}
