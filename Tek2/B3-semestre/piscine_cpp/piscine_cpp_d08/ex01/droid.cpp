//
// droid.cpp for  in /home/somasu_b/rendu/piscine_cpp_d08/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Wed Jan 14 15:38:32 2015 SOMASUNDRAM Barathan
// Last update Thu Jan 15 09:30:36 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "droid.hh"
#include "droidmemory.hh"

Droid::Droid(const std::string s_number) : Attack(25), Toughness(15)
{
  this->Energy = 50;
  this->Id = s_number;
  this->Status = new std::string("Standing by"); 
  this->battleData = new DroidMemory();
  std::cout << "Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const& original) : Attack(original.Attack), Toughness(original.Toughness)
{
  this->Energy = original.Energy;
  this->Id = original.Id;
  if (original.Status)
    this->Status = new std::string(*(original.Status));
  else
    this->Status = new std::string("Standing by"); 
  std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
  if (this->Status)
    delete this->Status;
  std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
}

std::string		Droid::getId() const
{
  return (this->Id);
}

size_t			Droid::getEnergy() const
{
  return (this->Energy);
}

std::string*		Droid::getStatus() const
{
  return (this->Status);
}

size_t 		Droid::getAttack() const
{
  return (this->Attack);
}

size_t 		Droid::getToughness() const
{
  return (this->Toughness);
}

void			Droid::setId(const std::string id)
{
  this->Id = id;
}

void			Droid::setEnergy(const size_t energy)
{
  this->Energy = energy;
  if (this->Energy > 100)
    this->Energy = 100;
}

void			Droid::setStatus(std::string* status)
{
  delete this->Status;
  this->Status = status;
}

Droid&			Droid::operator=(Droid const& original)
{
  if (&original == this)
    return (*this);
  this->Id = original.Id;
  this->Energy = original.Energy;
  *this->Status = *original.Status;
  return (*this);
}

bool			Droid::operator==(Droid const& original) const
{
  if (*this->Status == *original.Status)
    return (true);
  return (false);
}

bool			Droid::operator!=(Droid const& original) const
{
  if (*this == original)
    return (false);
  return (true);
}

Droid&			Droid::operator<<(size_t& reload)
{
  if (this->Energy <= 100)
    {
      this->Energy = this->Energy + reload;
      if (this->Energy > 100)
	{
	  reload = reload - (100 - this->Energy);
	  this->Energy = 100;
	}
      else
	reload = reload - reload;
    }
  return (*this);
}

std::ostream&		operator<<(std::ostream& w_exit, Droid const& droid)
{
  w_exit << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
  return (w_exit);
}

DroidMemory*		Droid::getBattleData() const
{
  return (this->battleData);
}

void			Droid::setBattleData(DroidMemory* bD)
{
  delete this->battleData;
  this->battleData = bD;
}
