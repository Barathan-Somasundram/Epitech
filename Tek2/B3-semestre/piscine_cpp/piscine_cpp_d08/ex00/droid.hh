//
// droid.hh for  in /home/somasu_b/rendu/piscine_cpp_d08/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Wed Jan 14 15:38:02 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 14 20:30:56 2015 SOMASUNDRAM Barathan
//

#ifndef DROID_H_
# define DROID_H_

#include <iostream>
#include <string>

class			Droid
{
  std::string		Id;
  size_t		Energy;
  size_t const		Attack;
  size_t const		Toughness;
  std::string*		Status;
public:
  Droid(const std::string s_number = "");
  Droid(Droid const&);
  ~Droid();

  std::string		getId() const;
  size_t		getEnergy() const;
  std::string*		getStatus() const;
  size_t 		getAttack() const;
  size_t 		getToughness() const;
  
  void			setId(const std::string);
  void			setEnergy(const size_t);
  void			setStatus(std::string*);

  Droid&		operator=(Droid const&);
  bool			operator==(Droid const&) const;
  bool			operator!=(Droid const&) const;
  Droid&		operator<<(size_t&);
};

std::ostream&		operator<<(std::ostream& w_exit, Droid const& droid);

#endif /* !DROID_H_ */
