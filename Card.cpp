#include "Card.hpp"

// Destructor
Card::~Card() {
    delete[] bitmap_;  // Assuming bitmap_ is dynamically allocated
}

// Copy Constructor
Card::Card(const Card& rhs) 
    : cardType_(rhs.cardType_), instruction_(rhs.instruction_), drawn_(rhs.drawn_) {
    bitmap_ = new int[80];  
    std::copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_);  
}

// Copy Assignment Operator
Card& Card::operator=(const Card& rhs) {
    if (this != &rhs) {
        delete[] bitmap_;  // Delete existing bitmap_
        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;
        bitmap_ = new int[80];
        std::copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_);
    }
    return *this;
}

// Move Constructor
Card::Card(Card&& rhs) noexcept
    : cardType_(rhs.cardType_), instruction_(std::move(rhs.instruction_)), 
      bitmap_(rhs.bitmap_), drawn_(rhs.drawn_) {
    rhs.bitmap_ = nullptr;
}

// Move Assignment Operator
Card& Card::operator=(Card&& rhs) noexcept {
    if (this != &rhs) {
        delete[] bitmap_;
        cardType_ = rhs.cardType_;
        instruction_ = std::move(rhs.instruction_);
        bitmap_ = rhs.bitmap_;
        drawn_ = rhs.drawn_;
        rhs.bitmap_ = nullptr;
    }
    return *this;
}

// Default Constructor
Card::Card() : cardType_(POINT_CARD), bitmap_(new int[80]{}), drawn_(false) {
    // bitmap_ is dynamically allocated with size 80, initialized to zeros
}

std::string Card::getType() const {
    return cardType_ == POINT_CARD ? "Point Card" : "Action Card";
}

void Card::setType(const CardType& type) {
    cardType_ = type;
}

const std::string& Card::getInstruction() const {
    return instruction_;
}

void Card::setInstruction(const std::string& instruction) {
    instruction_ = instruction;
}

const int* Card::getImageData() const {
    return bitmap_;
}

void Card::setImageData(int* data) {
    delete[] bitmap_; 
    bitmap_ = new int[80];  
    std::copy(data, data + 80, bitmap_);  
}

bool Card::getDrawn() const {
    return drawn_;
}

void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}


