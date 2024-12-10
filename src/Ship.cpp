#include <iostream>
#include "Ship.h"

Ship::Ship(int length)
    : length_(length), orientation_(ShipOrientation::Horizontal) {
    if (length_ > 4 ||length_ < 1) {
        std::cout << "Ship length must be between 1 and 4 inclusive." << '\n';
        return;
    }
    segments_.resize(length, SegmentStatus::Intact);

}

int Ship::GetLength() const { return length_; }

ShipOrientation Ship::GetOrientation() const { return orientation_; }

SegmentStatus Ship::GetSegmentStatus(int index) const {
    
    return segments_[index];
}

void Ship::DamageSegment(int index) {
    if (index < 0 || index >= length_) {
        std::cout << "Invalid segment index." << '\n';
        return;
    }
    if (segments_[index] == SegmentStatus::Intact) {
        segments_[index] = SegmentStatus::Damaged;
    }
    else if (segments_[index] == SegmentStatus::Damaged) {
        segments_[index] = SegmentStatus::Destroyed;
    }
}

void Ship::DoubleDamage(int index){
    segments_[index] = SegmentStatus::Destroyed;
}

bool Ship::IsDestroyed() const {
    for (auto status : segments_) {
        if (status != SegmentStatus::Destroyed) {
            return false;
        }
    }
    return true;
}
int Ship::GetShipIndex() const { return index; }
void Ship::SetShipIndex(int index) { this->index = index; }
