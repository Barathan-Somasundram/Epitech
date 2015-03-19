#include "Ratatouille.h"

int main()
{
  Ratatouille rata;
  rata.addSauce("Tomato").addCondiment(42).addSpice(123.321);
  rata.addVegetable('x');
  std::cout << "We taste: " << rata.kooc() << std::endl;
  rata.addSauce("Bolognese");
  rata.addSpice(3.14);
  std::cout << "C'mon, taste that: " << rata.kooc() << std::endl;
  // C'mon, gimme your pot, i'll just take a bit of it and try something else
  Ratatouille glurp(rata);
  glurp.addVegetable('p');
  glurp.addVegetable('o');
  glurp.addSauce("Tartar");
  std::cout << "And now: " << glurp.kooc() << std::endl;
  // Looks good ...
  rata = glurp;
  std::cout << "I'll taste again, it's sooo good: " << rata.kooc() << std::endl;
  return 0;
}
