#include "ActionCard.hpp"

// Constructor
ActionCard::ActionCard() {
    setType(CardType::ACTION_CARD);
}

// Check if the card is playable
bool ActionCard::isPlayable() {
    if (!getDrawn()) return false;

    const std::string& instruction = getInstruction();
    return instruction.find("DRAW") != std::string::npos ||
           instruction.find("PLAY") != std::string::npos ||
           instruction == "REVERSE HAND" ||
           instruction == "SWAP HAND WITH OPPONENT";
}

// Print the Action Card
void ActionCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
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
