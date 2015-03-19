//
// player.cpp for  in /home/somasu_b/Downloads/ISO/l/playpart
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Fri Feb 27 23:39:26 2015 SOMASUNDRAM Barathan
// Last update Sat Feb 28 01:42:57 2015 SOMASUNDRAM Barathan
//

#include <cstring>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"

Player::Player()
{

}

Player::~Player()
{

}

static int		cmp_int(const void* a, const void* b)
{
  int* pa=(int*)a;
  int* pb=(int*)b;
  int ea=*pa;
  int eb=*pb;
  return ea-eb;
}

void			Player::setDice(int nb)
{
  int			i = 0;

  srand(time(NULL) * nb);
  for (i = 0; i < 5; i++)
    _dice[i] = rand() % 6 + 1;
}

void			Player::setSuite(void)
{
  int i,_suite,contigu = 1;
  _suite = 0;
  for(i=1;i<5;i++)
    {
      if (_dice[i]==_dice[i-1]+1)
	contigu++;
      else
	contigu = 1;
      if (contigu>_suite)
	_suite = contigu;
    }
}

void			Player::setFull(void)
{
  if (occur[5]==3 && occur[4]==2)
    _full = 25;
  else
    _full = 0;
}

void			Player::setBrelan(int somme)
{
  if (occur[5] >= 3)
    _brelan = somme;
  else
    _brelan = 0;
}

void			Player::setCarre(int somme)
{
  if (occur[5] >= 4)
    _carre = somme;
  else
    _carre = 0;
}

void			Player::setYams(void)
{
  if (occur[5] >= 4)
    _yams = 50;
  else
    _yams = 0;
}

void			Player::setScore(void)
{
  _score = _yams + _brelan + _carre + _full + _suite + _chance;
}
#include <iostream>
void			Player::analyse(void)
{
  int			i, somme = 0;
  
  qsort(_dice, 5, sizeof(int), cmp_int);
   memset(occur,0,6*sizeof(int));
  for(i=0;i<5;i++)
    occur[_dice[i]-1]++;
  qsort(occur, 6, sizeof(int), cmp_int);
  somme = _dice[0] + _dice[1] + _dice[2] + _dice[3] + _dice[4];
  setSuite();
  setFull();
  setYams();
  _chance = somme;
  setBrelan(somme);
  setCarre(somme);
  // if (_suite == 4)
  //   _suite = 30;
  // if (_suite == 5)
  //   _suite = 40;
  // std::cout << "brelan: " << _brelan << std::endl;
  // std::cout << "carre: " << _carre << std::endl;
  // std::cout << "suite: " << _suite << std::endl;
  // std::cout << "yams: " << _yams << std::endl;
  // std::cout << "full: " << _full << std::endl;
  // std::cout << "chance: " << _chance << std::endl;
  setScore();
}

int			Player::getDice(int face)
{
  return (_dice[face]);
}

int			Player::getScore(void)
{
  return (_score);
}

int			Player::getBrelan(void)
{
  return (_brelan);
}

int			Player::getCarre(void)
{
  return (_carre);
}

int			Player::getFull(void)
{
  return (_full);
}

int			Player::getSuite(void)
{
  return (_suite);
}

int			Player::getYams(void)
{
  return (_yams);
}

int			Player::getChance(void)
{
  return (_chance);
}  
