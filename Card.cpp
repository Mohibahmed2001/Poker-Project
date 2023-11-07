#include "Card.hpp"

// Destructor
Card::~Card() {
    delete[] bitmap_;
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
        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;

        delete[] bitmap_;
        bitmap_ = new int[80];
        std::copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_);
    }
    return *this;
}

// Move Constructor
Card::Card(Card&& rhs)
    : cardType_(rhs.cardType_), instruction_(std::move(rhs.instruction_)), bitmap_(rhs.bitmap_), drawn_(rhs.drawn_) {
    rhs.bitmap_ = nullptr;
}

// Move Assignment Operator
Card& Card::operator=(Card&& rhs) {
    if (this != &rhs) {
        cardType_ = rhs.cardType_;
        instruction_ = std::move(rhs.instruction_);
        delete[] bitmap_;
        bitmap_ = rhs.bitmap_;
        drawn_ = rhs.drawn_;

        rhs.bitmap_ = nullptr;
    }
    return *this;
}

// Default Constructor
Card::Card() : bitmap_(new int[80]{}), drawn_(false) {}

// getType
std::string Card::getType() const {
    return cardType_ == CardType::POINT_CARD ? "Point Card" : "Action Card";
}

// setType
void Card::setType(const CardType& type) {
    cardType_ = type;
}

// getInstruction
const std::string& Card::getInstruction() const {
    return instruction_;
}

// setInstruction
void Card::setInstruction(const std::string& instruction) {
    instruction_ = instruction;
}

// getImageData
const int* Card::getImageData() const {
    return bitmap_;
}

// setImageData
void Card::setImageData(int* data) {
    if (bitmap_) {
        delete[] bitmap_;
    }
    bitmap_ = new int[80];
    std::copy(data, data + 80, bitmap_);
}

// getDrawn
bool Card::getDrawn() const {
    return drawn_;
}

// setDrawn
void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}

// Print and isPlayable are pure virtual and will be implemented in derived classes.
