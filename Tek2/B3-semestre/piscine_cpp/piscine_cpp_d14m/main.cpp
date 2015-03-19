#include "Lemon.h"
#include "Banana.h"
#include "Fruit.h"

int main(void)
{
  Lemon l;
  Banana b;

  std::cout << l.getVitamins() << std::endl;
  std::cout << b.getVitamins() << std::endl;
  std::cout << l.getName() << std::endl;
  std::cout << b.getName() << std::endl;

  Fruit& f = l;
  std::cout << f.getVitamins() << std::endl;
  std::cout << f.getName() << std::endl;
  return 1337;
}
