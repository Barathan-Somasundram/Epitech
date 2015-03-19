#include "Character.hh"

int		main()
{
  Character _c("poney", 42);

  _c.TakeDamage(50);
  _c.TakeDamage(200);
  _c.TakeDamage(200);

  Character _d("poney", 42);
  _d.Range = Character::CLOSE;
  _d.Range = Character::RANGE;
  return (0);
}
