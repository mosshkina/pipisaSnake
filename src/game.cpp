#include "game.h"
#include <QPainter>
#include <QTimer>
#include <QMessageBox>
#include <QVBoxLayout>

Game::Game(QWidget *parent) : QWidget(parent) {
    map = new Map();
    snake = new Snake();
    QWidget *main = new QWidget;
    main->setFixedSize(630,650);
    main->show();
    QVBoxLayout *layout = new QVBoxLayout(main);
    createMenuBar();
    layout->addWidget(menuBar);

    setFocusPolicy(Qt::StrongFocus);

    this->setFixedSize(601,601);
    layout->addWidget(this);
    startGame();
}

void Game::createMenuBar() {
    menuBar = new QMenuBar(this);

    pauseMenu = menuBar->addMenu("Pause");
    mapMenu = menuBar->addMenu("Maps");

    pauseAction = new QAction("Pause", this);
    connect(pauseAction, &QAction::triggered, this, &Game::pauseGame);
    pauseMenu->addAction(pauseAction);

    map1Action = new QAction("Map 1", this);
    connect(map1Action, &QAction::triggered, this, &Game::chooseMap1);
    mapMenu->addAction(map1Action);

    map2Action = new QAction("Map 2", this);
    connect(map2Action, &QAction::triggered, this, &Game::chooseMap2);
    mapMenu->addAction(map2Action);

    map3Action = new QAction("Map 3", this);
    connect(map3Action, &QAction::triggered, this, &Game::chooseMap3);
    mapMenu->addAction(map3Action);

    map4Action = new QAction("Map 4", this);
    connect(map4Action, &QAction::triggered, this, &Game::chooseMap4);
    mapMenu->addAction(map4Action);
}


void Game::chooseMap1() {
    pauseGame();
    QMessageBox::information(this, "Map Selected", "Map 1 selected!");
    map->loadMap(1);
    startGame();
}

void Game::chooseMap2() {
    pauseGame();
    QMessageBox::information(this, "Map Selected", "Map 2 selected!");
    map->loadMap(2);
    startGame();
}

void Game::chooseMap3() {
    pauseGame();
    QMessageBox::information(this, "Map Selected", "Map 3 selected!");
    map->loadMap(3);
    startGame();
}

void Game::chooseMap4() {
    pauseGame();
    QMessageBox::information(this, "Map Selected", "Map 4 selected!");
    map->loadMap(4);
    startGame();
}

void Game::startGame() {
    inGame = true;
    paused = false;
    score = 0;
    snake->reset();
    timerId = startTimer(100);
}

void Game::pauseGame() {
    paused = !paused;
    if (paused) {
        killTimer(timerId);
    } else {
        timerId = startTimer(100 - (score / N_POINTS_TO_INCREASE_SPEED));
    }
}

void Game::stopGame() {
    killTimer(timerId);
    inGame = false;
}

void Game::gameOver() {
    stopGame();
    QMessageBox::information(this, "Game Over", "Game Over! Your score: " + QString::number(score));
    startGame();
}

void Game::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter qp(this);
    if (inGame) {
        snake->draw(qp);
        map->draw(qp);
    }
}

void Game::timerEvent(QTimerEvent *event) {
    Q_UNUSED(event);

    if (inGame && !paused) {
        snake->move();
        checkCollision();
        updateGame();
    }

    repaint();
}

void Game::keyPressEvent(QKeyEvent *event) {
    Snake::Direction currentDirection = snake->getDirection();

    switch (event->key()) {
    case Qt::Key_Left:
    case Qt::Key_A:
        if (currentDirection != Snake::Direction::Right) {
            snake->setDirection(Snake::Direction::Left);
        }
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        if (currentDirection != Snake::Direction::Left) {
            snake->setDirection(Snake::Direction::Right);
        }
        break;
    case Qt::Key_Up:
    case Qt::Key_W:
        if (currentDirection != Snake::Direction::Down) {
            snake->setDirection(Snake::Direction::Up);
        }
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        if (currentDirection != Snake::Direction::Up) {
            snake->setDirection(Snake::Direction::Down);
        }
        break;
    case Qt::Key_P:
        pauseGame();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}


void Game::checkCollision() {
    if (map->isObstacle(snake->getHeadPosition())) {
        gameOver();
    }

    if (snake->checkSelfCollision()) {
        gameOver();
    }
}

void Game::updateGame() {
    if (map->isFood(snake->getHeadPosition())) {
        score++;
        snake->grow();
        map->generateFood();
        if (score % N_POINTS_TO_INCREASE_SPEED == 0) {
            killTimer(timerId);
            timerId = startTimer(100 - (score / N_POINTS_TO_INCREASE_SPEED));
        }
    }
}
