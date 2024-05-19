#ifndef SNAKEGAMETEST_H
#define SNAKEGAMETEST_H

#include <QObject>
#include <QtTest>
#include "snake.h"
#include "map.h"

class SnakeGameTest : public QObject {
    Q_OBJECT

private slots:
    void testInitialSnakePosition();
    void testSnakeMovement();
    void testSnakeGrow();
    void testSnakeSelfCollision();
    void testFoodGeneration();
    void testFoodNotOnObstacle();
    void testMapLoadObstacles();
    void testMapDraw();
};

#endif // SNAKEGAMETEST_H
