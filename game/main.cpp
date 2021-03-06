#include <QGuiApplication>
#include <QtGui/QOpenGLContext>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickView>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QSurfaceFormat format;
    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL) {
        format.setVersion(3, 2);
        format.setProfile(QSurfaceFormat::CoreProfile);
    }
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);

    QQuickView view;
    view.setFormat(format);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    QObject::connect(view.engine(), &QQmlEngine::quit,
                     &app, &QGuiApplication::quit);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return QGuiApplication::exec();
}
