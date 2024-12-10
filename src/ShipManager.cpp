#include <iostream>
#include "ShipManager.h"

ShipManager::ShipManager(int ships_count, std::vector<int>& lengths_of_ships) 
{
    for (int i = 0; i < ships_count; i++) {
        if (lengths_of_ships[i] > 0 & lengths_of_ships[i] < 4){
            ship_array.emplace_back(lengths_of_ships[i]);
            ship_array[i].SetShipIndex(i);
        }
        else{
            std::cout << "Ship length must be between 1 and 4 inclusive." << '\n';
            return;
        }
    }
}

Ship& ShipManager::GetShip(int index)
{
    return ship_array[index]; 
}

// Возвращает длину корабля по индексу
int ShipManager::GetShipLength(int index) const {
    if (index < 0 || index >= (int) ship_array.size()) {
        std::cout<< "Invalid ship index.";
        return 0;
    }
    return ship_array[index].GetLength();
}

int ShipManager::GetShipCount() const
{ 
    return ship_array.size(); 
}


std::vector<Ship>& ShipManager::GetShipArray()
{
    return ship_array;
}

bool ShipManager::AllShipsDestroy()
{
    for(auto& ship:ship_array){
        if (!ship.IsDestroyed()){
            return false;
        }
    }
}