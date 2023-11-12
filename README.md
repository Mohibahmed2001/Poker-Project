# Card-Game
Assigment 1

1 The Card Game
Definitions:
Players contain a hand of cards, and pointers to their opponent, a Point Deck, and an Action Deck.
Decks only hold either Point Cards and Action Cards.
A Hand belonging to a player only contains point cards, and must maintain an order so that cards
drawn first are scored first. The only way for a Player to add a Point card to their hand is through an
Action Card instruction.
Point Cards should contain only a whole number : This is the number of points scored when a
Player plays a Point Card from their hand. The only way for a Player to play a card from their hand
is through an Action Card Instruction.
Action Cards contain instructions in one following forms, where x is a positive integer
DRAW x CARD(S)
PLAY x CARD(S)
REVERSE HAND
SWAP HAND WITH OPPONEN
