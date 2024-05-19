#ifndef MAP_H
#define MAP_H

#include <QList>
#include <QPoint>
#include <QPainter>

class Map {
public:
    Map();
    void loadMap(int mapNumber);
    void draw(QPainter &painter);
    bool isObstacle(const QPoint &point) const;
    bool isFood(const QPoint &point) const;
    void generateFood();
    QPoint getFood() const;

private:
    QList<QPoint> obstacles;
    QPoint food;
    void loadObstacles(const QString &fileName);

    friend class SnakeGameTest;
};

#endif // MAP_H
