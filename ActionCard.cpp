#include "ActionCard.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <regex>
ActionCard::ActionCard() : Card() {
    // You can do additional initializations specific to ActionCard here if needed.
}

// Check if the card is playable
bool ActionCard::isPlayable() {
    // Card must be drawn and instruction must be valid
    if (!getDrawn()) {
        return false;
    }

    // Check if instruction matches any of the valid instructions
    std::string instruction = getInstruction();
    std::regex validPattern(R"(^(DRAW \d+ CARD\(S\)|PLAY \d+ CARD\(S\)|REVERSE HAND|SWAP HAND WITH OPPONENT)$)");
    return std::regex_match(instruction, validPattern);
}

// Print the ActionCard information
void ActionCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
     std::cout << getImageData() << std::endl;
}

