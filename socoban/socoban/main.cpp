#include <QApplication>
#include "socoban.hpp"
#include "appsettings.hpp"
#pragma comment (lib, "opengl32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    appSettings::instance();

    socoban app;

    app.setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    app.setFixedSize(800,600);

    app.show();

    return a.exec();
}
