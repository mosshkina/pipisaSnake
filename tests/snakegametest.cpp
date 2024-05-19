#include "snakegametest.h"

void SnakeGameTest::testInitialSnakePosition() {
    Snake snake;
    QCOMPARE(snake.getHead(), QPoint(100, 50));  // Assuming initial position is (50, 50)
}

void SnakeGameTest::testSnakeMovement() {
    Snake snake;
    snake.setDirection(Snake::Direction::Right);
    snake.move();
    QCOMPARE(snake.getHead(), QPoint(110, 50));  // Assuming snake moves right by 10 units
}

void SnakeGameTest::testSnakeGrow() {
    Snake snake;
    int initialLength = snake.length();
    snake.grow();
    QCOMPARE(snake.length(), initialLength + 1);
}

void SnakeGameTest::testSnakeSelfCollision() {
    Snake snake;
    while(snake.length()<10){
        snake.grow();
    }
    snake.setDirection(Snake::Direction::Up);
    snake.move();
    snake.setDirection(Snake::Direction::Left);
    snake.move();
    snake.setDirection(Snake::Direction::Down);
    snake.move();
    snake.setDirection(Snake::Direction::Right);
    snake.move();
    QVERIFY(snake.checkSelfCollision());
}

void SnakeGameTest::testFoodGeneration() {
    Map map;
    map.generateFood();
    QVERIFY(map.isFood(map.getFood()));
}

void SnakeGameTest::testFoodNotOnObstacle() {
    Map map;
    map.loadObstacles("../resources/map2.txt");  // Load a map with obstacles
    map.generateFood();
    QVERIFY(!map.isObstacle(map.getFood()));
}

void SnakeGameTest::testMapLoadObstacles() {
    Map map;
    map.loadObstacles("../resources/map2.txt");
    QVERIFY(map.isObstacle(QPoint(0, 0)));  // Assuming (0, 0) is an obstacle in map2.txt
}

void SnakeGameTest::testMapDraw() {
    Map map;
    map.loadObstacles("resources/map2.txt");
    QImage image(600, 600, QImage::Format_RGB32);
    QPainter painter(&image);
    map.draw(painter);
    QVERIFY(!image.isNull());
}

QTEST_MAIN(SnakeGameTest)
