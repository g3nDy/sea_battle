#pragma once
#include "ability.h"
#include <random>



class RandomShot : public Ability {
public:
    void apply(GameField& field, ShipManager& manager) override;
};
