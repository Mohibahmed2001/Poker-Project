#include "Player.hpp"

Player::Player() : score_(0), opponent_(nullptr), actiondeck_(nullptr), pointdeck_(nullptr) {

}

// Destructor
Player::~Player() {
    
}

// Get Hand
const Hand& Player::getHand() const {
    return hand_;
}

// Set Hand
void Player::setHand(const Hand& hand) {
    hand_ = hand;
}

// Get Score
int Player::getScore() const {
    return score_;
}

// Set Score
void Player::setScore(const int& score) {
    score_ = score;
}

// Play an ActionCard
void Player::play(ActionCard&& card) {
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
}

// Draw a PointCard
void Player::drawPointCard() {
    if (pointdeck_ && !pointdeck_->IsEmpty()) {
        PointCard card = std::move(pointdeck_->Draw());
        hand_.addCard(std::move(card));
    } else {
        throw std::runtime_error("Point deck is empty or not set.");
    }
}

// Play a PointCard
void Player::playPointCard() {
    try {
        int points = hand_.PlayCard();
        score_ += points;
        std::cout << "Played a PointCard for " << points << " points." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Set Opponent
void Player::setOpponent(Player* opponent) {
    opponent_ = opponent;
}

// Get Opponent
Player* Player::getOpponent() {
    return opponent_;
}

// Set ActionDeck
void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
    actiondeck_ = actiondeck;
}

// Get ActionDeck
Deck<ActionCard>* Player::getActionDeck() {
    return actiondeck_;
}

// Set PointDeck
void Player::setPointDeck(Deck<PointCard>* pointdeck) {
    pointdeck_ = pointdeck;
}

// Get PointDeck
Deck<PointCard>* Player::getPointDeck() {
    return pointdeck_;
}
