#include "Deck.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
template <typename CardType>
Deck<CardType>::Deck() {
    cards_.clear();
}

template <typename CardType>
Deck<CardType>::~Deck() {
}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card) {
    cards_.push_back(card);
}

template <typename CardType>
CardType&& Deck<CardType>::Draw() {
    if (cards_.empty()) {
        throw std::runtime_error("Deck is empty. Cannot draw a card.");
    }

    CardType drawnCard = std::move(cards_.back());
    cards_.pop_back();

    return std::move(drawnCard);
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const {
    return cards_.empty();
}

template <typename CardType>
void Deck<CardType>::Shuffle() {
    std::mt19937 rng(2028358904);
    std::shuffle(cards_.begin(), cards_.end(), rng);
}

template <typename CardType>
int Deck<CardType>::getSize() const {
    return static_cast<int>(cards_.size());
}

template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const {
    return cards_;
}

template class Deck<Card>;
