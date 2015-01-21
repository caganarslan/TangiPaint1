#include "qtglwebcamdemo.h"
#include "ui_qtglwebcamdemo.h"
#include <QtGui>

using namespace std;
using namespace cv;

vector<Point2f> left_image;      // Stores 4 points(x,y) of the logo image. Here the four points are 4 corners of image.
vector<Point2f> right_image;    // stores 4 points that the user clicks(mouse left click)

QtGLWebcamDemo::QtGLWebcamDemo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtGLWebcamDemo)
{
    ui->setupUi(this);
}

QtGLWebcamDemo::~QtGLWebcamDemo()
{
    delete ui;
}

void QtGLWebcamDemo::on_actionStart_triggered()
{
    if( !mCapture.isOpened() )
        if( !mCapture.open( 1 ) )
            return;

    startTimer(0);
}

void QtGLWebcamDemo::timerEvent(QTimerEvent *event)
{
    cv::Mat image;
    mCapture >> image;

   // setMouseCallback("Display window",on_mouse, NULL );

    int imH = image.rows;
    int imY = image.cols;

    qDebug() << "the integer is" << imH << " and " << imY;

    int pX = this->mapFromGlobal(QCursor::pos()).x();
    int pY = this->mapFromGlobal(QCursor::pos()).y();
    cv::circle(image,Point(pX/2-5,pY/2-20), 3, Scalar(0,0,255), CV_FILLED, 8, 0);

    cv::namedWindow("projector");
    cv::moveWindow("projector", 1366, 0);
    imshow("projector", image);

    /*
    QPoint pMouse = QCursor::pos();
    int pX = pMouse.x();
    int pY = pMouse.y();

    cv::circle(image,Point(pX,pY), 10, Scalar(0,0,0), CV_FILLED, 8, 0);*/

    ui->openCVviewer->showImage( image );
}

