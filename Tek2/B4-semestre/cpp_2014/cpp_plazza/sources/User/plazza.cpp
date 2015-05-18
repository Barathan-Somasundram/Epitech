//
// plazza.cpp for  in /home/somasu_b/rendu/cpp_plazza/sources/User
//
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
//
// Started on  Sun Apr 26 18:20:08 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:20:09 2015 SOMASUNDRAM Barathan
//

#include <unistd.h>
#include "plazza.hpp"
#include "order.hpp"
#include "about.hpp"
#include "my_exception.hpp"
#include "resto.hpp"

Plazza::Plazza(QWidget* parent)
  : QMainWindow(parent)
{
  _ui.setupUi(this);
  QObject::connect(_ui.actionQuit, SIGNAL(triggered()), this, SLOT(exit()));
  QObject::connect(_ui.actionNew_command, SIGNAL(triggered()), this, SLOT(changeToOrder()));
  QObject::connect(_ui.actionAbout_2, SIGNAL(triggered()), this, SLOT(changeToAbout()));
}

Plazza::~Plazza()
{

}

int		Plazza::isDigit(char* str)
{
  int		i = -1;
  while (str && str[++i])
    if (str[i] < '0' || str[i] > '9')
      return (1);
  return (0);
}

void		Plazza::setArg(int mult, int cook, int time)
{
  if (cook == 0)
    throw (my_exception("there is no cook in the kitchens"));
  if (cook < 0)
    throw (my_exception("the second parameter must be positiv"));
  if (mult < 0)
    throw (my_exception("the first parameter must be positiv"));
  if (time < 0)
    throw (my_exception("the third parameter must be positiv"));
  _mult = mult;
  _cook = cook;
  _time = time;
}

void		Plazza::run(void)
{
  QListWidgetItem*	thumbnail = new QListWidgetItem("cuisine");
  _ui.kitchenList->addItem(thumbnail);
  QList<QListWidgetItem *> items = _ui.kitchenList->findItems("kitchen", Qt::MatchStartsWith);
  if (items.size() > 0) {
    int i = 0;
    while (i < items.size())
      {
  	QString lol = items[i]->text();
  	std::cout << items.size() << " " << lol.toStdString() << std::endl;
	QListWidgetItem* tmp = _ui.kitchenList->takeItem(i);
	delete tmp;
	++i;
      }
  }
  this->show();
}

void		Plazza::changeToOrder(void)
{
  Order		cmd(&_command);
  cmd.exec();
  for (std::list<std::string>::iterator it = _command.begin(); it != _command.end(); ++it)
    {
      _ui.processingOrdersList->addItem((*it).c_str());
      applyCommand(*it);
      usleep(100000);
    }
  _command.clear();
}

void		Plazza::changeToAbout(void)
{
  About		about;
  about.exec();
}

void		Plazza::exit(void)
{
  qApp->quit();
}
