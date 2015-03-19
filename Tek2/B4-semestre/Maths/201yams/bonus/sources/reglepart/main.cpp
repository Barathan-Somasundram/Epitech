#include <QApplication>
#include <fenetreprincipale.hpp>
 
int main(int argc, char* argv[])
{
  QApplication leYams(argc,argv);
  FenetrePrincipale* laFenetrePrincipale =new FenetrePrincipale();
  
  laFenetrePrincipale->show();
  return leYams.exec();
}
