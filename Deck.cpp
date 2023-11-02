#include "Deck.hpp"
#include "Card.hpp"
#include <iostream>    
       template <typename CardType>
Deck<CardType>::Deck() {
    // Dummy constructor
}

template <typename CardType>
Deck<CardType>::~Deck() {
    // Dummy destructor
}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card) {
    // Dummy implementation
}

template <typename CardType>
CardType&& Deck<CardType>::Draw() {
    // Dummy implementation, returning a default-constructed CardType
    return CardType();
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const {
    // Dummy implementation, always returning true
    return true;
}

template <typename CardType>
void Deck<CardType>::Shuffle() {
    // Dummy implementation, no actual shuffling
}

template <typename CardType>
int Deck<CardType>::getSize() const {
    // Dummy implementation, always returning 0
    return 0;
}

template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const {
    // Dummy implementation, returning an empty vector
    return std::vector<CardType>();
}
