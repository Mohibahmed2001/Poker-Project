#include "PointCard.hpp"

// Constructor
PointCard::PointCard() {
    // Set the type specific for PointCard
    setType(CardType::POINT_CARD);
}

// Check if the card is playable
bool PointCard::isPlayable() {
    // Assuming 'instruction_' contains a number in string format
    return getDrawn() && !getInstruction().empty() && std::all_of(getInstruction().begin(), getInstruction().end(), ::isdigit);
}

// Print the Point Card
void PointCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;

    const int* imageData = getImageData();
    if (imageData) {
        for (int i = 0; i < 80; ++i) {
            std::cout << imageData[i] << " ";
            if ((i + 1) % 10 == 0) { // Newline every 10 numbers for formatting
                std::cout << std::endl;
            }
        }
    } else {
        std::cout << "No image data" << std::endl;
    }
}
