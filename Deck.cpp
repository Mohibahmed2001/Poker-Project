#include "Deck.hpp"
#include <algorithm>
#include "Card.hpp"

 /**
         * @post: Construct a new Deck object
         */
template <typename CardType>
Deck<CardType>::Deck() : cards_() {

}
/**
         * @post: Destroy the Deck object 
         */
template <typename CardType>
Deck<CardType>::~Deck(){
    cards_.~vector();
}
 /**
         * @post: Add a Card to the Deck
         * @param: const reference to CardType card
         */
template <typename CardType>
void Deck<CardType>::AddCard(const CardType &card)
{
    cards_.push_back(card);
    
}

/**
         * @post: Draw a card from the deck
         * @pre: the deck is not empty
         * @return the right hand value of type CardType 
         */
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
/**
         * @return if the deck is empty 
         */
template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
    return cards_.empty();
}
/**
         * @post: Shuffle the deck 
         * Create a random number generator using std::mt19937 with seed 2028358904, 
         * then call std::shuffle on the vector of cards, and with the random number generator as the third argument.  
         * https://en.cppreference.com/w/cpp/algorithm/random_shuffle
         * https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
         */
template <typename CardType>
void Deck<CardType>::Shuffle()
{
    std::mt19937 mt1(2028358904); //given seed
    std::shuffle(cards_.begin(), cards_.end(),mt1);
}
/**
         * @return the size of the deck 
         */
template <typename CardType>
int Deck<CardType>::getSize() const
{
    return (int) cards_.size();
}
  /**
         * @return the vector of cards in the deck 
         */
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
    return cards_;
}

