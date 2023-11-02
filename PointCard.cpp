#include "PointCard.hpp"
#include <iostream>

PointCard::PointCard() {
    setType(CardType::POINT_CARD);
}

bool PointCard::isPlayable() {
    if (getDrawn()) {
        const std::string& instruction = getInstruction();
        try {
            int points = std::stoi(instruction);
            return true; 
        } catch (const std::invalid_argument& e) {
            return false; 
        }
    }
    return false; 
}

void PointCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
    std::cout << "Card:" << std::endl;
    
    const int* imageData = getImageData();
    if (imageData) {
        for (int i = 0; i < 80; i++) {
            std::cout << imageData[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No image data" << std::endl;
    }
}
