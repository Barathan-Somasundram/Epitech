#ifndef MENUPRINCIPAL_HPP
#define MENUPRINCIPAL_HPP
 
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
 
class MenuPrincipal : public QWidget
{   Q_OBJECT
 
private:
  QPushButton *sonBoutonNouvellePartie, *sonBoutonRegles, *sonBoutonAPropos, *sonBoutonQuitter;
 
public:
  explicit MenuPrincipal(QWidget *parent = 0);
     
signals:
     
public slots:
     
};
 
#endif // MENUPRINCIPAL_HPP
