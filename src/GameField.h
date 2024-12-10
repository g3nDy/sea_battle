#pragma once
#include <vector>
#include <stdexcept>
#include "Ship.h"
#include "ShipManager.h"


struct PlacedSegmentsCoordinations
{
    int x;
    int y;
    int ship_index;
    int segment_index;
};

class GameField {
public:
    GameField(int width, int height);   

    GameField(const GameField& other);
    GameField& operator = (const GameField& other);

    GameField(GameField&& other) noexcept;
    GameField& operator = (GameField&& other) noexcept;

    void PlaceShip(const Ship& ship, int x, int y, ShipOrientation orientation);
    bool AttackCell(int x, int y, std::vector<Ship> &ship_array);
    void Show(std::vector<Ship> &ship);

    void setDoubleDamage(bool enable);

    int getWidth () const { return  width; }
    int getHeight () const { return height; }

    CellStatus getCellStatus(int x, int y) { return field[x][y]; }

private:
    int width;
    int height;
    std::vector<std::vector<CellStatus>> field;
    std::vector<PlacedSegmentsCoordinations> occupied_cells;
    bool double_damage;
};


