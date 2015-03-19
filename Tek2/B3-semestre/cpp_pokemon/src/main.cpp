#include <QApplication>
#include <QMainWindow>
#include "Pokedex.hh"
#include "XmlParser.hh"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  XmlParser		parser("pokedata.xml");

  parser.startParser();
  Pokedex *pokedex = new Pokedex();
  pokedex->show();
     	  
  return app.exec();
}
