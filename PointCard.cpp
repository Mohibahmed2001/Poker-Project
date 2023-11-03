#include "PointCard.hpp"
#include <cstdlib> // For std::atoi

// Constructor
PointCard::PointCard() : Card() {
    // Set the CardType to POINT_CARD by default
    setType(POINT_CARD);
}

// Check if the card is playable
bool PointCard::isPlayable() {
    if (!getDrawn()) {
        return false; // Card must be drawn to be playable
    }

    // Check if the instruction is a valid number between 1 and 99
    int points = std::atoi(getInstruction().c_str());
    return points >= 1 && points <= 99;
}

// Print the Point Card information
void PointCard::Print() const {
    std::cout << "Type: " << getType() << std::endl
              << "Points: " << getInstruction() << std::endl
              << "Card: " << std::endl;
    const int* imageData = getImageData();
    if (imageData) {
        for (int i = 0; i < 80; ++i) {
            std::cout << imageData[i];
            if ((i + 1) % 10 == 0) // Assuming you want to print 10 numbers per line
                std::cout << std::endl;
        }
    } else {
        std::cout << "No image data" << std::endl;
    }
}
