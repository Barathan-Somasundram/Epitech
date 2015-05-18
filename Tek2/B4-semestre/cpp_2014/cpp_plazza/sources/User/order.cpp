//
// order.cpp for  in /home/somasu_b/rendu/cpp_plazza/sources/User
//
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
//
// Started on  Sun Apr 26 18:20:03 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:20:04 2015 SOMASUNDRAM Barathan
//

#include <sstream>
#include "order.hpp"

Order::Order(std::list<std::string>* command, QWidget* parent)
  : QDialog(parent)
{
  _ui.setupUi(this);
  _command = command;
}

Order::~Order()
{

}

void		Order::valid(void)
{
  std::ostringstream oss;
  int i = 0;

  oss << _ui.spinBox->value();
  while (i < _ui.spinBox->value())
    {
      _command->push_back(">" + _ui.comboBox_3->currentText().toStdString()
			  + " " + _ui.comboBox_2->currentText().toStdString());
      ++i;
    }
  done(QDialog::Accepted);
}

void		Order::cancel(void)
{
  done(QDialog::Rejected);
}
