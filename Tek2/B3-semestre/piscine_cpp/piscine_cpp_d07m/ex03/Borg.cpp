//
// Borg.cpp for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 13 19:00:14 2015 SOMASUNDRAM Barathan
// Last update Wed Jan 14 02:04:21 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Destination.hh"
#include "Federation.hh"
#include "Borg.hh"


Borg::Ship::Ship(int wF, short repair)
{
  this->_side = 300;
  this->_maxWarp = 9;
  this->_home = UNICOMPLEX;
  this->_location = this->_home;
  this->_shield = 100;
  this->_weaponFrequency = wF;
  this->_repair = repair;
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{

}

void			Borg::Ship::setupCore(WarpSystem::Core *core)
{
  this->core = core;
}

void			Borg::Ship::checkCore()
{
  WarpSystem::QuantumReactor	*tmp;

  if (!this->core)
    return;
  tmp = this->core->checkReactor();
  std::cout << (tmp->isStable() == true ? "Everything is in order." : "Critical failure imminent.")
	    << std::endl;
}


bool			Borg::Ship::move(int warp, Destination d)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (warp > this->_maxWarp || d == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = d;
  return (true);
}

bool			Borg::Ship::move(int warp)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (warp > this->_maxWarp || this->_home == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = this->_home;
  return (true);
}

bool			Borg::Ship::move(Destination d)
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (d == this->_location || tmp->isStable() == false)
    return (false);
  this->_location = d;
  return (true);
}

bool			Borg::Ship::move()
{
  WarpSystem::QuantumReactor	*tmp;

  tmp = this->core->checkReactor();
  if (tmp->isStable() == false)
    return (false);
  this->_location = this->_home;
  return (true);
}

int			Borg::Ship::getShield()
{
  return (this->_shield);
}

void			Borg::Ship::setShield(int shield)
{
  this->_shield = shield;
}

int			Borg::Ship::getWeaponFrequency()
{
  return (this->_weaponFrequency);
}

void			Borg::Ship::setWeaponFrequency(int wF)
{
  this->_weaponFrequency = wF;
}

short			Borg::Ship::getRepair()
{
  return (this->_repair);
}

void			Borg::Ship::setRepair(short repair)
{
  this->_repair = repair;
}

void			Borg::Ship::repair()
{
  if (this->_repair > 0)
    {
      this->_shield = 100;
      this->_repair--;
      std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions."
		<< std::endl;
    }
  else
    std::cout << "Energy cells depleted, shield weakening." << std::endl;
}

void			Borg::Ship::fire(Federation::Starfleet::Ship *ea)
{
  std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
  ea->damage(this->_weaponFrequency);
}

void			Borg::Ship::fire(Federation::Ship *vu)
{
  std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
  vu->damage(this->_weaponFrequency);
}

void			Borg::Ship::damage(int dam)
{
  this->_shield = (this->_shield - dam < 0 ? 0 : this->_shield - dam);
}
