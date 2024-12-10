#pragma once
#include <vector>
#include "Ship.h" 

class ShipManager {
public:
    ShipManager(int ships_count, std::vector<int>& lengths_of_ships);

    // Возвращает ссылку на корабль по индексу
    Ship& GetShip(int index);

    // Возвращает длину корабля по индексу
    int GetShipLength(int index) const;

    int GetShipCount() const;
    
    std::vector<Ship>& GetShipArray();
    bool AllShipsDestroy();
    
        
private:
    std::vector<Ship> ship_array;
};

