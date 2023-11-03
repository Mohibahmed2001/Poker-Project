#include "Card.hpp"
#include <iostream> 
#include <string>   
#include <algorithm>
#include <vector>


// Destructor
Card::~Card() {
    delete[] bitmap_;
}

// Copy Constructor
Card::Card(const Card& rhs) : cardType_(rhs.cardType_), instruction_(rhs.instruction_), drawn_(rhs.drawn_) {
    bitmap_ = new int[80];
    for(int i = 0; i < 80; ++i) {
        bitmap_[i] = rhs.bitmap_[i];
    }
}

// Copy Assignment Operator
Card& Card::operator=(const Card& rhs) {
    if (this != &rhs) {
        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;
        delete[] bitmap_;
        bitmap_ = new int[80];
        for(int i = 0; i < 80; ++i) {
            bitmap_[i] = rhs.bitmap_[i];
        }
    }
    return *this;
}

// Move Constructor
Card::Card(Card&& rhs) : cardType_(rhs.cardType_), instruction_(std::move(rhs.instruction_)), bitmap_(rhs.bitmap_), drawn_(rhs.drawn_) {
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
Card::Card() : cardType_(POINT_CARD), instruction_(""), bitmap_(new int[80]), drawn_(false) {
    for(int i = 0; i < 80; ++i) {
        bitmap_[i] = 0;
    }
}

std::string Card::getType() const {
    if(cardType_==POINT_CARD){
        return "POINT_CARD";
    }
    else if(cardType_==ACTION_CARD){
        return "ACTION_CARD";
    }
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


