#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include "Card.hpp"
#include <random>

template <typename CardType>
class Deck {
public:
    Deck() {
        cards_.clear();
    }

    ~Deck() {
    }

    void AddCard(const CardType& card) {
        cards_.push_back(card);
    }

    CardType&& Draw() {
        if (cards_.empty()) {
            throw std::runtime_error("Deck is empty. Cannot draw a card.");
        }

        CardType drawnCard = std::move(cards_.back());
        cards_.pop_back();

        return std::move(drawnCard);
    }

    bool IsEmpty() const {
        return cards_.empty();
    }

    void Shuffle() {
        std::mt19937 rng(2028358904);
        std::shuffle(cards_.begin(), cards_.end(), rng);
    }

    int getSize() const {
        return static_cast<int>(cards_.size());
    }

    std::vector<CardType> getDeck() const {
        return cards_;
    }

private:
    std::vector<CardType> cards_;
};

#endif
