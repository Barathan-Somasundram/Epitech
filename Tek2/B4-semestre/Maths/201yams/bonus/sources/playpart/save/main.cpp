#include <QApplication>
#include <fenetreprincipal.hpp>
 
int main(int argc, char* argv[])
{
  QApplication leYams(argc,argv);
  FenetrePrincipale* laFenetrePrincipale =new FenetrePrincipale();
  
  laFenetrePrincipale->show();
  return leYams.exec();
}
