#include "ActionCard.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <regex>
/**
         * @post: Construct a new Action Card object
        */
ActionCard::ActionCard() : Card() {
}


        /**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be valid
         * Valid instructions:
         * DRAW x CARD(S) : assume x is a positive integer
         * PLAY x CARD(S) : assume x is a positive integer
         * REVERSE HAND : reverse the order of the cards in the hand
         * SWAP HAND WITH OPPONENT : swap the hand with the opponent
        */
bool ActionCard::isPlayable() {
  
    if (!getDrawn()) {
        return false;
    }
    //KEY DRAW X CARD(S) must be checking exactly for tht
    std::string instruction = getInstruction();
    std::regex validPattern(R"(^(DRAW \d+ CARD\(S\)|PLAY \d+ CARD\(S\)|REVERSE HAND|SWAP HAND WITH OPPONENT)$)");
    return std::regex_match(instruction, validPattern);
}

/**
         * @post: Print the ActionCard in the following format:
         * Type: [CardType]
         * Instruction: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
void ActionCard::Print() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    const int* imageData = getImageData();
    if (imageData) {
        for (size_t i = 0; i<80; ++i) {
            std::cout << imageData[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No image data" << std::endl;
    }
}


