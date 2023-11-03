#ifndef ACTIONCARD_HPP
#define ACTIONCARD_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include "Card.hpp"

class ActionCard : public Card
{
public:
    // Constructor
    ActionCard() : Card() {
         setType(ACTION_CARD);// Initialize any ActionCard specific members if any
    }

    // isPlayable method
    virtual bool isPlayable() override {
        if (!getDrawn()) {
            return false; // Card must be drawn to be playable
        }

        // Check if the instruction is valid
        std::regex validInstructionPattern("(DRAW|PLAY)\\s+\\d+\\s+CARD\\(S\\)|REVERSE HAND|SWAP HAND WITH OPPONENT");
        return std::regex_match(getInstruction(), validInstructionPattern);
    }

    // Print method
    virtual void Print() const override {
        std::cout << "Type: " << getType() << std::endl
                  << "Instruction: " << getInstruction() << std::endl
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
};

#endif // ACTIONCARD_HPP
