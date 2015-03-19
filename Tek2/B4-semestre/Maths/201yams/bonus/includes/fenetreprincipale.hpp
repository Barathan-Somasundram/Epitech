#ifndef FENETREPRINCIPALE_HPP
#define FENETREPRINCIPALE_HPP
 
#include <QMainWindow>
#include <QMenuBar>
#include <QLabel>
#include "menuprincipal.hpp"
#include "pageapropos.hpp"
 
class FenetrePrincipale : public QMainWindow
{   Q_OBJECT
 
private:
  MenuPrincipal* sonMenuPrincipal;
  PageAPropos*	saPageAPropos;
 
public:
  FenetrePrincipale(QWidget *parent = 0);
  ~FenetrePrincipale();
     
signals:
     
public slots:
  void	changerMenuPrincipal();
  void	changerPageAPropos();
  void	game(void);
  void	regle(void);
     
};
 
#endif // FENETREPRINCIPALE_HPP
