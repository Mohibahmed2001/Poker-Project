#include "Hand.hpp"

// Constructor
Hand::Hand() {
    // Dummy constructor
}

// Destructor
Hand::~Hand() {
    // Dummy destructor
}

// Copy Constructor
Hand::Hand(const Hand& other) {
    // Dummy copy constructor
}

// Copy Assignment Operator
Hand& Hand::operator=(const Hand& other) {
    // Dummy copy assignment operator
    return *this;
}

// Move Constructor
Hand::Hand(Hand&& other) {
    // Dummy move constructor
}

// Move Assignment Operator
Hand& Hand::operator=(Hand&& other) {
    // Dummy move assignment operator
    return *this;
}

const std::deque<PointCard>& Hand::getCards() const {
    // Dummy implementation, returning an empty deque
    return cards_;
}

void Hand::addCard(PointCard&& card) {
    // Dummy implementation
}

bool Hand::isEmpty() const {
    // Dummy implementation, always returning true
    return true;
}

void Hand::Reverse() {
    // Dummy implementation
}

int Hand::PlayCard() {
    // Dummy implementation, returning 0
    return 0;
}
