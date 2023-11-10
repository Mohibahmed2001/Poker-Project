#include "Deck.hpp"
#include <algorithm>
#include "Card.hpp"

template <typename CardType>
Deck<CardType>::Deck() : cards_() {

}

template <typename CardType>
Deck<CardType>::~Deck(){

}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType &card)
{   
    
    cards_.push_back(card);
}

template <typename CardType>
CardType &&Deck<CardType>::Draw()
{
    if(!IsEmpty()){
        CardType&& card = std::move(cards_.back());
        cards_.pop_back();
        return std::move(card);
    } else{
        throw std::out_of_range("NO CARDS IN DECK");
    }
    
   
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
    return cards_.empty();
}

template <typename CardType>
void Deck<CardType>::Shuffle()
{
    std::mt19937 mt1(2028358904);
    std::shuffle(cards_.begin(), cards_.end(),mt1);
}

template <typename CardType>
int Deck<CardType>::getSize() const
{
    return (int) cards_.size();
}

template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
    return cards_;
}