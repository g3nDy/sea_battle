#include "GameField.h"
#include "OutOfBoundsAttackException.h"
#include "InvalidShipPlacementException.h"
#include <iostream>

GameField::GameField(int width, int height) : width(width), height(height) {
    if (width < 1 || height < 1) {
        std::cout << "Field width and height must be greater than 0.";
        return;
    }
    field.resize(height, std::vector<CellStatus>(width, CellStatus::Unknown));
}

//конструктор копирования
GameField::GameField(const GameField &other)
{
    width = other.width;
    height = other.height;
    field = other.field;
    occupied_cells = other.occupied_cells;
}
//оперотор присваивания копирования
GameField& GameField::operator=(const GameField& other) 
{
    if (this != &other)
    {
        width = other.width;
        height = other.height;
        field = other.field;
        occupied_cells = other.occupied_cells;
    }
    return *this;
}


    // Конструктор перемещения
GameField::GameField(GameField &&other) noexcept
{
    std::swap(width, other.width);
    std::swap(height, other.height);
    field = std::move(other.field);
    occupied_cells = std::move(other.occupied_cells);

}
    // Оператор присваивания перемещением
GameField& GameField::operator=(GameField&& other) noexcept 
{
    if (this != &other) 
    {
        std::swap(width, other.width);
        std::swap(height, other.height);
        field = std::move(other.field);
        occupied_cells = std::move(other.occupied_cells);
    }
    return *this;
}




void GameField::PlaceShip(const Ship& ship, int x, int y, ShipOrientation orientation)
{   
    //проверка на выход за границы
    if (x < 0 || y >= height || x >= width || y < 0 
    || (orientation == ShipOrientation::Horizontal && x + ship.GetLength() >= width)
    || (orientation == ShipOrientation::Vertical && y + ship.GetLength() >= height))
    {
        throw OutOfBoundsAttackException();
    }

    //проерка на пересечение или соприкосновение кораблей
    for (int i = 0; i < ship.GetLength(); i++){
        if (orientation == ShipOrientation::Horizontal){
            if(field[y][x + i] == CellStatus::Ship 
                || (y + 1 < height && field[y + 1][x + i] == CellStatus::Ship)
                || (y - 1 >= 0 && field[y - 1][x + i] == CellStatus::Ship))
            {
                throw InvalidShipPlacementException(" Ship intersects or touches with other ships '\n'");
                return;
            }
        }
        else{
            if (field[y + i][x] == CellStatus::Ship
                || (x + 1 < width && field[y + i][x + 1] == CellStatus::Ship)
                || (x - 1 >= 0 && field[y + i][x - 1] == CellStatus::Ship))
            {
                throw InvalidShipPlacementException("Ship intersects or touches with other ships '\n'");
                return;
            }
        }
    }
    for (int i = 0; i < ship.GetLength(); i++)
    {
        if (orientation == ShipOrientation::Horizontal)
        {
            occupied_cells.emplace_back(PlacedSegmentsCoordinations{.x = x + i, .y = y, .ship_index = ship.GetShipIndex(), .segment_index = i});
            field[y][x + i] = CellStatus::Ship;
        }
        else
        {
            occupied_cells.emplace_back(PlacedSegmentsCoordinations{.x = x, .y = y + i, .ship_index = ship.GetShipIndex(), .segment_index = i});
            field[y + i][x] = CellStatus::Ship;
        }
    }
}   


bool GameField::AttackCell(int x, int y, std::vector<Ship> &ship_array)
{
    if (x >= width || x < 0 || y >= height || y < 0)
    {
        throw OutOfBoundsAttackException();
    }
    int ship_ind = -1;
    for (auto &cell : occupied_cells)
    {
        if (cell.x == x && cell.y == y)
        {
            
            if(double_damage){
                ship_array[ship_ind].DoubleDamage(cell.segment_index);
                double_damage = false;
            }
            else {
                ship_array[ship_ind].DamageSegment(cell.segment_index);
            }
            
            if (ship_array[ship_ind].IsDestroyed()){
                return true;
            }
        }
    }
    field[x][y] = CellStatus::Empty;
    return false;
}