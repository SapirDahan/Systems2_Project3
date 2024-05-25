#include "Intersection.hpp"

using namespace ariel;

Intersection::Intersection(unsigned int index) : index(index), structure(None), owner(nullptr) {}

unsigned int Intersection::getIndex() const { return index; }
Intersection::Structure Intersection::getStructure() const { return structure; }
Player* Intersection::getOwner() const { return owner; }

void Intersection::addAdjacentHexagon(unsigned int hexagonX, unsigned int hexagonY) {
    adjacentHexagons.emplace_back(hexagonX, hexagonY);
}
const std::vector<std::pair<unsigned int, unsigned int>>& Intersection::getAdjacentHexagons() const {
    return adjacentHexagons;
}

bool Intersection::setStructure(Structure newStructure, Player *player) {
    if (newStructure == Settlement) {
        if (structure == None) {
            structure = Settlement;
            this->owner = player;
            return true;
        }
    } else if (newStructure == City) {
        if (structure == Settlement && this->owner == player) {
            structure = City;
            return true;
        }
    }
    return false;
}
