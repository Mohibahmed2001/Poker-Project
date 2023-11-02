#include "Player.hpp"

// Constructor
Player::Player() {
    // Dummy constructor
}

// Destructor
Player::~Player() {
    // Dummy destructor
}

const Hand& Player::getHand() const {
    // Dummy implementation, returning an empty hand
    return hand_;
}

void Player::setHand(const Hand& hand) {
    // Dummy implementation
}

int Player::getScore() const {
    // Dummy implementation, always returning 0
    return score_;
}

void Player::setScore(const int& score) {
    // Dummy implementation
}

void Player::play(ActionCard&& card) {
    // Dummy implementation
}

void Player::drawPointCard() {
    // Dummy implementation
}

void Player::playPointCard() {
    // Dummy implementation
}

void Player::setOpponent(Player* opponent) {
    // Dummy implementation
}

Player* Player::getOpponent() {
    // Dummy implementation, returning a nullptr
    return nullptr;
}

void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
    // Dummy implementation
}

Deck<ActionCard>* Player::getActionDeck() {
    // Dummy implementation, returning a nullptr
    return nullptr;
}

void Player::setPointDeck(Deck<PointCard>* pointdeck) {
    // Dummy implementation
}

Deck<PointCard>* Player::getPointDeck() {
    // Dummy implementation, returning a nullptr
    return nullptr;
}
