#pragma once
#include "../GameField.h"
#include "../ShipManager.h"
#include <iostream>

class Ability {
public:
	virtual void apply(GameField& field, ShipManager& manager) = 0;
	virtual ~Ability() = default;
};

