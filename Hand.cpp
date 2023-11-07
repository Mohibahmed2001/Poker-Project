#include "Hand.hpp"

// Constructor
Hand::Hand() {
   
}

// Destructor
Hand::~Hand() {
    
}

// Copy Constructor
Hand::Hand(const Hand& other) : cards_(other.cards_) {
    
}

// Copy Assignment Operator
Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        cards_ = other.cards_;
    }
    return *this;
}

// Move Constructor
Hand::Hand(Hand&& other) noexcept : cards_(std::move(other.cards_)) {
}

// Move Assignment Operator
Hand& Hand::operator=(Hand&& other) noexcept {
    if (this != &other) {
        cards_ = std::move(other.cards_);
    }
    return *this;
}
// Get Cards
const std::deque<PointCard>& Hand::getCards() const {
    return cards_;
}

// Add a Card to the Hand
void Hand::addCard(PointCard&& card) {
    cards_.push_back(std::move(card));
}

// Check if the Hand is Empty
bool Hand::isEmpty() const {
    return cards_.empty();
}

// Reverse the Hand
void Hand::Reverse() {
    std::reverse(cards_.begin(), cards_.end());
}

// Play a Card from the Hand
int Hand::PlayCard() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot play a card from an empty hand.");
    }

    PointCard& frontCard = cards_.front();
    if (!frontCard.isPlayable()) {
        cards_.pop_front(); 
        throw std::runtime_error("The card is not playable.");
    }

    int points = std::stoi(frontCard.getInstruction()); 
    cards_.pop_front(); 
    return points;
}
