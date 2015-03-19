/*
** Exo-1.c for  in /home/somasu_b/rendu/piscine_cpp_d09/ex-1
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan 16 02:52:41 2015 SOMASUNDRAM Barathan
** Last update Fri Jan 16 03:15:49 2015 SOMASUNDRAM Barathan
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Exo-1.h"

t_cthulhu	*NewCthulhu()
{
  t_cthulhu	*this;

  if ((this = malloc(sizeof(*this))) == NULL)
    return (NULL);
  CthulhuInitializer(this);
  return (this);
}

void		PrintPower(t_cthulhu *this)
{
  printf("Power => %d\n", this->m_power);
}

void		Attack(t_cthulhu *this)
{
  if (this->m_power >= 42)
    {
      this->m_power -= 42;
      printf("%s attacks and destroys the city\n", this->m_name);
      return;
    }
  printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void		Sleeping(t_cthulhu *this)
{
  this->m_power += 42000;
  printf("%s sleeps\n", this->m_name);
}

static void	CthulhuInitializer(t_cthulhu *this)
{
  this->m_name = strdup("Cthulhu");
  this->m_power = 42;
  printf("----\nBuilding Cthulhu\n");  
}

t_koala		*NewKoala(char *name, char _isALegend)
{
  t_koala	*this;

  if ((this = malloc(sizeof(*this))) == NULL)
    return (NULL);
  KoalaInitializer(this, name, _isALegend);
  return (this);
}

void		Eat(t_koala *this)
{
  this->m_parent.m_power += 42;
  printf("%s eats\n", this->m_parent.m_name);
}

static void	KoalaInitializer(t_koala *this, char *_name, char _isALegend)
{
  CthulhuInitializer(&this->m_parent);
  this->m_parent.m_name = _name;
  if (_isALegend)
    this->m_parent.m_power = 42;
  else
    this->m_parent.m_power = 0;
  this->m_isALegend = _isALegend;
  printf("Building %s\n", this->m_parent.m_name);
}

