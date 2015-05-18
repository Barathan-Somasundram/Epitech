//
// about.hpp for  in /home/somasu_b/rendu/cpp_plazza/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr 26 18:17:26 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:17:27 2015 SOMASUNDRAM Barathan
//

#ifndef ABOUT_HPP_
# define ABOUT_HPP_

#include <iostream>
#include <string>
#include <list>
#include <QDialog>
#include <QWidget>
#include <QObject>
#include "ui_about.hpp"

class		About : public QDialog
{
  Q_OBJECT
  public:
  About(QWidget* parent = 0);
  ~About();

private:
  Ui_Dialog	_ui;
};

#endif /* !ABOUT_HPP_ */
