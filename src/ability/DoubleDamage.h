#pragma once
#include "Ability.h"


class DoubleDamage : public Ability {
public:
	void apply(GameField& field, ShipManager& manager) override;
};
