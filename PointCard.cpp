#include "PointCard.hpp"

PointCard::PointCard() : Card() {
}

bool PointCard::isPlayable() {
    if (!getDrawn()) {
        return false; 
    }
    std::string instruction = getInstruction();
    for (char c : instruction) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return !instruction.empty(); 
}

void PointCard::Print() const {
    std::cout << "Type: " << (getType() == "Point Card" ? "Point Card" : "Unknown") << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl; 
    std::cout << "Card: " << std::endl;

    const int* imageData = getImageData();
    if (imageData) {
        for (int i = 0; i < 80; ++i) {
            std::cout << imageData[i] << " ";
            if ((i + 1) % 10 == 0) { 
                std::cout << std::endl;
            }
        }
    } else {
        std::cout << "No image data" << std::endl;
    }
}
