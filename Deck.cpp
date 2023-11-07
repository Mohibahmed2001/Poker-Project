#include "Deck.hpp"

// Constructor
template<typename CardType>
Deck<CardType>::Deck() {
    
}

// Destructor
template<typename CardType>
Deck<CardType>::~Deck() {
    
}

// AddCard
template<typename CardType>
void Deck<CardType>::AddCard(const CardType& card) {
    cards_.push_back(card);
}

// Draw
template<typename CardType>
CardType Deck<CardType>::Draw() {
    if (IsEmpty()) {
        throw std::runtime_error("Cannot draw from an empty deck.");
    }
    CardType card = std::move(cards_.back());
    cards_.pop_back();
    return card;
}

// Check if the Deck is Empty
template <typename CardType>
bool Deck<CardType>::IsEmpty() const {
    return cards_.empty();
}

// Shuffle the Deck
template <typename CardType>
void Deck<CardType>::Shuffle() {
    std::mt19937 generator(2028358904); 
    std::shuffle(cards_.begin(), cards_.end(), generator);
}

// Get the Size of the Deck
template <typename CardType>
int Deck<CardType>::getSize() const {
    return cards_.size();
}

// Get the Deck of Cards
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const {
    return cards_;
}
template class Deck<PointCard>;
template class Deck<ActionCard>;
