
#include "Card.hpp"
using namespace std;

// Destructor
Card::~Card() {
    delete[] bitmap_;
}

// Copy Constructor
Card::Card(const Card& rhs) :cardType_(rhs.cardType_), instruction_(rhs.instruction_), drawn_(rhs.drawn_) {
    bitmap_ = new int{*rhs.bitmap_};
}

// Copy Assignment Operator
Card& Card::operator=(const Card& rhs) {
    if (this != &rhs) {
        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;
        bitmap_ = rhs.bitmap_;
    }
    return *this;
}

// Move Constructor
Card::Card(Card&& rhs){
    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = rhs.bitmap_;
    rhs.bitmap_ = nullptr;
    drawn_ = std::move(rhs.drawn_);
}

// Move Assignment Operator
Card& Card::operator=(Card&& rhs) {
    if (this != &rhs) {
        delete[] bitmap_;
        std::swap(cardType_,rhs.cardType_);
        std::swap(instruction_,rhs.instruction_);
        std::swap(bitmap_,rhs.bitmap_);
        std::swap(drawn_,rhs.drawn_);
        rhs.bitmap_ = nullptr;
    }
    return *this;
}

// Default Constructor
Card::Card() : cardType_(ACTION_CARD),instruction_(""),bitmap_(nullptr), drawn_(false) {}

// getType
std::string Card::getType() const {
    if( cardType_==ACTION_CARD){
        return "ACTION_CARD";
    }
    else{
        return "POINT_CARD";
    }
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
    delete[] bitmap_;
    bitmap_ = data;
}

// getDrawn
bool Card::getDrawn() const {
    return drawn_;
}

// setDrawn
void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}
