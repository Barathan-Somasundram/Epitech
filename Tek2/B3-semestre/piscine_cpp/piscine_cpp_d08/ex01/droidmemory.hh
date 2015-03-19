//
// droidmemory.hh for  in /home/somasu_b/rendu/piscine_cpp_d08/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Jan 15 01:09:48 2015 SOMASUNDRAM Barathan
// Last update Thu Jan 15 02:22:58 2015 SOMASUNDRAM Barathan
//

#ifndef DROIDMEMORY_H_
# define DROIDMEMORY_H_

#include <iostream>
#include <string>

class				DroidMemory
{
  size_t			FingerPrint;
  size_t			Exp;

public:
  DroidMemory();
  ~DroidMemory();

  size_t			getFingerPrint() const;
  size_t			getExp() const;
  void				setFingerPrint(size_t);
  void				setExp(size_t);

  DroidMemory&			operator<<(DroidMemory const&);
  DroidMemory&			operator>>(DroidMemory&) const;
  DroidMemory&			operator+=(DroidMemory const&);
  DroidMemory&			operator+(DroidMemory const&) const;
  DroidMemory&			operator+=(size_t);
  DroidMemory&			operator+(size_t) const;
};

std::ostream& operator<<(std::ostream&, DroidMemory const&);

#endif /* !DROIDMEMORY_H_ */
