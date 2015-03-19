//
// droid.hh for  in /home/somasu_b/rendu/piscine_cpp_d08/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Wed Jan 14 15:38:02 2015 SOMASUNDRAM Barathan
// Last update Thu Jan 15 09:15:44 2015 SOMASUNDRAM Barathan
//

#ifndef DROID_H_
# define DROID_H_

#include <iostream>
#include <string>
#include "droidmemory.hh"

class			Droid
{
  std::string		Id;
  size_t		Energy;
  size_t const		Attack;
  size_t const		Toughness;
  std::string*		Status;
  DroidMemory*		battleData;

public:
  Droid(const std::string s_number);
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
  bool			operator()(std::string const*, size_t);

  DroidMemory*		getBattleData() const;
  void			setBattleData(DroidMemory*);
};

std::ostream&		operator<<(std::ostream& w_exit, Droid const& droid);

#endif /* !DROID_H_ */
