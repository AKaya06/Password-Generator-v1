#include "PasswordGenerator.h"
#include <QtWidgets/QApplication>

#include <random>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    PasswordGenerator w;
    w.show();
    return a.exec();
}
