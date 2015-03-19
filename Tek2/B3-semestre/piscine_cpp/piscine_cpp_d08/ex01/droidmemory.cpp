//
// droidmemory.cpp for  in /home/somasu_b/rendu/piscine_cpp_d08/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Jan 15 01:17:05 2015 SOMASUNDRAM Barathan
// Last update Thu Jan 15 02:26:14 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "droidmemory.hh"

DroidMemory::DroidMemory()
{
  this->Exp = 0;
  this->FingerPrint = random();
}

DroidMemory::~DroidMemory()
{

}

size_t				DroidMemory::getFingerPrint() const
{
  return (this->FingerPrint);
}

size_t				DroidMemory::getExp() const
{
  return (this->Exp);
}

void				DroidMemory::setFingerPrint(size_t fp)
{
  this->FingerPrint = fp;
}

void				DroidMemory::setExp(size_t xp)
{
  this->Exp = xp;
}

DroidMemory&			DroidMemory::operator<<(DroidMemory const& mem1)
{
  this->Exp = this->Exp + mem1.Exp;
  this->FingerPrint = this->FingerPrint ^ mem1.FingerPrint;
  return (*this);
}

DroidMemory&			DroidMemory::operator>>(DroidMemory& mem1) const
{
  mem1.Exp = mem1.Exp + this->Exp;
  mem1.FingerPrint = mem1.FingerPrint ^ this->FingerPrint;
  return (mem1);
}

DroidMemory&			DroidMemory::operator+=(DroidMemory const& mem1)
{
  this->Exp = this->Exp + mem1.Exp;
  this->FingerPrint = this->FingerPrint ^ mem1.FingerPrint; 
  return (*this);
}

DroidMemory&			DroidMemory::operator+(DroidMemory const& mem1) const
{
  DroidMemory			*mem2;

  mem2 = new DroidMemory();
  mem2->Exp = mem1.Exp + this->Exp;
  mem2->FingerPrint = mem1.FingerPrint ^ this->FingerPrint;
  return (*mem2);
}

DroidMemory&			DroidMemory::operator+=(size_t xp)
{
  this->Exp = this->Exp + xp;
  this->FingerPrint = this->FingerPrint ^ xp;
  return (*this);
}

DroidMemory&			DroidMemory::operator+(size_t xp) const
{
  DroidMemory			mem1;
  DroidMemory			*mem2;

  mem2 = new DroidMemory();
  mem1.Exp = xp;
  mem1.FingerPrint = xp;
  mem2->Exp = mem1.Exp + this->Exp;
  mem2->FingerPrint = mem1.FingerPrint ^ this->FingerPrint;
  return (*mem2);
}

std::ostream& operator<<(std::ostream& w_exit, DroidMemory const& mem)
{
  w_exit << "Droid Memory '" << mem.getFingerPrint() << "', " << mem.getExp();
  return (w_exit);
}
