#include "katana.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    katana w;
    w.show();
    return a.exec();
}
