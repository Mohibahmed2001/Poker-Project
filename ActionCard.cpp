#include "ActionCard.hpp"
#include<iostream>
using namespace std;
  /* @post: Construct a new Action Card object
        */
        ActionCard::ActionCard(){
            setType(ACTION_CARD);
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
    // Check if the card is drawn
    if (!getDrawn()) {
        return false;
    }
    const string& instruction = getInstruction();
    if (instruction == "REVERSE HAND" || instruction == "SWAP HAND WITH OPPONENT") {
        return true;
    }
    if (instruction.size() >= 5) {
        string prefix = instruction.substr(0, 4);
        if (prefix == "DRAW" || prefix == "PLAY") {
            // Check if the remaining part is a positive integer
            string numberStr = instruction.substr(5);
            for (char c : numberStr) {
                if (!isdigit(c)) {
                    return false;  // Not a digit
                }
            }
            int num = stoi(numberStr);
            if (num > 0) {
                return true;  
            }
        }
    }

    return false;
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
         cout << "Type: " << getType() << endl;
    cout << "Instruction: " << getInstruction() << endl;
    cout << "Card:" << endl;

    const int* imageData = getImageData();
    if (imageData) {
        cout << "Image Data:" << endl;
        for (int i = 0; i < 80; i++) {
            cout << imageData[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No image data" << endl;
    }
}
