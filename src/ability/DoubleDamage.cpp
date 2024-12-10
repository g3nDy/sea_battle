#include "DoubleDamage.h"


void DoubleDamage::apply(GameField& field, ShipManager& manager) {
    field.setDoubleDamage(true);
    std::cout << "Ability 'Double Damage' activated!\n";
}
