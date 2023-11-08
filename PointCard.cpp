#include "PointCard.hpp"

// Constructor
PointCard::PointCard() {
    // Set the type specific for PointCard
    setType(CardType::POINT_CARD);
}

bool PointCard::isPlayable() {
    if (!getDrawn() || getInstruction().empty()) return false;   
    int points = std::stoi(getInstruction());
    return points >= 1 && points <= 99;
}

// Print the Point Card
void PointCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    std::cout << getImageData() << std::endl;
}
