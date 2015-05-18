//
// order.hpp for  in /home/somasu_b/rendu/cpp_plazza/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr 26 18:17:41 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:17:42 2015 SOMASUNDRAM Barathan
//

#ifndef ORDER_HPP_
# define ORDER_HPP_

#include <iostream>
#include <string>
#include <list>
#include <QDialog>
#include <QWidget>
#include <QObject>
#include "ui_order.hpp"

class		Order : public QDialog
{
  Q_OBJECT
  public:
  Order(std::list<std::string>* command, QWidget* parent = 0);
  ~Order();

public slots:
  void		valid(void);
  void		cancel(void);

private:
  std::list<std::string>*	_command;
  Ui_Order	_ui;
};

#endif /* !ORDER_HPP_ */
