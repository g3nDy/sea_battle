#pragma once
#include <vector>
#include <queue>
#include <random>
#include "ability/Ability.h"
#include "ability/DoubleDamage.h"
#include "ability/Scan.h"
#include "ability/RandomShot.h"
#include "NoAbilitiesException.h"

class AbilityManager {
public:
    AbilityManager();
    void applyAbility(GameField& field, ShipManager& manager);
    void addAbility(Ability* ability);
    void generateInitialAbilities();
    void giveRandomAbility();

private:
    std::queue<Ability*> abilities;
};
