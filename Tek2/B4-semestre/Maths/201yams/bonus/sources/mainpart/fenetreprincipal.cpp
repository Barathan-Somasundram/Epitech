#include <QWidget>
#include <QGridLayout>
#include <cstdlib>
#include "fenetreprincipale.hpp"
 
FenetrePrincipale::FenetrePrincipale(QWidget *parent): QMainWindow(parent)
{
  QWidget* content = new QWidget();
  QGridLayout* layout = new QGridLayout();
  QPixmap pic("./img/proba.png");
  QPixmap scaled = pic.scaled(150, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation);
  QLabel *label = new QLabel();

  setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
  setWindowTitle("Yams");
  setWindowIcon(QIcon("Des/5.png"));
  setPalette(QPalette(Qt::lightGray));
  sonMenuPrincipal =new MenuPrincipal(this);

  label->setPixmap(scaled);
  layout->addWidget(sonMenuPrincipal, 0, 1);
  layout->addWidget(label, 0, 0);

  saPageAPropos =new PageAPropos(this);

  content->setLayout(layout);
  setCentralWidget(content);

  setFixedSize(sizeHint());
}

FenetrePrincipale::~FenetrePrincipale()
{

}

void FenetrePrincipale::game(void)
{
  system("./sources/playpart/yams");
}

void FenetrePrincipale::regle(void)
{
  system("./sources/reglepart/yams");
}

void FenetrePrincipale::changerMenuPrincipal()
{
  // setCentralWidget(this);
  // setFixedSize(sizeHint());
}
 
void FenetrePrincipale::changerPageAPropos()
{
  setCentralWidget(saPageAPropos);
  setFixedSize(sizeHint());
}
