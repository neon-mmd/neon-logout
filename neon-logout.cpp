#include <QApplication>
#include <QtWidgets>
#include <QtGui>
#include <QtCore>

void runCommand(char command[]){
  std::system(command);
}

int main(int argc, char **argv)
{
  // std::string path = "/opt/neon-logout";
  
  QApplication app (argc, argv);
  QWidget win;
  win.setFixedSize(1000,150);
  
  QGridLayout *lay = new QGridLayout(&win);
  lay->setSpacing(0);
  lay->setContentsMargins(10,10,10,10);

  QPushButton *Btn1 = new QPushButton(&win);
  QObject::connect(Btn1, SIGNAL(clicked()),&app, SLOT(quit()));
  Btn1->setIcon(QIcon("/opt/neon-logout-git/cancel.png"));
  Btn1->setIconSize(QSize(100,100));
  Btn1->setStyleSheet("QPushButton{border-radius:50%;}");
  lay->addWidget(Btn1,0,0,1,1);

  QLabel *Label1 = new QLabel("Cancel",&win);
  Label1->setStyleSheet("QLabel{font-weight:600;letter-spacing:1px;font-size:15px;}");
  Label1->setAlignment(Qt::AlignCenter);
  lay->addWidget(Label1,1,0,1,1);

  QPushButton *Btn2 = new QPushButton(&win);
  QObject::connect(Btn2, &QPushButton::clicked,[=] () {
    runCommand("shutdown -h now");
    });
  Btn2->setIcon(QIcon("/opt/neon-logout-git/shutdown.png"));
  Btn2->setIconSize(QSize(100,100));
  Btn2->setStyleSheet("QPushButton{border-radius:50%;}");
  lay->addWidget(Btn2,0,1,1,1);

  QLabel *Label2 = new QLabel("Shutdown",&win);
  Label2->setStyleSheet("QLabel{font-weight:600;letter-spacing:1px;font-size:15px;}");
  Label2->setAlignment(Qt::AlignCenter);
  lay->addWidget(Label2,1,1,1,1);

  QPushButton *Btn3 = new QPushButton(&win);
  QObject::connect(Btn3, &QPushButton::clicked,[=] () {
    runCommand("killall echo $DESKTOP_SESSION");
    });
  Btn3->setIcon(QIcon("/opt/neon-logout-git/logout.png"));
  Btn3->setIconSize(QSize(100,100));
  Btn3->setStyleSheet("QPushButton{border-radius:50%;}");
  lay->addWidget(Btn3,0,2,1,1);

  QLabel *Label3 = new QLabel("Logout",&win);
  Label3->setStyleSheet("QLabel{font-weight:600;letter-spacing:1px;font-size:15px;}");
  Label3->setAlignment(Qt::AlignCenter);
  lay->addWidget(Label3,1,2,1,1);
  
  QPushButton *Btn4 = new QPushButton(&win);
  QObject::connect(Btn4, &QPushButton::clicked,[=] () {
    runCommand("reboot");
    });
  Btn4->setIcon(QIcon("/opt/neon-logout-git/reboot.png"));
  Btn4->setIconSize(QSize(100,100));
  Btn4->setStyleSheet("QPushButton{border-radius:50%;}");
  lay->addWidget(Btn4,0,3,1,1);

  QLabel *Label4 = new QLabel("Reboot",&win);
  Label4->setStyleSheet("QLabel{font-weight:600;letter-spacing:1px;font-size:15px;}");
  Label4->setAlignment(Qt::AlignCenter);
  lay->addWidget(Label4,1,3,1,1);

  QPushButton *Btn5 = new QPushButton(&win);
  QObject::connect(Btn5, &QPushButton::clicked,[=] () {
    runCommand("slock");
    });
  Btn5->setIcon(QIcon("/opt/neon-logout-git/lock.png"));
  Btn5->setIconSize(QSize(100,100));
  Btn5->setStyleSheet("QPushButton{border-radius:50%;}");
  lay->addWidget(Btn5,0,4,1,1);

  QLabel *Label5 = new QLabel("Lock",&win);
  Label5->setStyleSheet("QLabel{font-weight:600;letter-spacing:1px;font-size:15px;}");
  Label5->setAlignment(Qt::AlignCenter);
  lay->addWidget(Label5,1,4,1,1);

  QPushButton *Btn6 = new QPushButton(&win);
  QObject::connect(Btn6, &QPushButton::clicked,[=] () {
    runCommand("systemctl hibernate");
    });
  Btn6->setIcon(QIcon("/opt/neon-logout-git/hibernate.png"));
  Btn6->setIconSize(QSize(100,100));
  Btn6->setStyleSheet("QPushButton{border-radius:50%;}");
  lay->addWidget(Btn6,0,5,1,1);

  QLabel *Label6 = new QLabel("Hibernate",&win);
  Label6->setStyleSheet("QLabel{font-weight:600;letter-spacing:1px;font-size:15px;}");
  Label6->setAlignment(Qt::AlignCenter);
  lay->addWidget(Label6,1,5,1,1);

  QPushButton *Btn7 = new QPushButton(&win);
  QObject::connect(Btn7, &QPushButton::clicked,[=] () {
    runCommand("systemctl suspend");
    });
  Btn7->setIcon(QIcon("/opt/neon-logout-git/sleep.png"));
  Btn7->setIconSize(QSize(100,100));
  Btn7->setStyleSheet("QPushButton{border-radius:50%;}");
  lay->addWidget(Btn7,0,6,1,1);

  QLabel *Label7 = new QLabel("Sleep",&win);
  Label7->setStyleSheet("QLabel{font-weight:600;letter-spacing:1px;font-size:15px;}");
  Label7->setAlignment(Qt::AlignCenter);
  lay->addWidget(Label7,1,6,1,1);

  QPushButton *Btn8 = new QPushButton(&win);
  QObject::connect(Btn8, &QPushButton::clicked,[=] () {
    runCommand("systemctl hybrid-sleep");
    });
  Btn8->setIcon(QIcon("/opt/neon-logout-git/hybrid.png"));
  Btn8->setIconSize(QSize(100,100));
  Btn8->setStyleSheet("QPushButton{border-radius:50%;}");
  lay->addWidget(Btn8,0,7,1,1);

  QLabel *Label8 = new QLabel("Hybrid Sleep",&win);
  Label8->setStyleSheet("QLabel{font-weight:600;letter-spacing:1px;font-size:15px;}");
  Label8->setAlignment(Qt::AlignCenter);
  lay->addWidget(Label8,1,7,1,1);

  win.show();
  return app.exec();
}

