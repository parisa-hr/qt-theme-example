#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int  main(int argc, char *argv[])
{
    QApplication  a(argc, argv);
    MainWindow    w;

    w.show();

    QObject::connect(&w, &MainWindow::changedDark, &a, [&]
    {
        /**
         * Load the application style
         */
        QFile dark_styleFile(":/theme/themes/MaterialDark.qss");

        dark_styleFile.open(QFile::ReadOnly);

        /**
         * Apply the loaded stylesheet
         */
        QString style(dark_styleFile.readAll());
        a.setStyleSheet(style);
    });

    QObject::connect(&w, &MainWindow::changedLight, &a, [&]
    {
        /**
         * Load the application style
         */
        QFile light_styleFile(":/theme/themes/Ubuntu.qss");

        light_styleFile.open(QFile::ReadOnly);

        /**
         * Apply the loaded stylesheet
         */
        QString style(light_styleFile.readAll());
        a.setStyleSheet(style);
    });

    return a.exec();
}
