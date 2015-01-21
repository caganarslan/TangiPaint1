#include <QApplication>
#include <QException>
#include <QDebug>
#include <QDesktopWidget>

#include "qtglwebcamdemo.h"

int main(int argc, char *argv[])
{
    int res=-1;

    try
    {
        QApplication a(argc, argv);
        QtGLWebcamDemo w;
        w.show();

        //QRect screenres = QApplication::desktop()->screenGeometry(1);
        //QDesktopWidget dw;
        //*dw = a.desktop();
        /*QRect screenres = a.desktop()->screenGeometry(1);
        w.move(QPoint(screenres.x(), screenres.y()));
        w.showFullScreen();
            */

        res = a.exec();
    }
    catch(QException &e)
    {
        qCritical() << QString("Exception: %1").arg( e.what() );
    }
    catch(...)
    {
        qCritical() << QString("Unhandled Exception");
    }

    return res;
}
