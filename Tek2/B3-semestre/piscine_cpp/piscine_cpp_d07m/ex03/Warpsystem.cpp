//
// Warpsystem.cpp for  in /home/somasu_b/rendu/piscine_cpp_d07m/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Jan 13 10:52:16 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 13 18:05:45 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include "Warpsystem.hh"

/*
** WARPSYSTEM QUANTUMREACTOR
*/

WarpSystem::QuantumReactor::QuantumReactor()
{
  this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{

}

bool			WarpSystem::QuantumReactor::isStable()
{
  return (this->_stability);
}

void			WarpSystem::QuantumReactor::setStability(bool status)
{
  this->_stability = status;
}

/*
** WARPSYSTEM CORE
*/

WarpSystem::Core::Core(QuantumReactor *core)
{
  this->_coreReactor = core;
}

WarpSystem::Core::~Core()
{

}

WarpSystem::QuantumReactor	*WarpSystem::Core::checkReactor()
{
  return (this->_coreReactor);
}
