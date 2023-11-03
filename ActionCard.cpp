#include "ActionCard.hpp"

// Constructor implementation
ActionCard::ActionCard() {
    setType(ACTION_CARD); // Set the card type to ACTION_CARD
}

// isPlayable method implementation
bool ActionCard::isPlayable() {
    if (!getDrawn()) {
        return false; // Card must be drawn to be playable
    }

    // Regex to match the valid instructions
    std::regex validInstructionPattern("(DRAW|PLAY)\\s+\\d+\\s+CARD\\(S\\)|REVERSE HAND|SWAP HAND WITH OPPONENT");
    return std::regex_match(getInstruction(), validInstructionPattern);
}

// Print method implementation
void ActionCard::Print() const {
    std::cout << "Type: " << getType() << std::endl
              << "Instruction: " << getInstruction() << std::endl
              << "Card: " << std::endl;
    const int* imageData = getImageData();
    if (imageData) {
        for (int i = 0; i < 80; ++i) { // Assuming there are 80 integers in the image data array
            std::cout << imageData[i];
            if ((i + 1) % 10 == 0) // Assuming you want to print 10 numbers per line
                std::cout << std::endl;
        }
    } else {
        std::cout << "No image data" << std::endl;
    }
}
