#pragma once
#include <vector>
#include <stdexcept>
#include <string>

enum class CellStatus { Empty, Unknown, Ship };
enum class ShipOrientation { Horizontal, Vertical };
enum class SegmentStatus { Intact, Damaged, Destroyed };

class Ship {
public:
    Ship(int length);

    // Возвращает длину корабля
    int GetLength() const;

    // Возвращает ориентацию корабля
    ShipOrientation GetOrientation() const;

    // Возвращает статус сегмента по индексу
    SegmentStatus GetSegmentStatus(int index) const;

    // Наносит урон сегменту корабля по индексу
    void DamageSegment(int index);
    void DoubleDamage(int index);

    // Проверяет, уничтожен ли корабль
    bool IsDestroyed() const;
    
    int GetShipIndex() const;
    void SetShipIndex(int index);

private:
    int length_;
    int index;
    ShipOrientation orientation_;
    std::vector<SegmentStatus> segments_;
};

