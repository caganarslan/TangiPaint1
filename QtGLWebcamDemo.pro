QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtGLWebcamDemo
TEMPLATE = app

SOURCES += main.cpp\
           qtglwebcamdemo.cpp \
           cqtopencvviewergl.cpp

HEADERS  += qtglwebcamdemo.h \
            cqtopencvviewergl.h

FORMS    += qtglwebcamdemo.ui

win32 {
message("Using win32 configuration")

OPENCV_PATH = C:/opencv-mingw


#LIBS_PATH = "$$OPENCV_PATH/build/x86/mingw/lib" #project compiled using MINGW
LIBS_PATH = "$$OPENCV_PATH/install/x64/mingw/bin" #project compiled using Visual C++ 2010 32bit compiler

    CONFIG(debug, debug|release) {
    LIBS     += -L$$LIBS_PATH \
                -lopencv_core249 \
                -lopencv_highgui249 \
				-lopencv_imgproc249 \
				-lopencv_calib3d249
    }

    CONFIG(release, debug|release) {
    LIBS     += -L$$LIBS_PATH \
                -lopencv_core249 \
                -lopencv_highgui249 \
				-lopencv_imgproc249 \
				-lopencv_calib3d249
	}

}

unix {
message("Using unix configuration")

OPENCV_PATH = /usr/local/opencv2/

LIBS     += -L$$LIBS_PATH \
            -lopencv_core \
            -lopencv_highgui
}

INCLUDEPATH += $$OPENCV_PATH/install/include/

message("OpenCV path: $$OPENCV_PATH")
message("Includes path: $$INCLUDEPATH")
message("Libraries: $$LIBS")


