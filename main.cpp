#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QDebug>

#include "camerafilter.h"

#include <scene.h>
#include "fboinsgrenderer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType< CameraFilter >( "com.vayra.camera", 1, 0, "CameraFilter" );
    qmlRegisterType< FboInSGRenderer >( "com.vayra.rendering", 1, 0, "Renderer" );

    Scene::getInstancia()->show();

    return app.exec();
}

