#include "Hand.hpp"

Hand::Hand() {
    cards_.clear();
}

Hand::~Hand() {
}

Hand::Hand(const Hand& other) {
    cards_ = other.cards_;
}

Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        cards_ = other.cards_;
    }
    return *this;
}

Hand::Hand(Hand&& other) {
    cards_ = std::move(other.cards_);
}

Hand& Hand::operator=(Hand&& other) {
    if (this != &other) {
        cards_ = std::move(other.cards_);
    }
    return *this;
}

const std::deque<PointCard>& Hand::getCards() const {
    return cards_;
}

void Hand::addCard(PointCard&& card) {
    cards_.push_back(std::move(card));
}

bool Hand::isEmpty() const {
    return cards_.empty();
}

void Hand::Reverse() {
    std::reverse(cards_.begin(), cards_.end());
}

int Hand::PlayCard() {
    if (cards_.empty()) {
        throw std::runtime_error("Hand is empty. Cannot play a card.");
    }

    PointCard frontCard = std::move(cards_.front());
    cards_.pop_front();

    if (frontCard.isPlayable()) {
        return frontCard.getPoints();
    }

    return 0;
}
