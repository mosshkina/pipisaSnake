#include "obstacle.h"

Obstacle::Obstacle(int x, int y) : position(x, y) {}

QPoint Obstacle::getPosition() const {
    return position;
}
