
#include "Card.hpp"
using namespace std;

/**
         * Destructor
         * @post: Destroy the Card object
        */
Card::~Card() {
    delete[] bitmap_;
}

/**
         * Copy Constructor
         * @post: Construct a new Card object
         * @param: const reference to a Card object
        */
Card::Card(const Card &rhs) : cardType_(rhs.cardType_), instruction_(rhs.instruction_), drawn_(rhs.drawn_)
{
    if(rhs.bitmap_ != nullptr){
        bitmap_ = new int(*rhs.bitmap_);
    } else{
        bitmap_ = nullptr;
    }
}

/**
         * Copy Assignment Operator
         * @param const reference to a Card object
         * @return this Card object
         */
Card &Card::operator=(const Card &rhs)
{
    if (this != &rhs) {
        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;
        bitmap_ = rhs.bitmap_;

    }

    return *this;
    
}

 /**
         * Move Constructor
         * @param: rvalue reference to a Card object 
        */
Card::Card(Card &&rhs){

    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = rhs.bitmap_;
    rhs.bitmap_ = nullptr;
    drawn_ = rhs.drawn_;

}
/**
         * Move assignment operator
         * @param: rvalue reference to a Card object
         * @return this card object
        */
Card &Card::operator=(Card &&rhs)
{

    if(this != &rhs){
        cardType_ = std::move(rhs.cardType_);
        instruction_ = std::move(rhs.instruction_);
        drawn_ = rhs.drawn_;
        bitmap_ = std::move(rhs.bitmap_);
        rhs.bitmap_ = nullptr;
    }

    return *this;
}

/**
         * Default Constructor
         * @post: Construct a new Card object 
         */
Card::Card() : cardType_(), instruction_(""), bitmap_(), drawn_(false)
{
}
 /**
         * @return the string representation of the card type ACTION_CARD or POINT_CARD
         */
std::string Card::getType() const
{
    std::string triangle;
    if(cardType_ == POINT_CARD)
        triangle = "POINT_CARD";
    else
        triangle = "ACTION_CARD";
    return triangle;
}

/**
         * @post: set the card type 
         * @param const reference to a CardType object
         */
void Card::setType(const CardType& type) {
    cardType_ = type;
}

 /**
         * @return the string representation of the card instruction
        */
const std::string& Card::getInstruction() const {
    return instruction_;
}

  /**
         * @post: set the card instruction
         * @param: const reference to an instruction 
         */
void Card::setInstruction(const std::string& instruction) {
    instruction_ = instruction;
}


        /**
         * @return the image data
         */
const int* Card::getImageData() const {
    return bitmap_;
}
        /**
         * @post: Set the image data
         * @param pointer to an array of integers
         */
void Card::setImageData(int *data)
{
    if(bitmap_) delete [] bitmap_;
    bitmap_ = data;
}


  /**
         * @return the drawn status of the card
        */
bool Card::getDrawn() const {
    return drawn_;
}

// @return drawn
void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}
