#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <cstdlib>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void runCommand(string command) { system(command.c_str()); }

int main(int argc, char **argv) {

  QApplication app(argc, argv);
  QWidget win;
  win.setFixedSize(1000, 150);

  QGridLayout *lay = new QGridLayout(&win);
  lay->setSpacing(0);
  lay->setContentsMargins(10, 10, 10, 10);

  string path = "/opt/neon-logout-git/";

  vector<QPushButton *> btns;
  unordered_map<string, string> props = {
      {"cancel", "killall neon-logout"},
      {"shutdown", "shutdown -h now"},
      {"logout", "loginctl kill-user $USER"},
      {"reboot", "reboot"},
      {"lock", "slock"},
      {"hibernate", "systemctl hibernate"},
      {"sleep", "systemctl suspend && killall neon-logout"},
      {"hybrid", "systemctl hybrid-sleep"}};
  vector<QLabel *> labels;

  int cnt = 0;
  for (auto i = props.begin(); i != props.end(); i++) {
    QPushButton *Btn = new QPushButton(&win);
    Btn->setIconSize(QSize(100, 100));
    Btn->setStyleSheet("QPushButton{border-radius:50%;}");
    QObject::connect(Btn, &QPushButton::clicked,
                     [=]() { runCommand(i->second); });
    Btn->setIcon(QIcon(QString(string(path + i->first + ".png").c_str())));
    lay->addWidget(Btn, 0, cnt, 1, 1);
    btns.emplace_back(Btn);

    QLabel *Label = new QLabel(i->first.c_str(), &win);
    Label->setStyleSheet(
        "QLabel{font-weight:600;letter-spacing:1px;font-size:15px;}");
    Label->setAlignment(Qt::AlignCenter);
    lay->addWidget(Label, 1, cnt, 1, 1);
    cnt++;
  }

  win.show();
  return app.exec();
}
