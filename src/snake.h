#ifndef SNAKE_H
#define SNAKE_H

#include <QList>
#include <QPoint>
#include <QPainter>

class Snake {
public:
    enum class Direction { Left, Right, Up, Down };

    Snake();
    void move();
    void grow();
    void setDirection(Direction newDirection);
    void draw(QPainter &painter);
    bool checkSelfCollision() const;
    void reset();
    QPoint getHeadPosition() const;
    const QPoint& getHead() const;
    int length() const;

    static int getFIELD_WIDTH();

    static int getFIELD_HEIGHT();

    Direction getDirection() const;

private:
    QList<QPoint> body;
    Direction direction;
    void updateBody();

    static constexpr int FIELD_WIDTH = 600;
    static constexpr int FIELD_HEIGHT = 600;
};

#endif // SNAKE_H
