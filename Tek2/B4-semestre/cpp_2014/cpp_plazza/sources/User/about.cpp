//
// about.cpp for  in /home/somasu_b/rendu/cpp_plazza/sources/User
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr 26 18:19:42 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:19:43 2015 SOMASUNDRAM Barathan
//

#include "about.hpp"

About::About(QWidget* parent)
  : QDialog(parent)
{
  _ui.setupUi(this);
  this->show();
}

About::~About()
{

}
