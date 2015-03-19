//
// AWeapon.hh for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:02:08 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 09:07:20 2015 SOMASUNDRAM Barathan
//

#ifndef AWEAPON_H_
# define AWEAPON_H_

class				AWeapon
{
protected:
  std::string			name;
  int				apcost;
  int				damage;

public:
  AWeapon(std::string const& name, int apcost, int damage);
  virtual ~AWeapon();

  std::string const&		getName() const;
  int				getAPCost() const;
  int				getDamage() const;
  virtual void			attack() const;
};

#endif /* !AWEAPON_H_ */
