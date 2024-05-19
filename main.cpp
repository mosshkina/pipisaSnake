#include "game.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Game game;
    game.show();
    return app.exec();
}
