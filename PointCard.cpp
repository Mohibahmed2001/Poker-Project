#include "Card.hpp"
#include <regex>
#include "PointCard.hpp"
/**
         * @post: Construct a new Point Card object
         */
PointCard::PointCard() : Card()
{
    setType(POINT_CARD); 
}

/**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be a valid number
        */
bool PointCard::isPlayable()
{
    if(!getDrawn()){
        return false; 
    } 

    std::regex points("^([1-9][0-9]{0,1}|99)");
    if(std::regex_match(getInstruction(), points)){
        return true;
    } else {
    }

    return false;
}


/**
         * @post: Print the Point Card in the following format:
         * Type: [CardType]
         * Points: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
void PointCard::Print() const
{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
    std::cout << "Card:" << std::endl;

    if(!getImageData()){
        std::cout << "No image data" << std::endl;
    }
    else{
        for(int i = 0; i < 80; i++){
            std::cout << getImageData()[i] << " " << std::endl;
        }
    }

    std::cout << std::endl;

    
}