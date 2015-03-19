#ifndef PAGEAPROPOS_HPP
#define PAGEAPROPOS_HPP
 
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
 
class PageAPropos : public QWidget
{   Q_OBJECT
 
private:
  QLabel *sonTexte, *sonIllustration;
  QPushButton* sonBoutonRetour;
 
public:
  explicit PageAPropos(QWidget *parent = 0);
     
signals:
     
public slots:
     
};
 
#endif // PAGEAPROPOS_HPP
