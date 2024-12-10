#include "RandomShot.h"
#include <random>

void RandomShot::apply(GameField& field, ShipManager& manager) {
    srand(time(NULL));
    if (manager.GetShipCount() > 0) {
        Ship* ship = nullptr;
        int random_index;
        
        do {
            random_index = rand() % manager.GetShipCount();
            ship = &manager.GetShip(random_index);
        } while (ship->IsDestroyed());

        int segment_index;
        do {
            segment_index = rand() % ship->GetLength();
        } while (ship->GetSegmentStatus(segment_index) != SegmentStatus::Destroyed);
        ship->DamageSegment(segment_index);
        
        std::cout << "\nRandom shot hit the ship! )) \n\n";
    }
}
