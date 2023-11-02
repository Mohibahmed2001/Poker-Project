#include "Card.hpp"
#include <iostream>

Card::~Card() {
    std::cout << "Destructor is called" << std::endl;
    delete[] bitmap_;
}

// Copy Constructor
Card::Card(const Card& rhs) {
    std::cout << "Copy constructor called" << std::endl;
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;

    // Allocate memory for the bitmap and copy the data
    bitmap_ = new int[80];
    for (int i = 0; i < 80; i++) {
        bitmap_[i] = rhs.bitmap_[i];
    }

    drawn_ = rhs.drawn_;
}

// Copy Assignment Operator
Card& Card::operator=(const Card& rhs) {
    if (this != &rhs) {
        std::cout << "Copy assignment called" << std::endl;

        // Release the existing bitmap
        delete[] bitmap_;

        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;

        // Allocate memory for the new bitmap and copy the data
        bitmap_ = new int[80];
        for (int i = 0; i < 80; i++) {
            bitmap_[i] = rhs.bitmap_[i];
        }

        drawn_ = rhs.drawn_;
    }
    return *this;
}

// Move Constructor
Card::Card(Card&& rhs) {
    std::cout << "Move constructor called" << std::endl;

    cardType_ = rhs.cardType_;
    instruction_ = std::move(rhs.instruction_);

    // Move the existing bitmap and reset rhs
    bitmap_ = rhs.bitmap_;
    rhs.bitmap_ = nullptr;

    drawn_ = rhs.drawn_;
}

// Move Assignment Operator
Card& Card::operator=(Card&& rhs) {
    if (this != &rhs) {
        std::cout << "Move assignment called" << std::endl;

        // Release the existing bitmap
        delete[] bitmap_;

        cardType_ = rhs.cardType_;
        instruction_ = std::move(rhs.instruction_);

        // Move the existing bitmap and reset rhs
        bitmap_ = rhs.bitmap_;
        rhs.bitmap_ = nullptr;

        drawn_ = rhs.drawn_;
    }
    return *this;
}

// Default Constructor
Card::Card() = default;

// Other member functions
std::string Card::getType() const {
    return (cardType_ == POINT_CARD) ? "POINT_CARD" : "ACTION_CARD";
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
    // Release existing bitmap
    delete[] bitmap_;
    
    // Allocate new memory for the bitmap and copy the data
    bitmap_ = new int[80];
    for (int i = 0; i < 80; i++) {
        bitmap_[i] = data[i];
    }
}

bool Card::getDrawn() const {
    return drawn_;
}

void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}
