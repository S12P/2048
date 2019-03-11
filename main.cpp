#include "game.h"



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    /*******
     * test
     * ****/

    Game g;
    g.afficher_score();

    g.afficher_data();
    //QString CurrentDir =  QCoreApplication::applicationDirPath();
    //cout <<  "yo "<< QFileDialog::directory().toStdString();
             //.toStdString();

    return app.exec();
}


