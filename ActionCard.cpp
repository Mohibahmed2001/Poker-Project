#include "ActionCard.hpp"
#include<iostream>
using namespace std;

ActionCard::ActionCard() : Card() {
}

bool ActionCard::isPlayable() {
    if (!getDrawn()) {
        return false; 
    }
    std::string instruction = getInstruction();
    std::regex validPattern("(DRAW [1-9]\\d* CARD(S)?)|(PLAY [1-9]\\d* CARD(S)?)|(REVERSE HAND)|(SWAP HAND WITH OPPONENT)");
    return std::regex_match(instruction, validPattern);
}

void ActionCard::Print() const {
    std::cout << "Type: " << (getType() == "Action Card" ? "Action Card" : "Unknown") << std::endl;
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
