#include "Hand.hpp"
#include <string>
#include <algorithm>

Hand::Hand() : cards_(){}
Hand::~Hand()
{
    cards_.clear();
}

Hand::Hand(const Hand &other) : cards_(other.cards_){}

Hand &Hand::operator=(const Hand &other){
    if(this != &other)
        cards_ = other.cards_;
    return *this;
}

Hand::Hand(Hand &&other) : cards_(std::move(other.cards_)){}

Hand &Hand::operator=(Hand &&other)
{
    if(this != & other){
        cards_ = std::move(other.cards_);}
    return *this;
}
const std::deque<PointCard> &Hand::getCards() const
{
    return cards_;
}

void Hand::addCard(PointCard &&card)
{
    card.setDrawn(true);
    cards_.push_back(card);
}

bool Hand::isEmpty() const
{
    return cards_.empty();
}

void Hand::Reverse()
{
    std::reverse(cards_.begin(), cards_.end());
}

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