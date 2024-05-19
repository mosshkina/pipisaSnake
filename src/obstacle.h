#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QPoint>

class Obstacle {
public:
    Obstacle(int x, int y);
    QPoint getPosition() const;

private:
    QPoint position;
};

#endif // OBSTACLE_H
