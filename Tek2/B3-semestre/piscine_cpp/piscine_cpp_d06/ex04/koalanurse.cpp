//
// koalanurse.cpp for  in /home/somasu_b/rendu/piscine_cpp_d06/ex03
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 12 16:14:15 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 13 09:47:13 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <fstream>
#include <string>
#include "sickkoala.h"
#include "koalanurse.h"

KoalaNurse::KoalaNurse(int id)
{
  this->id = id;
  this->if_work = 0;
}

KoalaNurse::~KoalaNurse()
{
  std::cout << "Nurse " << this->id << ": Enfin un peu de repos !" << std::endl;
}

void		KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
  patient->takeDrug(drug);
}

std::string	KoalaNurse::readReport(std::string filename)
{
  std::string	drug;
  std::fstream	file;
  int		is_ok;

  is_ok = filename.find(".report");
  if (is_ok == std::string::npos && filename.substr(is_ok).compare(".report") != 0)
    return (drug);
  file.open(filename.c_str());
  if (!file.is_open())
    return (drug);
  getline(file, drug, '\0');
  filename.resize(filename.size() - 7);
  std::cout << "Nurse " << this->id << ": Kreog ! Il faut donner un " << drug << " a Mr."
	    << filename << " !" << std::endl;
  file.close();
  return (drug);
}

void		KoalaNurse::timeCheck()
{
  if (this->if_work == 0)
    std::cout << "Nurse " << this->id << ": Je commence le travail !" << std::endl;
  else
    std::cout << "Nurse " << this->id << ": Je rentre dans ma foret d'eucalyptus !"
	      << std::endl;
  this->if_work = (this->if_work == 0 ? 1 : 0);
}
