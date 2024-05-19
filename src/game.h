#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QKeyEvent>
#include <QMenuBar>
#include <QAction>
#include "snake.h"
#include "map.h"

class Game : public QWidget {
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    void startGame();
    void pauseGame();
    void stopGame();
    void gameOver();

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void chooseMap1();
    void chooseMap2();
    void chooseMap3();
    void chooseMap4();

private:
    Snake *snake;
    Map *map;
    int timerId;
    int score;
    bool inGame;
    bool paused;
    void checkCollision();
    void updateGame();
    void createMenuBar();

    QMenuBar *menuBar;
    QMenu *pauseMenu;
    QMenu *mapMenu;
    QAction *pauseAction;
    QAction *map1Action;
    QAction *map2Action;
    QAction *map3Action;
    QAction *map4Action;

    static constexpr int N_POINTS_TO_INCREASE_SPEED = 10;
};

#endif // GAME_H
