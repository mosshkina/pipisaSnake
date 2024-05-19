#include "map.h"
#include "snake.h"
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QRandomGenerator>

Map::Map() {
    loadMap(1);
}

void Map::loadMap(int mapNumber) {
    obstacles.clear();
    QString fileName = "../resources/map" + QString::number(mapNumber) + ".txt";
    loadObstacles(fileName);
    generateFood();
}

void Map::loadObstacles(const QString &fileName) {
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList points = line.split(" ");
            obstacles.append(QPoint(points[0].toInt(), points[1].toInt()));
        }
        file.close();
    }
}

void Map::draw(QPainter &painter) {
    painter.setBrush(Qt::red);
    for (const QPoint &point : obstacles) {
        painter.drawRect(point.x(), point.y(), 10, 10);
    }

    painter.setBrush(Qt::yellow);
    painter.drawRect(food.x(), food.y(), 10, 10);
}

bool Map::isObstacle(const QPoint &point) const {
    return obstacles.contains(point);
}

bool Map::isFood(const QPoint &point) const {
    return point == food;
}

void Map::generateFood() {
    QRandomGenerator *generator = QRandomGenerator::global();
    Snake snake;
    int fieldWidth = snake.getFIELD_WIDTH();
    int fieldHeight = snake.getFIELD_HEIGHT();

    QPoint newFood;
    do {
        int x = generator->bounded(0, fieldWidth / 10) * 10;
        int y = generator->bounded(0, fieldHeight / 10) * 10;
        newFood = QPoint(x, y);
    } while (isObstacle(newFood) || isFood(newFood));

    food = newFood;
}

QPoint Map::getFood() const {
    return food;
}

