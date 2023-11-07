#include "ActionCard.hpp"

// Constructor
ActionCard::ActionCard() {
    // Set the type specific for ActionCard
    setType(CardType::ACTION_CARD);
}

// Check if the card is playable
bool ActionCard::isPlayable() {
    // Simplified logic for demonstration purposes. You'd need a more complex check for the different valid instructions.
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
            if ((i + 1) % 10 == 0) { // Newline every 10 numbers for formatting
                std::cout << std::endl;
            }
        }
    } else {
        std::cout << "No image data" << std::endl;
    }
}
