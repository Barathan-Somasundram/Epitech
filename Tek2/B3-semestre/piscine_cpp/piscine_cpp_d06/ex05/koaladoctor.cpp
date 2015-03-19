//
// koaladoctor.cpp for  in /home/somasu_b/rendu/piscine_cpp_d06/ex04
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 12 17:09:46 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 13 03:02:35 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "sickkoala.h"
#include "koalanurse.h"
#include "koaladoctor.h"

KoalaDoctor::KoalaDoctor(std::string name)
{
  this->name = name;
}

KoalaDoctor::~KoalaDoctor()
{
  
}

void		KoalaDoctor::diagnose(SickKoala *patient)
{
  std::string	filename;
  std::fstream	file;
  std::string	drug;
  std::string	drugs[5] = {"mars", "Buronzand", "Viagra",
			    "Extasy", "Feuille d'eucalyptus" };

  std::cout << "Dr." << this->name << ": Je suis le Dr." << this->name
	    << " ! Comment Kreoggez-vous ?" << std::endl;
  filename = patient->getName() + ".report";
  file.open(filename.c_str());
  if (!file.is_open())
    return;
  drug = drugs[random() % 5];
  file << drug << std::endl;
}

void		KoalaDoctor::timeCheck()
{
  static int	if_work = 0;
  
  if (if_work == 0)
    std::cout << "Dr." << this->name << ": Je commence le travail !" << std::endl;
  else
    std::cout << "Dr." << this->name << ": Je rentre dans ma foret d’eucalyptus !"
	      << std::endl;
  if_work = (if_work == 0 ? 1 : 0);
}

std::string	getName()
{
  return (this->name);
}
