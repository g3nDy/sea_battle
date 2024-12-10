// Функция main
#include <iostream>
#include <vector>
#include <string>
#include "GameField.h"
#include "ShipManager.h"
#include "AbilityManager.h"


int main()
{
    // Пример использования классов
    std::vector<int> ship_lengths = {3, 2, 3, 2, 7};
    ShipManager ship_manager(5, ship_lengths);

    GameField my_field(10, 10);
    AbilityManager abilityManager;

    // Размещение кораблей на поле
    my_field.PlaceShip(ship_manager.GetShip(0), 1, 1, ShipOrientation::Vertical);
    my_field.PlaceShip(ship_manager.GetShip(1), 3, 3, ShipOrientation::Horizontal);
    my_field.PlaceShip(ship_manager.GetShip(2), 9, 8, ShipOrientation::Vertical);
    my_field.PlaceShip(ship_manager.GetShip(3), 1, 2, ShipOrientation::Horizontal);
    my_field.PlaceShip(ship_manager.GetShip(4), 0, 5, ShipOrientation::Horizontal);




    // Пример атаки
    
    if (my_field.AttackCell(1, 1, ship_manager.GetShipArray()))
    {
        abilityManager.giveRandomAbility();
    }
    if (my_field.AttackCell(1, 1, ship_manager.GetShipArray()))
    {
        abilityManager.giveRandomAbility();
    }
    if (my_field.AttackCell(3, 3, ship_manager.GetShipArray()))
    {
        abilityManager.giveRandomAbility();
    }




    my_field.Show(ship_manager.GetShipArray());
    return 0;
}