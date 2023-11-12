#include "Deck.hpp"
#include <algorithm>
#include "Card.hpp"


//Zero Parameter Constructor
template <typename CardType>
Deck<CardType>::Deck() : cards_() {

}



//Object Destructor
template <typename CardType>
Deck<CardType>::~Deck(){
    cards_.~vector();
}

//Adds a card to the Deck
template <typename CardType>
void Deck<CardType>::AddCard(const CardType &card)
{
    cards_.push_back(card);
    
}

//Draws a card from the deck 
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

//Returns true if the deck is empty 
template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
    return cards_.empty();
}


//Shuffles the deck with the given seed 
template <typename CardType>
void Deck<CardType>::Shuffle()
{
    std::mt19937 mt1(2028358904); //given seed
    std::shuffle(cards_.begin(), cards_.end(),mt1);
}


//Returns the size of the deck as an int
template <typename CardType>
int Deck<CardType>::getSize() const
{
    return (int) cards_.size();
}


//returns the Deck as a vector<CardType>
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
    return cards_;
}

