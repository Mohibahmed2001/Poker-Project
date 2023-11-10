#include "Deck.hpp"

template <typename CardType>
Deck<CardType>::Deck() {}

template <typename CardType>
Deck<CardType>::~Deck() {}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card) {
    cards_.push_back(card);
}

template <typename CardType>
CardType&& Deck<CardType>::Draw() {
    CardType card = std::move(cards_.back());
    cards_.pop_back();
    return std::move(card);
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const {
    return cards_.empty();
}

template <typename CardType>
void Deck<CardType>::Shuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(cards_.begin(), cards_.end(), gen);
}

template <typename CardType>
int Deck<CardType>::getSize() const {
    return cards_.size();
}

template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const {
    return cards_;
}
