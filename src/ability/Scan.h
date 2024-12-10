#pragma once
#include "Ability.h"


class Scan : public Ability {
public:
	void apply(GameField& field, ShipManager& manager) override;
};
