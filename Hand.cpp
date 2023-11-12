#include "Hand.hpp"
#include <string>
#include <algorithm>
 /**
         * Copy Constructor
         * @param: other Hand object
         */
Hand::Hand() : cards_()
{

}
 /**
         * @post: Destroy the Hand object
         */
Hand::~Hand()
{
    cards_.~deque();
}
/**
         * Copy Assignment Operator
         * @param: other Hand object
         * @return this Hand 
         */
Hand::Hand(const Hand &other) : cards_(other.cards_)
{

}
/**
         * Move Constructor
         * @param: other Hand object
         */
Hand &Hand::operator=(const Hand &other)
{
    if(this != &other)
        cards_ = other.cards_;
    return *this;
}
  /**
         * Copy Assignment Operator
         * @param: other Hand object
         * @return this Hand 
         */
Hand::Hand(Hand &&other) : cards_(std::move(other.cards_))
{
    
}
 /**
         * Move assignment operator
         * @param: other Hand object
         * @return this Hand
         */
Hand &Hand::operator=(Hand &&other)
{
    if(this != & other){
        cards_ = std::move(other.cards_);
    }
    return *this;
}
 /**
         * @return Hand
         */
const std::deque<PointCard> &Hand::getCards() const
{
    return cards_;
}
  /**
         * @post: Add a card to the hand
         * @param PointCard object
         */
void Hand::addCard(PointCard &&card)
{
    card.setDrawn(true); 
    cards_.push_back(card);
}

        /**
         * @return true if hand is empty, false otherwise
         */
bool Hand::isEmpty() const
{
    return cards_.empty();
}
  /**
         * @post: Reverse the hand
         */
void Hand::Reverse()
{
    std::reverse(cards_.begin(), cards_.end());
}
  /**
         * @post: Play the card at the front of the hand, removing it from the hand
         * Throws an exception if the hand is empty or the card is not playable
         * If the card is not playable, the card is removed from the hand
         * @return the points earned from playing the card
         */
int Hand::PlayCard()
{
    if(isEmpty()){
        throw std::exception(); 
    }
    PointCard card = cards_.front(); 
    if(!card.isPlayable()){ 
        cards_.pop_front(); 
        throw std::exception();
    }
    int ret = std::stoi(card.getInstruction()); 
    cards_.pop_front();
    return ret; 
}
