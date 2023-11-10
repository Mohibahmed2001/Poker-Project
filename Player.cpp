#include "Player.hpp"

Player::Player() : score_(0), opponent_(nullptr), actiondeck_(nullptr), pointdeck_(nullptr) {}

Player::~Player() {}

const Hand& Player::getHand() const {
    return hand_;
}

void Player::setHand(const Hand& hand) {
    hand_ = hand;
}

int Player::getScore() const {
    return score_;
}

void Player::setScore(const int& score) {
    score_ = score;
}

void Player::play(ActionCard&& card) {
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
    // Implement the logic for playing an action card
}

void Player::drawPointCard() {
    if (!pointdeck_->IsEmpty()) {
        hand_.addCard(pointdeck_->Draw());
    }
}

void Player::playPointCard() {
    if (!hand_.isEmpty()) {
        score_ += hand_.PlayCard();
    }
}

void Player::setOpponent(Player* opponent) {
    opponent_ = opponent;
}

Player* Player::getOpponent() {
    return opponent_;
}

void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
    actiondeck_ = actiondeck;
}

Deck<ActionCard>* Player::getActionDeck() {
    return actiondeck_;
}

void Player::setPointDeck(Deck<PointCard>* pointdeck) {
    pointdeck_ = pointdeck;
}

Deck<PointCard>* Player::getPointDeck() {
    return pointdeck_;
}
