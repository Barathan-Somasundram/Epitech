//
// plazza.hpp for  in /home/somasu_b/rendu/cpp_plazza/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr 26 18:18:00 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:18:01 2015 SOMASUNDRAM Barathan
//

#ifndef PLAZZA_HPP_
# define PLAZZA_HPP_

#include <iostream>
#include <string>
#include <list>
#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include "ui_plazza.hpp"
#include "resto.hpp"
#include "SFML.hpp"
#include "order.hpp"

class		Plazza : public QMainWindow
{
  Q_OBJECT
public:
  Plazza(QWidget* parent = 0);
  ~Plazza();

  void				run(void);
  void				setArg(int, int, int);
  int				isDigit(char*);
  int				createKitchen();
  void				enterKitchen(std::string name, int id);
  void				applyCommand(std::string commande);
  int				recup_nb_cook(int id);
  std::string			recup_name(int id);
  void				recup_ressources(int id);
  void				recup_finish(int id);
  SFML				*getSfml();

public slots:
  void				changeToOrder();
  void				changeToAbout();
  void				exit();

private:
  int				_mult;
  int				_cook;
  int				_time;
  std::vector<int>		_fd_in_kitchens;
  std::vector<int>		_fd_out_kitchens;
  SFML				*_sfml;

  std::list<std::string>	_command;

  Ui_Plazza	_ui;
};

#endif /* !PLAZZA_HPP_ */
