 #include "snake.h"

Snake::Snake() {
    reset();
}

void Snake::move() {
    updateBody();

    QPoint newHeadPosition = body.first();
    switch (direction) {
    case Direction::Left:
        newHeadPosition -= QPoint(10, 0);
        break;
    case Direction::Right:
        newHeadPosition += QPoint(10, 0);
        break;
    case Direction::Up:
        newHeadPosition -= QPoint(0, 10);
        break;
    case Direction::Down:
        newHeadPosition += QPoint(0, 10);
        break;
    }

    if (newHeadPosition.x() < 0)
        newHeadPosition.setX(FIELD_WIDTH - 10);
    else if (newHeadPosition.x() >= FIELD_WIDTH)
        newHeadPosition.setX(0);
    else if (newHeadPosition.y() < 0)
        newHeadPosition.setY(FIELD_HEIGHT - 10);
    else if (newHeadPosition.y() >= FIELD_HEIGHT)
        newHeadPosition.setY(0);

    body.prepend(newHeadPosition);
    body.removeLast();
}


void Snake::grow() {
    body.append(body.last());
}

void Snake::setDirection(Direction newDirection) {
    direction = newDirection;
}

void Snake::draw(QPainter &painter) {
    painter.setBrush(Qt::green);
    for (int i = 0; i < body.size(); ++i) {
        if (i == 0) {
            painter.setBrush(Qt::darkGreen);
        } else {
            painter.setBrush(Qt::green);
        }
        painter.drawRect(body[i].x(), body[i].y(), 10, 10);
    }
}

bool Snake::checkSelfCollision() const {
    for (int i = 1; i < body.size(); ++i) {
        if (body.first() == body[i]) {
            return true;
        }
    }
    return false;
}

void Snake::reset() {
    body.clear();
    body.append(QPoint(100, 50));
    body.append(QPoint(90, 50));
    body.append(QPoint(80, 50));
    direction = Direction::Right;
}

QPoint Snake::getHeadPosition() const {
    return body.first();
}

void Snake::updateBody() {
    for (int i = body.size() - 1; i > 0; --i) {
        body[i] = body[i - 1];
    }
}

int Snake::getFIELD_HEIGHT() {
    return FIELD_HEIGHT;
}

Snake::Direction Snake::getDirection() const
{
    return direction;
}


int Snake::getFIELD_WIDTH() {
    return FIELD_WIDTH;
}

const QPoint& Snake::getHead() const {
    return body.front();
}

int Snake::length() const {
    return body.size();
}
